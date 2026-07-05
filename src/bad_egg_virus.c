#include "global.h"
#include "pokemon.h"
#include "bad_egg_virus.h"
#include "event_data.h"
#include "script.h"
#include "string_util.h"
#include "random.h"
#include "item.h"
#include "constants/flags.h"
#include "constants/species.h"
#include "battle_main.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_util.h"
#include "party_menu.h"
#include "constants/party_menu.h"
#include "pokemon_storage_system.h"
#include "chooseboxmon.h"

// EWRAM Allocation
#define gGlobalPcVirusClock  (gSaveBlock1Ptr->globalPcVirusClock)
#define gBevTrackers         (gSaveBlock1Ptr->bevTrackers)

EWRAM_DATA u8 gPendingAlert_PartyIndex[PARTY_SIZE] = {0};
EWRAM_DATA u8 gPendingAlert_Strain[PARTY_SIZE] = {0};
EWRAM_DATA u8 gPendingAlert_Reason[PARTY_SIZE] = {0}; 
EWRAM_DATA u8 gPendingAlert_Stage[PARTY_SIZE] = {0};
EWRAM_DATA u8 gNumPendingAlerts = 0;

// Script References
extern const u8 EventScript_BadEggVirusAlert[];
extern const u8 EventScript_CheckStarterVirus[];
extern const u8 EventScript_VirusRitual[];
extern const u8 EventScript_RitualCancelled[];

// --- THRESHOLD CONSTANTS ---
static const u16 sStrainMaxSteps[4]   = {0, 5120, 2560, 1280};
static const u16 sStrainMaxBattles[4] = {0, 30,   15,   5};
static const u16 sStrainMaxTime[4]    = {0, 240,  120,  60};
static const u8 sStrainMaxStages[4]   = {0, 5, 4, 3};

static const u8 sText_StrainX[] = _("X");
static const u8 sText_StrainY[] = _("Y");
static const u8 sText_StrainZ[] = _("Z");
static const u8 sText_StrainUnknown[] = _("?");

static u8 sVirusCooldown[MAX_BATTLERS_COUNT];
static bool8 sWasConfused[MAX_BATTLERS_COUNT];
static u8 sLastPartyIndex[MAX_BATTLERS_COUNT];
static bool8 sProcessedFaint[MAX_BATTLERS_COUNT];

static struct BevTracker* FindTrackerByPersonality(u32 personality)
{
    int i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gBevTrackers[i].personality == personality)
            return &gBevTrackers[i];
    }
    return NULL;
}

static struct BevTracker* GetTrackerForMon(struct Pokemon *mon)
{
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    int i, j;
    
    // 1. Try to find the existing tracker for this Pokemon
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gBevTrackers[i].personality == personality)
            return &gBevTrackers[i];
    }
    
    // 2. Not found! Find an empty slot (or overwrite a Pokemon that was deposited in the PC)
    for (i = 0; i < PARTY_SIZE; i++)
    {
        bool32 slotInUse = FALSE;
        for (j = 0; j < gPartiesCount[B_TRAINER_PLAYER]; j++)
        {
            if (gBevTrackers[i].personality == GetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_PERSONALITY))
            {
                slotInUse = TRUE;
                break;
            }
        }
        
        if (!slotInUse)
        {
            gBevTrackers[i].personality = personality;
            gBevTrackers[i].steps = 0;
            gBevTrackers[i].battles = 0;
            gBevTrackers[i].time = 0;
            return &gBevTrackers[i];
        }
    }
    return &gBevTrackers[0]; // Fallback
}

// --- CORE UTILITIES ---

bool8 IsMonInfected(struct Pokemon *mon)
{
    return GetVirusStrain(mon) != 0;
}

u8 GetVirusStrain(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_BAD_EGG_VIRUS) & BEV_STRAIN_MASK;
}

u8 GetVirusStage(struct Pokemon *mon)
{
    return (GetMonData(mon, MON_DATA_BAD_EGG_VIRUS) & BEV_STAGE_MASK) >> 2;
}

void SetVirusStage(struct Pokemon *mon, u8 stage)
{
    u8 bevData = GetMonData(mon, MON_DATA_BAD_EGG_VIRUS);
    bevData &= ~BEV_STAGE_MASK;
    bevData |= ((stage << 2) & BEV_STAGE_MASK);
    SetMonData(mon, MON_DATA_BAD_EGG_VIRUS, &bevData);
}

