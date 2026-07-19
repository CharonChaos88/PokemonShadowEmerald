#include "font.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;

#include <stdint.h>

#define REG_DISPCNT  *(volatile u16*)0x04000000
#define REG_KEYINPUT *(volatile u16*)0x04000130
#define REG_VCOUNT   *(volatile u16*)0x04000006
#define REG_IME      *(volatile u16*)0x04000208
#define REG_IE       *(volatile u16*)0x04000200
#define REG_IF       *(volatile u16*)0x04000202
#define REG_DISPSTAT *(volatile u16*)0x04000004
#define INTR_VECTOR  *(volatile u32*)0x03FFFFFC

#define DISPCNT_MODE_3 0x0003
#define DISPCNT_BG2_ON 0x0400

#define KEY_A      0x0001
#define KEY_B      0x0002
#define KEY_SELECT 0x0004
#define KEY_START  0x0008
#define KEY_RIGHT  0x0010
#define KEY_LEFT   0x0020
#define KEY_UP     0x0040
#define KEY_DOWN   0x0080

extern const u8 gMultibootEventPayload[];
extern const u32 gMultibootEventPayloadSize;

// Use the EXACT official struct layout from include/gba/multiboot.h
struct MultiBootParam {
    u32 system_work[5];    // 0x00
    u8 handshake_data;     // 0x14
    // compiler inserts 1 byte padding here for u16 alignment
    u16 handshake_timeout; // 0x16
    u8 probe_count;        // 0x18
    u8 client_data[3];     // 0x19
    u8 palette_data;       // 0x1C
    u8 response_bit;       // 0x1D
    u8 client_bit;         // 0x1E
    u8 reserved1;          // 0x1F
    const u8 *boot_srcp;   // 0x20
    const u8 *boot_endp;   // 0x24
    const u8 *masterp;     // 0x28
    u8 *reserved2[3];      // 0x2C
    u32 system_work2[4];   // 0x38
    u8 sendflag;           // 0x48
    u8 probe_target_bit;   // 0x49
    u8 check_wait;         // 0x4A
    u8 server_type;        // 0x4B
};

// Official multiboot protocol functions (from multiboot.s)
extern void MultiBootInit(struct MultiBootParam *mp);
extern int MultiBootMain(struct MultiBootParam *mp);
extern void MultiBootStartProbe(struct MultiBootParam *mp);
extern void MultiBootStartMaster(struct MultiBootParam *mp, const u8 *srcp, int length, u8 palette_color, s8 palette_speed);
extern int MultiBootCheckComplete(struct MultiBootParam *mp);

// Keep patched payload in EWRAM (.bss)
// Actual payload is ~1KB, but pad to 4KB to allow room for growth
u8 gPatchedPayload[4096] __attribute__((aligned(4)));

void *memcpy(void *dest, const void *src, u32 n) {
    u8 *d = dest;
    const u8 *s = src;
    while (n--) *d++ = *s++;
    return dest;
}

void* memset(void* dest, int val, u32 len) {
    u8* ptr = (u8*)dest;
    while (len-- > 0) *ptr++ = val;
    return dest;
}

void DrawChar(int x, int y, char c, u16 color, u16 bgcolor) {
    volatile u16* vram = (volatile u16*)0x06000000;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (font8x8_basic[(int)c][row] & (1 << col)) {
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
        str++;
    }
}

void DrawScreenColor(u16 color) {
    volatile u16* vram = (volatile u16*)0x06000000;
    for (int i = 0; i < 240 * 160; i++) {
        vram[i] = color;
    }
}

const u8 auraMew[100] = {
    0x0, 0x0, 0x0, 0x0, 0x6e, 0x4e, 0x0, 0x0, 0xc1, 0xbf, 0xd1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x2, 0xbb, 0xef, 0xcc, 0xbb, 0xff, 0x0, 0x0, 0x0, 0x37, 0xa9, 0x0, 0x0, 0x97, 0x0, 0x0, 0x0, 0xe2, 0x4, 0x0, 0x0, 0x0, 0x78, 0x0, 0x0, 0x1, 0x0, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x23, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xa, 0x22, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0x0, 0x28, 0x0, 0x28, 0x0, 0x19, 0x0, 0x19, 0x0, 0x19, 0x0, 0x19, 0x0, 0x19, 0x0
};

const u8 pcnySeviper[100] = {
    0x0, 0x0, 0x0, 0x0, 0x6e, 0x4e, 0x0, 0x0, 0xcd, 0xd9, 0xea, 0xdd, 0xde, 0xd9, 0xcc, 0xff, 0x0, 0x0, 0x2, 0x2, 0xca, 0xbd, 0xce, 0xcd, 0xff, 0x0, 0x0, 0x0, 0x60, 0x9f, 0x0, 0x0, 0x50, 0x1, 0x0, 0x0, 0xe2, 0x4, 0x0, 0x0, 0x0, 0x78, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x23, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xa, 0x22, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0x0, 0x28, 0x0, 0x28, 0x0, 0x19, 0x0, 0x19, 0x0, 0x19, 0x0, 0x19, 0x0, 0x19, 0x0
};

