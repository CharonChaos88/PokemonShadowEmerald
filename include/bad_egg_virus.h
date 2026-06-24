#ifndef GUARD_BAD_EGG_VIRUS_H
#define GUARD_BAD_EGG_VIRUS_H

#include "global.h"
#include "pokemon.h"
#include "constants/pokemon.h"

// --- 8-BIT VIRUS MEMORY MASKS ---
// These map to the dedicated MON_DATA_BAD_EGG_VIRUS byte
#define BEV_STRAIN_MASK 0x03 // Bits 0-1 (0=Clean, 1=X, 2=Y, 3=Z)
#define BEV_STAGE_MASK  0x1C // Bits 2-4 (Stages 0-7)
#define BEV_ANTIBODY_X  0x20 // Bit 5
#define BEV_ANTIBODY_Y  0x40 // Bit 6
#define BEV_ANTIBODY_Z  0x80 // Bit 7

// --- STRAIN DEFINITIONS ---
#define STRAIN_NONE 0
#define STRAIN_X    1
#define STRAIN_Y    2
#define STRAIN_Z    3

#ifndef GUARD_CONSTANTS_BAD_EGG_VIRUS_H
#define GUARD_CONSTANTS_BAD_EGG_VIRUS_H

// Defining the state constants
#define NORMAL                      (0)
#define INFECTED                    (1 << 0) 
#define PURIFIED_VARIANT_CHARONIAN  (1 << 1)

#endif

// --- COUNTER INDICES ---
#define VIRUS_COUNTER_STEPS   0
#define VIRUS_COUNTER_BATTLES 1
#define VIRUS_COUNTER_TIME    2

// Functions to expose to Poryscript
void PerformCocoonRitual(void);
bool8 ApplyCasilcoonVaccine(struct Pokemon *mon);
bool8 ApplyButterdrillVaccine(struct Pokemon *mon);
bool8 ApplyDustoxiflyVaccine(struct Pokemon *mon);

// EWRAM array to track partial stage progress for the active party.
// Wiped to 0 when deposited in the PC to simulate "Quarantine Stasis".


// --- FUNCTION DECLARATIONS ---
bool8 IsMonInfected(struct Pokemon *mon);
u8 GetVirusStrain(struct Pokemon *mon);
u8 GetVirusStage(struct Pokemon *mon);
void SetVirusStage(struct Pokemon *mon, u8 stage);
u8 const *GetStrainNameString(u8 strain);

void InfectMonWithVirus(struct Pokemon *mon, u8 strain, u8 stage);
void TryMutatePokerus(struct Pokemon *mon);
void WipeVirusCounters(struct Pokemon *mon);


void IncrementVirusSteps(void);
void IncrementVirusBattles(void);
void IncrementVirusTime(void);

u8 GetVirusProgressionPercentage(struct Pokemon *mon, u8 strain, u8 stage);

// Native functions called by the Event Script
void ApplyBadEggVirusBattleEffects(u8 battlerId);
void ConvertMonToBadEgg(void);
void PartySpreadBadEggVirus(void);
void InfectStarterWithVirus(void);
void TryInfectStarterWithVirus(void);
bool8 TryTriggerPendingVirusAlerts(void);
void QueueVirusAlert(struct Pokemon *mon, u8 strain, u8 reason);
void TryInfectWildMon(struct Pokemon *mon);

#endif // GUARD_BAD_EGG_VIRUS_H