u8 const *GetStrainNameString(u8 strain)
{
    switch (strain)
    {
        case STRAIN_X: return sText_StrainX;
        case STRAIN_Y: return sText_StrainY;
        case STRAIN_Z: return sText_StrainZ;
        default:       return sText_StrainUnknown;
    }
}

// --- INFECTION & SPREAD ---

void InfectMonWithVirus(struct Pokemon *mon, u8 strain, u8 stage)
{   
    u8 bevData = GetMonData(mon, MON_DATA_BAD_EGG_VIRUS);
    u8 oldStrain = bevData & BEV_STRAIN_MASK;
    u8 allAntibodies = BEV_ANTIBODY_X | BEV_ANTIBODY_Y | BEV_ANTIBODY_Z;

    // 1. TOTAL IMMUNITY CHECK (If they have all 3, they are permanently safe!)
    if ((bevData & allAntibodies) == allAntibodies) return;

    // 2. DON'T OVERWRITE ACTIVE INFECTIONS
    if (oldStrain != 0 && oldStrain != strain) return;

    // 3. ANTIBODY-BASED MUTATION THREAT
    if (oldStrain == 0) // New infection only
    {
        if (bevData & BEV_ANTIBODY_Y)
        {
            if (strain < STRAIN_Z && (Random() % 100) < 80) strain = STRAIN_Z; 
        }
        else if (bevData & BEV_ANTIBODY_X)
        {
            if (strain < STRAIN_Y && (Random() % 100) < 80) strain = STRAIN_Y; 
        }
    }

    // 4. INDIVIDUAL IMMUNITY CHECK (Done AFTER mutation to check the final strain)
    if (strain == STRAIN_X && (bevData & BEV_ANTIBODY_X)) return;
    if (strain == STRAIN_Y && (bevData & BEV_ANTIBODY_Y)) return;
    if (strain == STRAIN_Z && (bevData & BEV_ANTIBODY_Z)) return;

    if (oldStrain == 0 && (strain == STRAIN_Y || strain == STRAIN_Z) && stage < 2)
        stage = 2;

    // 5. APPLY INFECTION (Preserving Antibodies)
    bevData &= ~(BEV_STRAIN_MASK | BEV_STAGE_MASK); 
    bevData |= (strain & BEV_STRAIN_MASK);
    bevData |= ((stage << 2) & BEV_STAGE_MASK);
    SetMonData(mon, MON_DATA_BAD_EGG_VIRUS, &bevData);
    
    CalculateMonStats(mon);
   
    // 6. ALERT (Only queue if it belongs to the player and wasn't infected before)
    if (oldStrain == STRAIN_NONE)
    {
        if (mon >= gParties[B_TRAINER_PLAYER] && mon < &gParties[B_TRAINER_PLAYER][PARTY_SIZE])
            QueueVirusAlert(mon, strain, 1); // 1 = Caught BEV
    }
}

static u8 GetNumBadges(void)
{
    u8 badges = 0;
    if (FlagGet(FLAG_BADGE01_GET)) badges++;
    if (FlagGet(FLAG_BADGE02_GET)) badges++;
    if (FlagGet(FLAG_BADGE03_GET)) badges++;
    if (FlagGet(FLAG_BADGE04_GET)) badges++;
    if (FlagGet(FLAG_BADGE05_GET)) badges++;
    if (FlagGet(FLAG_BADGE06_GET)) badges++;
    if (FlagGet(FLAG_BADGE07_GET)) badges++;
    if (FlagGet(FLAG_BADGE08_GET)) badges++;
    return badges;
}

void TryMutatePokerus(struct Pokemon *mon)
{
    u8 badges = GetNumBadges();
    u8 mutationChance = 30 + (badges * 5);

    if ((Random() % 100) < mutationChance)
    {
        u8 strainRoll = Random() % 100;
        u8 assignedStrain = STRAIN_X;

        if (strainRoll < 5) assignedStrain = STRAIN_Z;
        else if (strainRoll < 30) assignedStrain = STRAIN_Y;

        InfectMonWithVirus(mon, assignedStrain, 1);
    }
}

// --- UI DATA CALCULATOR ---

