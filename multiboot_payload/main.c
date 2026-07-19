#include "global.h"
#include "save.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"

// GBA Display Macros
#define DISPCNT_MODE_3  0x0003
#define DISPCNT_BG2_ON  0x0400

void DrawScreenColor(unsigned short color) {
    for(int i = 0; i < 240 * 160; i++) {
        ((vu16 *)VRAM)[i] = color;
    }
}

void *memcpy(void *dest, const void *src, u32 n) {
    u8 *d = dest;
    const u8 *s = src;
    while (n--) *d++ = *s++;
    return dest;
}

// ----------------------------------------------------
// BARE-METAL FLASH DRIVER (128KB MACRONIX/SANYO)
// ----------------------------------------------------
#define FLASH_BASE ((vu8*)0x0E000000)
#define FLASH_WRITE(addr, data) (FLASH_BASE[addr] = (data))

void FlashSwitchBank(u8 bankNum) {
    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    FLASH_WRITE(0x5555, 0xB0);
    FLASH_WRITE(0x0000, bankNum);
}

void FlashEraseSector(u16 sectorNum) {
    FlashSwitchBank(sectorNum / 16);
    u16 bankSector = sectorNum % 16;
    
    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    FLASH_WRITE(0x5555, 0x80);
    FLASH_WRITE(0x5555, 0xAA);
    FLASH_WRITE(0x2AAA, 0x55);
    FLASH_WRITE(bankSector << 12, 0x30);
    
    while(FLASH_BASE[bankSector << 12] != 0xFF);
}

void FlashWriteSector(u16 sectorNum, u8* data) {
    FlashSwitchBank(sectorNum / 16);
    u16 bankSector = sectorNum % 16;
    
    for(int i = 0; i < 4096; i++) {
        FLASH_WRITE(0x5555, 0xAA);
        FLASH_WRITE(0x2AAA, 0x55);
        FLASH_WRITE(0x5555, 0xA0);
        FLASH_BASE[(bankSector << 12) + i] = data[i];
        
        while(FLASH_BASE[(bankSector << 12) + i] != data[i]);
    }
}

u16 CalculateChecksum(u8 *data, u16 size) {
    u16 i;
    u32 checksum = 0;
    u32 *data32 = (u32 *)data;

    for (i = 0; i < (size / 4); i++) {
        checksum += *data32++;
    }

    return ((checksum >> 16) + checksum);
}

// ----------------------------------------------------
// SAVE PARSING LOGIC
// ----------------------------------------------------

#define INJECT_PAYLOAD_ADDR 0x02001000

// Huge buffers allocated safely in BSS
struct SaveSector gSaveSectors[14];
u8 gPokemonStorageBuffer[SECTOR_DATA_SIZE * 9]; // 35712 bytes

#include "font.h"

void DrawChar(int x, int y, char c, u16 color, u16 bgcolor) {
    if (c < 0 || c >= 128) c = '?';
    char* bitmap = font8x8_basic[(int)c];
    u16* vram = (u16*)0x06000000;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (bitmap[row] & (1 << col)) {
                vram[(y + row) * 240 + (x + col)] = color;
            } else {
                vram[(y + row) * 240 + (x + col)] = bgcolor;
            }
        }
    }
}

void DrawString(int x, int y, const char* str, u16 color, u16 bgcolor) {
    while (*str) {
        DrawChar(x, y, *str, color, bgcolor);
        x += 8;
        if (x >= 240) {
            x = 0;
            y += 8;
        }
        str++;
    }
}

#define REG_KEYINPUT (*(volatile u16*)0x04000130)
#define KEY_A 1
#define KEY_B 2
#define KEY_UP 64
#define KEY_DOWN 128

    const u8 gEventMonData[108] __attribute__((section(".rodata"))) = {
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, // Magic Signature
        // 100 bytes will be patched by the Server here!
        0
    };

