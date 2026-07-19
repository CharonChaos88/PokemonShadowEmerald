#include "global.h"
#include "pokemon.h"
#include "multiboot.h"
#include "main.h"
#include "random.h"
#include "string_util.h"
#include "constants/region_map_sections.h"
#include "event_distribution.h"
#include "malloc.h"

// The compiled binary we generated! (You will link this in the Makefile)
extern const u8 gMultibootEventPayload[];
extern const u32 gMultibootEventPayloadSize;

const u8* gEventDistributionPayloadPtr = NULL;
u32 gEventDistributionPayloadSize = 0;

void DistributeEventPokemon(const struct EventPokemonTemplate* template) {
    struct Pokemon fullMon;
    struct BoxPokemon* eventMon = &fullMon.box;
    ZeroBoxMonData(eventMon);

    // 1. Generate Legal PID
    u32 pid = 0;
    u16 tid = template->otId & 0xFFFF;
    u16 sid = template->otId >> 16;
    do {
        pid = Random32();
        bool32 isShiny = ((tid ^ sid ^ (pid >> 16) ^ (pid & 0xFFFF)) < 8);
        
        if (template->isShiny != isShiny) continue;
        if (template->nature != 0xFF && (pid % 25) != template->nature) continue;
        
        break; // Found valid PID!
    } while (1);

    // 2. Create the Pokemon Structure
    CreateBoxMon(eventMon, template->species, template->level, pid, OTID_STRUCT_PRESET(template->otId));

    // 3. Apply Template Modifiers
    for (int i = 0; i < 4; i++) {
        SetBoxMonData(eventMon, MON_DATA_MOVE1 + i, &template->moves[i]);
    }

    SetBoxMonData(eventMon, MON_DATA_HELD_ITEM, &template->heldItem);
    SetBoxMonData(eventMon, MON_DATA_OT_NAME, template->otName);
    SetBoxMonData(eventMon, MON_DATA_OT_GENDER, &template->otGender);
    SetBoxMonData(eventMon, MON_DATA_POKEBALL, &template->pokeball);

    // Apply Fateful Encounter
    if (template->isFatefulEncounter) {
        u8 metLocation = METLOC_FATEFUL_ENCOUNTER;
        SetBoxMonData(eventMon, MON_DATA_MET_LOCATION, &metLocation);
        u32 modernFatefulEncounter = 1;
        SetBoxMonData(eventMon, MON_DATA_MODERN_FATEFUL_ENCOUNTER, &modernFatefulEncounter);
    }
    
    // 4. Recalculate Anti-Cheat Checksums
    u32 checksumCalc = 0;
    for (u32 i = 0; i < ARRAY_COUNT(eventMon->secure.raw); i++) {
        checksumCalc += eventMon->secure.raw[i] + (eventMon->secure.raw[i] >> 16);
    }
    u16 checksum = checksumCalc;
    SetBoxMonData(eventMon, MON_DATA_CHECKSUM, &checksum);

    // Calculate full battle stats!
    CalculateMonStats(&fullMon);

    // 5. Setup Multiboot Memory
    // The payload binary is in Read-Only Memory (ROM). 
    // We must copy it to RAM (WRAM) so we can patch the Event Pokemon into it.
    u32 totalPayloadSize = gMultibootEventPayloadSize;
    if (totalPayloadSize < 0x1000 + sizeof(struct Pokemon)) {
        totalPayloadSize = 0x1000 + sizeof(struct Pokemon);
    }
    
    u8* payloadRamCopy = AllocZeroed(totalPayloadSize);
    memcpy(payloadRamCopy, gMultibootEventPayload, gMultibootEventPayloadSize);

    // We calculate the offset inside the binary: 
    // Offset = 0x02001000 - 0x02000000 = 0x1000 (4096 bytes)
    struct Pokemon* injectionTarget = (struct Pokemon*)(payloadRamCopy + 0x1000);
    
    // Patch!
    *injectionTarget = fullMon;

    // 6. Broadcast the patched payload!
    gEventDistributionPayloadPtr = payloadRamCopy;
    gEventDistributionPayloadSize = totalPayloadSize;

    // Call the Official Connection UI!
    extern void CB2_InitBerryFixProgram(void);
    SetMainCallback2(CB2_InitBerryFixProgram);
}