void WipeVirusCounters(struct Pokemon *mon)
{
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    struct BevTracker *tracker = FindTrackerByPersonality(personality);
    if (tracker != NULL)
    {
        tracker->steps = 0;
        tracker->battles = 0;
        tracker->time = 0;
    }
}

u8 GetVirusProgressionPercentage(struct Pokemon *mon, u8 strain, u8 stage)
{
    if (strain == STRAIN_NONE || strain > STRAIN_Z) return 0;

    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    struct BevTracker *tracker = FindTrackerByPersonality(personality);
    
    // If they are in the PC and their tracker was overwritten, they are frozen at 0%
    if (tracker == NULL) return 0; 

    u16 currentSteps = tracker->steps;
    u16 currentBattles = tracker->battles;
    u16 currentTime = tracker->time;

    u16 maxSteps = sStrainMaxSteps[strain];
    u16 maxBattles = sStrainMaxBattles[strain];
    u16 maxTime = sStrainMaxTime[strain];

    u8 pctSteps = (currentSteps * 100) / maxSteps;
    u8 pctBattles = (currentBattles * 100) / maxBattles;
    u8 pctTime = (currentTime * 100) / maxTime;

    u8 highestPct = pctSteps;
    if (pctBattles > highestPct) highestPct = pctBattles;
    if (pctTime > highestPct) highestPct = pctTime;

    return (highestPct > 99) ? 99 : highestPct;
}

// --- BACKGROUND COUNTER UPDATES & ALERT TRIGGERING ---

static void CheckAndTriggerVirusStage(struct Pokemon *mon)
{
    u8 strain = GetVirusStrain(mon);
    u8 stage = GetVirusStage(mon);

    if (strain == STRAIN_NONE || stage >= sStrainMaxStages[strain])
        return;

    bool8 thresholdMet = FALSE;
    struct BevTracker *tracker = GetTrackerForMon(mon);

    if (tracker->steps >= sStrainMaxSteps[strain]) thresholdMet = TRUE;
    if (tracker->battles >= sStrainMaxBattles[strain]) thresholdMet = TRUE;
    if (tracker->time >= sStrainMaxTime[strain]) thresholdMet = TRUE;

    if (thresholdMet)
    {
        stage++;
        InfectMonWithVirus(mon, strain, stage);
        WipeVirusCounters(mon);
        CalculateMonStats(mon);

        // Safely push to the Alert Queue. Do NOT force the script here!
        QueueVirusAlert(mon, strain, 0); 
    }
}

void IncrementVirusSteps(void)
{
    int i;
    for (i = 0; i < gPartiesCount[B_TRAINER_PLAYER]; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        u8 vanillaPokerus = GetMonData(mon, MON_DATA_POKERUS);

        if (vanillaPokerus != 0 && (vanillaPokerus & 0x0F) != 0 && !IsMonInfected(mon))
            InfectMonWithVirus(mon, STRAIN_X, 1); 

        if (IsMonInfected(mon))
        {
            struct BevTracker *tracker = GetTrackerForMon(mon);
            tracker->steps++;
            CheckAndTriggerVirusStage(mon);
        }
    }
}

void IncrementVirusBattles(void)
{
    int i;
    bool8 enemyInfected = IsMonInfected(&gParties[B_TRAINER_OPPONENT_A][0]);
    u8 enemyStrain = enemyInfected ? GetVirusStrain(&gParties[B_TRAINER_OPPONENT_A][0]) : STRAIN_NONE;

    for (i = 0; i < gPartiesCount[B_TRAINER_PLAYER]; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        
        if (enemyInfected && !GetMonData(mon, MON_DATA_IS_EGG) && !IsMonInfected(mon))
        {
            if ((Random() % 100) < 10) 
                InfectMonWithVirus(mon, enemyStrain, 1);
        }

        u8 vanillaPokerus = GetMonData(mon, MON_DATA_POKERUS);
        if (vanillaPokerus != 0 && (vanillaPokerus & 0x0F) != 0 && !IsMonInfected(mon))
            InfectMonWithVirus(mon, STRAIN_X, 1); 

        if (IsMonInfected(mon))
        {
            struct BevTracker *tracker = GetTrackerForMon(mon);
            tracker->battles++;
            CheckAndTriggerVirusStage(mon); 
        }
    }
}

void IncrementVirusTime(void)
{
    int i;
    
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        if (IsMonInfected(mon))
        {
            struct BevTracker *tracker = GetTrackerForMon(mon);
            tracker->time++;
            CheckAndTriggerVirusStage(mon);
        }
    }
}