const char* options[] = {
    "Aura Mew",
    "PCNY Seviper"
};

const u8* dataPointers[] = {
    auraMew,
    pcnySeviper
};

int PayloadMain(void) {
    REG_DISPCNT = DISPCNT_MODE_3 | DISPCNT_BG2_ON;
    DrawScreenColor(0x0000); // Black

    int numOptions = 2;
    int selected = 0;
    u16 oldKeys = REG_KEYINPUT;
    struct MultiBootParam mb;

    // States: -1=Menu, 0=WaitStart, 1=Probing, 2=Sending, 3=Success
    int state = -1;
    int drawnState = -2;
    int distributions = 0;
    // 0=waiting for clients, 1=MultiBootStartMaster called, transferring
    int mbPhase = 0;

    // Set up interrupts once at startup
    extern void IntrMain(void);
    INTR_VECTOR = (u32)IntrMain;
    REG_IE = 0x0001; // VBlank
    REG_DISPSTAT |= 0x0008; // VBlank IRQ Enable
    REG_IME = 1;

    while (1) {
        // VSync
        while (REG_VCOUNT >= 160);
        while (REG_VCOUNT < 160);
        
        u16 keys = REG_KEYINPUT;
        u16 pressed = ~keys & oldKeys;
        oldKeys = keys;

        if (state == -1) {
            // === MENU STATE ===
            if (drawnState != state) {
                DrawScreenColor(0x0000);
                DrawString(10, 10, "Select Event to Distribute:", 0x7FFF, 0x0000);
                DrawString(10, 140, "Press A to Confirm", 0x7FFF, 0x0000);
                drawnState = state;
            }
            
            for (int i = 0; i < numOptions; i++) {
                u16 color = (i == selected) ? 0x03E0 : 0x7FFF;
                DrawString(20, 30 + i * 12, options[i], color, 0x0000);
            }

            if (pressed & KEY_UP) {
                selected--;
                if (selected < 0) selected = numOptions - 1;
            }
            if (pressed & KEY_DOWN) {
                selected++;
                if (selected >= numOptions) selected = 0;
            }
            if (pressed & KEY_A) {
                // Copy the payload to RAM and patch it
                for (u32 i = 0; i < gMultibootEventPayloadSize && i < sizeof(gPatchedPayload); i++) {
                    gPatchedPayload[i] = gMultibootEventPayload[i];
                }
                
                // Search for the magic signature to find the injection offset
                u32 magicOffset = 0;
                for (u32 i = 0; i < gMultibootEventPayloadSize - 8; i++) {
                    if (gPatchedPayload[i] == 0x11 &&
                        gPatchedPayload[i+1] == 0x22 &&
                        gPatchedPayload[i+2] == 0x33 &&
                        gPatchedPayload[i+3] == 0x44 &&
                        gPatchedPayload[i+4] == 0x55 &&
                        gPatchedPayload[i+5] == 0x66 &&
                        gPatchedPayload[i+6] == 0x77 &&
                        gPatchedPayload[i+7] == 0x88) {
                        magicOffset = i + 8;
                        break;
                    }
                }
                
                if (magicOffset != 0) {
                    for (u32 i = 0; i < 100; i++) {
                        gPatchedPayload[magicOffset + i] = dataPointers[selected][i];
                    }
                }
                
                state = 0;
            }
        } else if (state == 0) {
            // === WAIT FOR START ===
            if (drawnState != state) {
                DrawScreenColor(0x0000);
                DrawString(10, 10, "DISTRIBUTION READY", 0x03E0, 0x0000);
                DrawString(10, 30, "Current Event:", 0x7FFF, 0x0000);
                DrawString(120, 30, options[selected], 0x03E0, 0x0000);
                DrawString(10, 50, "Connect Client GBA", 0x7FFF, 0x0000);
                DrawString(10, 60, "with a Link Cable.", 0x7FFF, 0x0000);
                DrawString(10, 80, "Press START to Begin.", 0x7FFF, 0x0000);
                DrawString(10, 140, "Press B to Cancel", 0x001F, 0x0000);
                drawnState = state;
            }
            
            if (pressed & KEY_START) {
                // Initialize the multiboot protocol.
                MultiBootInit(&mb);
                
                mbPhase = 0;
                state = 1;
                drawnState = -2;
            }
            if (pressed & KEY_B) {
                state = -1;
                drawnState = -2;
            }
        } else if (state == 1) {
            // === PROBING + TRANSFERRING ===
            // MultiBootMain is a non-blocking state machine called once per VBlank.
            
            if (drawnState != state) {
                DrawScreenColor(0x0000);
                if (mbPhase == 0) {
                    DrawString(10, 10, "SEARCHING FOR CLIENT...", 0x03FF, 0x0000);
                    DrawString(10, 30, "Turn on Client GBA now", 0x7FFF, 0x0000);
                    DrawString(10, 40, "(hold START+SELECT on boot)", 0x7FFF, 0x0000);
                } else {
                    DrawString(10, 10, "TRANSMITTING...", 0x03FF, 0x0000);
                    DrawString(10, 30, "Do NOT turn off", 0x7FFF, 0x0000);
                    DrawString(10, 40, "either GBA!", 0x7FFF, 0x0000);
                }
                DrawString(10, 140, "Press B to Cancel", 0x001F, 0x0000);
                drawnState = state;
            }
            
            if (pressed & KEY_B) {
                state = 0;
                drawnState = -2;
                continue;
            }

            // Force SD bit (master flag) before each call.
            // On real hardware SD is read-only from pin state, but
            // emulators may not assert it automatically for Player 1.
            *(volatile u16*)0x04000128 |= 0x0008;
            
            // Drive the state machine one step per VBlank
            int result = MultiBootMain(&mb);

            // Debug: show live status on screen without clearing
            {
                // Show error code
                char hex[5] = "0x00";
                u8 val = (u8)result;
                hex[2] = "0123456789ABCDEF"[(val >> 4) & 0xF];
                hex[3] = "0123456789ABCDEF"[val & 0xF];
                DrawString(10, 60, "Err:", 0x7FFF, 0x0000);
                DrawString(42, 60, hex, 0x03FF, 0x0000);
                
                // Show probe_count
                val = mb.probe_count;
                hex[2] = "0123456789ABCDEF"[(val >> 4) & 0xF];
                hex[3] = "0123456789ABCDEF"[val & 0xF];
                DrawString(10, 70, "Prb:", 0x7FFF, 0x0000);
                DrawString(42, 70, hex, 0x03FF, 0x0000);
                
                // Show client_bit
                val = mb.client_bit;
                hex[2] = "0123456789ABCDEF"[(val >> 4) & 0xF];
                hex[3] = "0123456789ABCDEF"[val & 0xF];
                DrawString(10, 80, "Cli:", 0x7FFF, 0x0000);
                DrawString(42, 80, hex, 0x03FF, 0x0000);
                
                // Show SIOCNT raw value
                u16 sio = *(volatile u16*)0x04000128;
                hex[2] = "0123456789ABCDEF"[(sio >> 4) & 0xF];
                hex[3] = "0123456789ABCDEF"[sio & 0xF];
                DrawString(10, 90, "SIO:", 0x7FFF, 0x0000);
                DrawString(42, 90, hex, 0x03FF, 0x0000);
                char hex2[5] = "0x00";
                hex2[2] = "0123456789ABCDEF"[(sio >> 12) & 0xF];
                hex2[3] = "0123456789ABCDEF"[(sio >> 8) & 0xF];
                DrawString(74, 90, hex2, 0x03FF, 0x0000);
            }

            if (MultiBootCheckComplete(&mb)) {
                // Transfer + handshake fully complete!
                state = 2;
                distributions++;
                drawnState = -2;
            } else if (result != 0) {
                // Error during probing is normal (no client yet).
                // Silently reinitialize and keep trying. Don't redraw.
                MultiBootInit(&mb);
                mbPhase = 0;
            } else if (mbPhase == 0 && mb.probe_count == 0 
                       && mb.client_bit != 0 && mb.check_wait == 0) {
                // Clients detected and stable! Start the master transfer.
                u32 payloadLen = gMultibootEventPayloadSize;
                MultiBootStartMaster(&mb, gPatchedPayload, payloadLen, 4, 0);
                
                // If MultiBootStartMaster accepted, probe_count is now 0xd0
                if (mb.probe_count == 0xd0) {
                    mbPhase = 1;
                    drawnState = -2; // Force redraw to show "TRANSMITTING"
                }
            }
        } else if (state == 2) {
            // === SUCCESS ===
            if (drawnState != state) {
                DrawScreenColor(0x0000);
                DrawString(10, 10, "SUCCESS!", 0x03E0, 0x0000);
                DrawString(10, 30, "Payload transmitted.", 0x7FFF, 0x0000);
                DrawString(10, 60, "Press START for next.", 0x7FFF, 0x0000);
                DrawString(10, 140, "Press B for Menu", 0x7FFF, 0x0000);
                drawnState = state;
            }
            
            if (pressed & KEY_START) {
                state = 0;
                drawnState = -2;
            }
            if (pressed & KEY_B) {
                state = -1;
                drawnState = -2;
            }
        }
    }
    return 0;
}
