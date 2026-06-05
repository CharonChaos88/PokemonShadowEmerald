#ifndef GUARD_PALETTE_EDITOR_H
#define GUARD_PALETTE_EDITOR_H

#include "global.h"
#include "pokemon.h"

// The unified global fetcher for all custom/default palettes
const u16* GetUnifiedMonPalette(u16 species, bool32 isShiny, u32 personality, u8 altPalette);

// Initializes the Palette Editor UI
void CB2_InitPaletteEditor(void);

#endif // GUARD_PALETTE_EDITOR_H