// --- SCRIPT NATIVE CALLBACKS ---

void ApplyBadEggVirusStageEffects(void)
{
}

void ConvertMonToBadEgg(void)
{
    u8 partyIndex = VarGet(VAR_TEMP_1);
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];
    u8 isEgg = TRUE;
    u8 isBadEgg = TRUE;
    
    SetMonData(mon, MON_DATA_IS_EGG, &isEgg);
    SetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG, &isBadEgg);
    CalculateMonStats(mon);
}

void ApplyBadEggVirusBattleEffects(u8 battlerId)
{
    struct Pokemon *mon;
    u8 partyIndex;
    u8 strain;
    u8 stage;

    if (gBattleResults.battleTurnCounter == 0)
    {
        sVirusCooldown[battlerId] = 0;
        sWasConfused[battlerId] = FALSE;
        sLastPartyIndex[battlerId] = 0xFF;
        sProcessedFaint[battlerId] = FALSE; // Reset faint tracker for new battles
    }

    // 1. Immediately ignore opponents so we don't waste processing power
    if (!IsOnPlayerSide(battlerId)) return;

    // 2. Grab the TRUE party data, not the volatile battle memory
    partyIndex = gBattlerPartyIndexes[battlerId]; 
    if (partyIndex >= PARTY_SIZE) return;
    mon = &gParties[B_TRAINER_PLAYER][partyIndex];

    // 3. Prevent checking empty slots or eggs
    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE || GetMonData(mon, MON_DATA_IS_EGG)) 
        return;

    // --- FAINTING IMMUNITY LOSS CHECK ---
    // Look directly at the Pokémon's permanent HP in memory so the engine's cleanup step doesn't trick us!
    if (GetMonData(mon, MON_DATA_HP) == 0)
    {
        if (!sProcessedFaint[battlerId])
        {
            sProcessedFaint[battlerId] = TRUE; // Mark as processed so it only rolls once!
            u8 bevData = GetMonData(mon, MON_DATA_BAD_EGG_VIRUS);

            if (bevData & (BEV_ANTIBODY_X | BEV_ANTIBODY_Y | BEV_ANTIBODY_Z))
            {
                if ((Random() % 100) < 5) // 5% chance to lose immunity!
                {
                    bevData &= ~(BEV_ANTIBODY_X | BEV_ANTIBODY_Y | BEV_ANTIBODY_Z);
                    SetMonData(mon, MON_DATA_BAD_EGG_VIRUS, &bevData);
                    
                    // Queue a special alert (Reason 3 = Lost Immunity)
                    QueueVirusAlert(mon, STRAIN_NONE, 3); 
                }
            }
        }
        return; // Always return if HP is 0
    }
    else
    {
        sProcessedFaint[battlerId] = FALSE; // Reset this if the Pokemon is Revived during battle!
    }

    if (sLastPartyIndex[battlerId] != partyIndex)
    {
        sVirusCooldown[battlerId] = 0;
        sWasConfused[battlerId] = FALSE;
        sLastPartyIndex[battlerId] = partyIndex;
    }

    strain = GetVirusStrain(mon);
    stage = GetVirusStage(mon);

    if (strain == STRAIN_NONE || stage == 0) return;

    if (strain == STRAIN_Y)
    {
        if (gBattleMons[battlerId].volatiles.confusionTurns > 0)
        {
            sWasConfused[battlerId] = TRUE;
            sVirusCooldown[battlerId] = 0;
        }
        else
        {
            if (sWasConfused[battlerId] == TRUE)
            {
                sVirusCooldown[battlerId] = (Random() % 2 + 2);
                sWasConfused[battlerId] = FALSE;
            }
            if (sVirusCooldown[battlerId] > 0)
                sVirusCooldown[battlerId]--;
            
            if (sVirusCooldown[battlerId] == 0)
            {
                if ((Random() % 100) < 30)
                {
                    gBattleMons[battlerId].volatiles.confusionTurns = (Random() % 4 + 2);
                    sWasConfused[battlerId] = TRUE;
                }
            }
        }
    }

    if (strain == STRAIN_Z)
    {
        if (gBattleMons[battlerId].volatiles.confusionTurns > 0)
        {
            sWasConfused[battlerId] = TRUE;
            sVirusCooldown[battlerId] = 0;
            gBattleMons[battlerId].volatiles.confusionTurns = 5;

            if (gBattleMons[battlerId].statStages[STAT_ACC] > 0)
                gBattleMons[battlerId].statStages[STAT_ACC]--;
            if (gBattleMons[battlerId].statStages[STAT_EVASION] > 0)
                gBattleMons[battlerId].statStages[STAT_EVASION]--;
        }
        else
        {
            if (sWasConfused[battlerId] == TRUE)
            {
                sVirusCooldown[battlerId] = 3;
                sWasConfused[battlerId] = FALSE;
            }
            if (sVirusCooldown[battlerId] > 0)
                sVirusCooldown[battlerId]--;
            
            if (sVirusCooldown[battlerId] == 0)
            {
                gBattleMons[battlerId].volatiles.confusionTurns = 5;
                sWasConfused[battlerId] = TRUE;
            }
        }
    }
}