void PayloadMain(void) {
    // 1. Initialize Display
    REG_DISPCNT = DISPCNT_MODE_3 | DISPCNT_BG2_ON;
    DrawScreenColor(0x7C00); // Blue (Injecting...)
    
    const u8* eventMon = &gEventMonData[8];

    // 2. Find the active save slot
    u32 activeSlot = 0;
    u32 maxCounter = 0;
    bool32 foundSave = FALSE;
    u16 logicalToPhysical[14];

    for (int slot = 0; slot < 2; slot++) {
        u32 slotCounter = 0;
        bool32 slotValid = FALSE;

        for (int i = 0; i < 14; i++) {
            u16 physicalSector = (slot * 14) + i;
            FlashSwitchBank(physicalSector / 16);
            u16 bankSector = physicalSector % 16;
            
            u8* sectorAddr = (u8*)(FLASH_BASE + (bankSector << 12));
            u32 signature = *(u32*)(sectorAddr + SECTOR_SIGNATURE_OFFSET);
            
            if (signature == SECTOR_SIGNATURE) {
                slotValid = TRUE;
                u32 counter = *(u32*)(sectorAddr + SECTOR_COUNTER_OFFSET);
                if (counter > slotCounter) {
                    slotCounter = counter;
                }
            }
        }
        
        if (slotValid && slotCounter >= maxCounter) {
            maxCounter = slotCounter;
            activeSlot = slot;
            foundSave = TRUE;
        }
    }

    if (!foundSave) {
        DrawScreenColor(0x001F); // Red (Save Corrupted or Missing)
        while(1);
    }

    // Map physical sectors
    for (int i = 0; i < 14; i++) {
        u16 physicalSector = (activeSlot * 14) + i;
        FlashSwitchBank(physicalSector / 16);
        u16 bankSector = physicalSector % 16;
        
        u8* sectorAddr = (u8*)(FLASH_BASE + (bankSector << 12));
        u32 signature = *(u32*)(sectorAddr + SECTOR_SIGNATURE_OFFSET);
        
        if (signature == SECTOR_SIGNATURE) {
            u16 id = *(u16*)(sectorAddr + offsetof(struct SaveSector, id));
            if (id < 14) {
                logicalToPhysical[id] = physicalSector;
                
                // Copy entire sector into RAM
                u8* dest = (u8*)&gSaveSectors[id];
                for(int j=0; j<4096; j++) {
                    dest[j] = sectorAddr[j];
                }
            }
        }
    }

    // 3. Reconstruct SaveBlock1 Buffer
    u8* dest = gPokemonStorageBuffer;
    u8* src = gSaveSectors[1].data;
    for(int j=0; j<SECTOR_DATA_SIZE; j++) dest[j] = src[j];

    // 4. Find Empty Slot in Party and Inject
    u8 partyCount = gPokemonStorageBuffer[0x234];
    
    if (partyCount >= 6) {
        DrawScreenColor(0x001F); // Red (Party is full)
        while(1);
    }

    // Inject event
    u8* targetPartySlot = gPokemonStorageBuffer + 0x238 + (partyCount * 100);
    for (int i = 0; i < 100; i++) {
        targetPartySlot[i] = eventMon[i];
    }
    
    // Increment party count
    gPokemonStorageBuffer[0x234] = partyCount + 1;

    // 5. Deconstruct SaveBlock1 back to Sector 1
    src = gPokemonStorageBuffer;
    dest = gSaveSectors[1].data;
    for(int j=0; j<SECTOR_DATA_SIZE; j++) dest[j] = src[j];

    // 6. Write Sector 1 to Flash
    u16 physicalSector = logicalToPhysical[1];
    
    // Recalculate Checksum
    gSaveSectors[1].checksum = CalculateChecksum(gSaveSectors[1].data, SECTOR_DATA_SIZE);
    
    // Erase and Write
    FlashEraseSector(physicalSector);
    FlashWriteSector(physicalSector, (u8*)&gSaveSectors[1]);

    DrawScreenColor(0x03E0); // Green (Success!)
    while(1) {} 
}