void PartySpreadBadEggVirus(void)
{
    u8 i;
    bool8 virusSpreadThisBattle = FALSE;

    for (i = 0; i < gPartiesCount[B_TRAINER_PLAYER]; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];

        if (!GetMonData(mon, MON_DATA_SPECIES) || GetMonData(mon, MON_DATA_IS_EGG))
            continue;

        if (IsMonInfected(mon))
        {
            u8 currentStrain = GetVirusStrain(mon);

            if (!virusSpreadThisBattle && (Random() % 100) < 30)
            {
                u8 spreadStrain = currentStrain;

                if (currentStrain == STRAIN_Z)
                    spreadStrain = (Random() % 2 == 0) ? STRAIN_X : STRAIN_Y;

                if (i > 0)
                {
                    struct Pokemon *targetUp = &gParties[B_TRAINER_PLAYER][i - 1];
                    if (GetMonData(targetUp, MON_DATA_SPECIES) && !GetMonData(targetUp, MON_DATA_IS_EGG) && !IsMonInfected(targetUp))
                    {
                        InfectMonWithVirus(targetUp, spreadStrain, 1);
                        virusSpreadThisBattle = TRUE;
                    }
                }

                if (i < gPartiesCount[B_TRAINER_PLAYER] - 1)
                {
                    struct Pokemon *targetDown = &gParties[B_TRAINER_PLAYER][i + 1];
                    if (GetMonData(targetDown, MON_DATA_SPECIES) && !GetMonData(targetDown, MON_DATA_IS_EGG) && !IsMonInfected(targetDown))
                    {
                        InfectMonWithVirus(targetDown, spreadStrain, 1);
                        virusSpreadThisBattle = TRUE;
                        i++; 
                    }
                }
            }
        }
    }
}

void InfectStarterWithVirus(void)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][0];
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG))
    {
        InfectMonWithVirus(mon, STRAIN_X, 1);
        CalculateMonStats(mon); 
    }
}

void TryInfectStarterWithVirus(void)
{
    if ((Random() % 100) < 15)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][0];
        if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG))
        {
            InfectMonWithVirus(mon, STRAIN_X, 1);
            CalculateMonStats(mon); 
        }
    }
}

void TryInfectWildMon(struct Pokemon *mon)
{
    if ((Random() % 100) < 5) 
    {
        u8 strainRoll = Random() % 100;
        u8 assignedStrain = STRAIN_X;

        if (strainRoll < 5) assignedStrain = STRAIN_Z;
        else if (strainRoll < 30) assignedStrain = STRAIN_Y;

        InfectMonWithVirus(mon, assignedStrain, 1);
    }
}

// --- CASILCOON VACCINE ---
bool8 ApplyCasilcoonVaccine(struct Pokemon *mon)
{
    u8 bevData = GetMonData(mon, MON_DATA_BAD_EGG_VIRUS);
    u8 currentStrain = bevData & BEV_STRAIN_MASK;
    bool8 applied = FALSE;
    bool8 cured = FALSE;

    if (currentStrain == STRAIN_X)
    {
        bevData &= ~(BEV_STRAIN_MASK | BEV_STAGE_MASK); 
        cured = TRUE;
        applied = TRUE;
    }

    if (!(bevData & BEV_ANTIBODY_X))
    {
        bevData |= BEV_ANTIBODY_X;
        applied = TRUE;
    }

    if (!applied)
        return FALSE;
    
    SetMonData(mon, MON_DATA_BAD_EGG_VIRUS, &bevData);

    if (cured)
    {
        u8 partyIndex = mon - gParties[B_TRAINER_PLAYER];
        if (partyIndex < PARTY_SIZE)
            WipeVirusCounters(mon);
    }
        
    CalculateMonStats(mon); 
    return TRUE;
}

bool8 ApplyButterdrillVaccine(struct Pokemon *mon)
{
    u8 bevData = GetMonData(mon, MON_DATA_BAD_EGG_VIRUS);
    u8 currentStrain = bevData & BEV_STRAIN_MASK;
    bool8 applied = FALSE;
    bool8 cured = FALSE;

    if (currentStrain == STRAIN_X || currentStrain == STRAIN_Y)
    {
        bevData &= ~(BEV_STRAIN_MASK | BEV_STAGE_MASK); 
        cured = TRUE;
        applied = TRUE;
    }

    if ((bevData & (BEV_ANTIBODY_X | BEV_ANTIBODY_Y)) != (BEV_ANTIBODY_X | BEV_ANTIBODY_Y))
    {
        bevData |= (BEV_ANTIBODY_X | BEV_ANTIBODY_Y);
        applied = TRUE;
    }

    if (!applied)
        return FALSE;
    
    SetMonData(mon, MON_DATA_BAD_EGG_VIRUS, &bevData);

    if (cured)
    {
        u8 partyIndex = mon - gParties[B_TRAINER_PLAYER];
        if (partyIndex < PARTY_SIZE)
            WipeVirusCounters(mon);
    }
        
    CalculateMonStats(mon); 
    return TRUE;
}

bool8 ApplyDustoxiflyVaccine(struct Pokemon *mon)
{
    u8 bevData = GetMonData(mon, MON_DATA_BAD_EGG_VIRUS);
    u8 currentStrain = bevData & BEV_STRAIN_MASK;
    bool8 applied = FALSE;
    bool8 cured = FALSE;

    if (currentStrain == STRAIN_X || currentStrain == STRAIN_Y || currentStrain == STRAIN_Z)
    {
        bevData &= ~(BEV_STRAIN_MASK | BEV_STAGE_MASK); 
        cured = TRUE;
        applied = TRUE;
    }

    if ((bevData & (BEV_ANTIBODY_X | BEV_ANTIBODY_Y | BEV_ANTIBODY_Z)) != (BEV_ANTIBODY_X | BEV_ANTIBODY_Y | BEV_ANTIBODY_Z))
    {
        bevData |= (BEV_ANTIBODY_X | BEV_ANTIBODY_Y | BEV_ANTIBODY_Z);
        applied = TRUE;
    }

    if (!applied)
        return FALSE;
    
    SetMonData(mon, MON_DATA_BAD_EGG_VIRUS, &bevData);

    if (cured)
    {
        u8 partyIndex = mon - gParties[B_TRAINER_PLAYER];
        if (partyIndex < PARTY_SIZE)
            WipeVirusCounters(mon);
    }
        
    CalculateMonStats(mon); 
    return TRUE;
}

// --- COCOON RITUAL ---
void PerformCocoonRitual(void)
{
    u8 sacrificeChoice = VarGet(VAR_0x8004);
    u16 sacrificeSpecies;
    u8 targetChoice = VarGet(VAR_0x8007);
    u8 targetPokerus;

    // BULLETPROOF CHECK: Any choice 6 or higher is guaranteed to be a PC selection!
    if (sacrificeChoice >= PARTY_SIZE)
        sacrificeSpecies = GetBoxMonData(GetBoxedMonPtr(VarGet(VAR_0x8005), VarGet(VAR_0x8006)), MON_DATA_SPECIES);
    else
        sacrificeSpecies = GetMonData(&gParties[B_TRAINER_PLAYER][sacrificeChoice], MON_DATA_SPECIES);

    if (targetChoice >= PARTY_SIZE)
        targetPokerus = GetBoxMonData(GetBoxedMonPtr(VarGet(VAR_0x8008), VarGet(VAR_0x8009)), MON_DATA_BAD_EGG_VIRUS);
    else
        targetPokerus = GetMonData(&gParties[B_TRAINER_PLAYER][targetChoice], MON_DATA_BAD_EGG_VIRUS);

    if ((sacrificeSpecies == SPECIES_CASCOON || sacrificeSpecies == SPECIES_SILCOON) && (targetPokerus & BEV_STRAIN_MASK) != 0)
    {
        targetPokerus &= ~BEV_STAGE_MASK;
        targetPokerus |= ((1 << 2) & BEV_STAGE_MASK); 

        if (targetChoice >= PARTY_SIZE)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(VarGet(VAR_0x8008), VarGet(VAR_0x8009));
            SetBoxMonData(boxMon, MON_DATA_BAD_EGG_VIRUS, &targetPokerus);
            
            u32 personality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY);
            struct BevTracker *tracker = FindTrackerByPersonality(personality);
            if (tracker != NULL)
            {
                tracker->steps = 0;
                tracker->battles = 0;
                tracker->time = 0;
            }
        }
        else
        {
            struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][targetChoice];
            SetMonData(mon, MON_DATA_BAD_EGG_VIRUS, &targetPokerus);
            WipeVirusCounters(mon); 
            CalculateMonStats(mon); 
        }

        if (sacrificeChoice >= PARTY_SIZE)
            ZeroBoxMonData(GetBoxedMonPtr(VarGet(VAR_0x8005), VarGet(VAR_0x8006)));
        else
            ZeroMonData(&gParties[B_TRAINER_PLAYER][sacrificeChoice]);

        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE; 
    }
}

void QueueVirusAlert(struct Pokemon *mon, u8 strain, u8 reason)
{
    if (gNumPendingAlerts >= PARTY_SIZE) return;

    gPendingAlert_PartyIndex[gNumPendingAlerts] = mon - gParties[B_TRAINER_PLAYER];
    gPendingAlert_Strain[gNumPendingAlerts] = strain;
    gPendingAlert_Reason[gNumPendingAlerts] = reason;
    gPendingAlert_Stage[gNumPendingAlerts] = GetVirusStage(mon);

    gNumPendingAlerts++;
}

bool8 TryTriggerPendingVirusAlerts(void)
{
    if (gNumPendingAlerts == 0)
        return FALSE;
        
    if (ScriptContext_IsEnabled())
        return FALSE; 

    u8 partyIndex = gPendingAlert_PartyIndex[0];
    u8 strain = gPendingAlert_Strain[0];
    u8 reason = gPendingAlert_Reason[0];
    u8 stage = gPendingAlert_Stage[0];

    u8 i;
    for (i = 0; i < gNumPendingAlerts - 1; i++)
    {
        gPendingAlert_PartyIndex[i] = gPendingAlert_PartyIndex[i + 1];
        gPendingAlert_Strain[i] = gPendingAlert_Strain[i + 1];
        gPendingAlert_Reason[i] = gPendingAlert_Reason[i + 1];
        gPendingAlert_Stage[i] = gPendingAlert_Stage[i + 1];
    }
    gNumPendingAlerts--;

    VarSet(VAR_TEMP_1, partyIndex);
    VarSet(VAR_TEMP_5, reason);

    if (reason == 0) // 0 = Stage Up
    {
        if (stage >= sStrainMaxStages[strain])
            VarSet(VAR_TEMP_4, TRUE);
        else
            VarSet(VAR_TEMP_4, FALSE);

        StringCopy(gStringVar2, GetStrainNameString(strain));
        ConvertIntToDecimalStringN(gStringVar3, stage, STR_CONV_MODE_LEFT_ALIGN, 1);
    }
    else if (reason == 1) // 1 = Caught BEV
    {
        if (strain == STRAIN_X) StringCopy(gStringVar2, sText_StrainX);
        else if (strain == STRAIN_Y) StringCopy(gStringVar2, sText_StrainY);
        else if (strain == STRAIN_Z) StringCopy(gStringVar2, sText_StrainZ);
    }

    ScriptContext_SetupScript(EventScript_BadEggVirusAlert);
    return TRUE;
}

void CheckPartyHasBevStrainX(void)
{
    u8 i;
    gSpecialVar_Result = FALSE;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SANITY_HAS_SPECIES) && !GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_IS_EGG))
        {
            if (GetVirusStrain(&gParties[B_TRAINER_PLAYER][i]) == STRAIN_X)
            {
                gSpecialVar_Result = TRUE;
                break;
            }
        }
    }
}


