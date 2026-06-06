#include "global.h"
#include "main.h"
#include "bg.h"
#include "window.h"
#include "text.h"
#include "menu.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_animation.h"
#include "trainer_pokemon_sprites.h"
#include "task.h"
#include "gpu_regs.h"
#include "string_util.h"
#include "text_window.h"
#include "malloc.h"
#include "sound.h"
#include "data.h"
#include "battle.h"
#include "script.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "overworld.h"
#include "decompress.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "palette_editor.h"

// --- WARDROBE FETCHER (NOW CHECKS SLOT NUMBERS) ---
#define MAX_CUSTOM_PALETTES 15

const u16 *GetUnifiedMonPalette(u16 species, bool32 isShiny, u32 personality, u8 altPalette)
{
    const u16 *defaultPal = GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality);

    if (altPalette == 0 || species >= NUM_SPECIES)
        return defaultPal;

    // Search the Wardrobe for this exact individual Pokemon's PID AND the Slot Number
    for (u8 i = 0; i < MAX_CUSTOM_PALETTES; i++)
    {
        u32 savedPersonality = isShiny ? gSaveBlock3Ptr->customPalettesShiny[i].personality
                                       : gSaveBlock3Ptr->customPalettesNormal[i].personality;

        u8 savedSlot = isShiny ? gSaveBlock3Ptr->customPalettesShiny[i].slotNum
                               : gSaveBlock3Ptr->customPalettesNormal[i].slotNum;

        if (savedPersonality == personality && savedSlot == altPalette)
        {
            return isShiny ? gSaveBlock3Ptr->customPalettesShiny[i].palette
                           : gSaveBlock3Ptr->customPalettesNormal[i].palette;
        }
    }

    return defaultPal;
}

// --- EDITOR UI STATE ---
struct PaletteEditor
{
    u8 frontSpriteId;
    u8 backSpriteId;
    u16 mutablePalette[16];
    u8 currentAlt;
    u8 editColorIndex;
    u8 editChannel;
    bool32 isShiny;
    struct Pokemon mon;
};

// --- FORWARD DECLARATIONS ---
static void HandleInput_PaletteEditor(u8 taskId);
static void Exit_PaletteEditor(u8 taskId);

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}
static void CB2_PaletteEditorRunner(void)
{
    RunTasks();
    BuildOamBuffer();
    UpdatePaletteFade();
}

// --- UI PRINTING (TEXT CURSOR STRINGS) ---
static const u8 sText_TitleNormal[] = _("PALETTE EDITOR (NORMAL)");
static const u8 sText_TitleShiny[] = _("PALETTE EDITOR (SHINY)");
static const u8 sText_ArrowSlot[] = _("{RIGHT_ARROW} Slot: ");
static const u8 sText_EmptySlot[] = _("  Slot: ");
static const u8 sText_ArrowIndex[] = _("{RIGHT_ARROW} Index: ");
static const u8 sText_EmptyIndex[] = _("  Index: ");
static const u8 sText_ArrowRed[] = _("{RIGHT_ARROW} Red:   ");
static const u8 sText_EmptyRed[] = _("  Red:   ");
static const u8 sText_ArrowGreen[] = _("{RIGHT_ARROW} Green: ");
static const u8 sText_EmptyGreen[] = _("  Green: ");
static const u8 sText_ArrowBlue[] = _("{RIGHT_ARROW} Blue:  ");
static const u8 sText_EmptyBlue[] = _("  Blue:  ");

static void PrintEditorUI(struct PaletteEditor *data)
{
    u16 color = data->mutablePalette[data->editColorIndex];
    static const u8 sTextColor[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x214, 14);

    // Dynamic Title based on Shiny State
    if (data->isShiny)
    {
        AddTextPrinterParameterized4(0, FONT_SMALL, 4, 4, 0, 0, sTextColor, 0, sText_TitleShiny);
    }
    else
    {
        AddTextPrinterParameterized4(0, FONT_SMALL, 4, 4, 0, 0, sTextColor, 0, sText_TitleNormal);
    }

    // Slot
    if (data->editChannel == 0)
        StringCopy(gStringVar4, sText_ArrowSlot);
    else
        StringCopy(gStringVar4, sText_EmptySlot);
    ConvertIntToDecimalStringN(gStringVar1, data->currentAlt, STR_CONV_MODE_LEFT_ALIGN, 2);
    StringAppend(gStringVar4, gStringVar1);
    AddTextPrinterParameterized4(0, FONT_NORMAL, 4, 24, 0, 0, sTextColor, 0, gStringVar4);

    // Index
    if (data->editChannel == 1)
        StringCopy(gStringVar4, sText_ArrowIndex);
    else
        StringCopy(gStringVar4, sText_EmptyIndex);
    ConvertIntToDecimalStringN(gStringVar1, data->editColorIndex, STR_CONV_MODE_LEFT_ALIGN, 2);
    StringAppend(gStringVar4, gStringVar1);
    AddTextPrinterParameterized4(0, FONT_NORMAL, 4, 40, 0, 0, sTextColor, 0, gStringVar4);

    // Red
    if (data->editChannel == 2)
        StringCopy(gStringVar4, sText_ArrowRed);
    else
        StringCopy(gStringVar4, sText_EmptyRed);
    ConvertIntToDecimalStringN(gStringVar1, (color & 0x1F), STR_CONV_MODE_LEFT_ALIGN, 2);
    StringAppend(gStringVar4, gStringVar1);
    AddTextPrinterParameterized4(0, FONT_NORMAL, 4, 56, 0, 0, sTextColor, 0, gStringVar4);

    // Green
    if (data->editChannel == 3)
        StringCopy(gStringVar4, sText_ArrowGreen);
    else
        StringCopy(gStringVar4, sText_EmptyGreen);
    ConvertIntToDecimalStringN(gStringVar1, ((color >> 5) & 0x1F), STR_CONV_MODE_LEFT_ALIGN, 2);
    StringAppend(gStringVar4, gStringVar1);
    AddTextPrinterParameterized4(0, FONT_NORMAL, 4, 72, 0, 0, sTextColor, 0, gStringVar4);

    // Blue
    if (data->editChannel == 4)
        StringCopy(gStringVar4, sText_ArrowBlue);
    else
        StringCopy(gStringVar4, sText_EmptyBlue);
    ConvertIntToDecimalStringN(gStringVar1, ((color >> 10) & 0x1F), STR_CONV_MODE_LEFT_ALIGN, 2);
    StringAppend(gStringVar4, gStringVar1);
    AddTextPrinterParameterized4(0, FONT_NORMAL, 4, 88, 0, 0, sTextColor, 0, gStringVar4);

    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

// --- INITIALIZATION ---
void CB2_InitPaletteEditor(void)
{
    u8 taskId;
    struct PaletteEditor *data;
    u16 species;
    u32 personality;
    const u16 *pal;
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        FreeMonSpritesGfx();
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        DmaFillLarge16(3, 0, (u8 *)VRAM, VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        gMain.state++;
        break;
    case 1:
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        ResetAllPicSprites();
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 2: 
        InitBgsFromTemplates(0, (struct BgTemplate[]){{0,0,24,0,0,0,0},{1,1,28,0,0,0,0}}, 2); 
        FreeAllWindowBuffers(); 
        
        // Define the array first to avoid preprocessor comma confusion
        const struct WindowTemplate winTemplates[] = {{0,14,2,15,16,15,1}, DUMMY_WIN_TEMPLATE};
        InitWindows(winTemplates); 
        
        LoadPalette(GetTextWindowPalette(0), BG_PLTT_ID(15), 32); 
        LoadStdWindowGfx(0, 0x214, 14); 
        gMain.state++; 
        break;
    case 3:
        AllocateMonSpritesGfx();
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON);
        ShowBg(0);
        taskId = CreateTask(HandleInput_PaletteEditor, 0);
        data = AllocZeroed(sizeof(struct PaletteEditor));
        *(struct PaletteEditor **)(&gTasks[taskId].data[0]) = data;

        if (gSpecialVar_0x8005)
            BoxMonToMon(&gPokemonStoragePtr->boxes[gSpecialVar_MonBoxId][gSpecialVar_MonBoxPos], &data->mon);
        else
            data->mon = gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004];

        data->currentAlt = GetMonData(&data->mon, MON_DATA_ALT_PALETTE);
        if (data->currentAlt == 0)
            data->currentAlt = 1;

        data->isShiny = GetMonData(&data->mon, MON_DATA_IS_SHINY);
        species = GetMonData(&data->mon, MON_DATA_SPECIES_OR_EGG);
        personality = GetMonData(&data->mon, MON_DATA_PERSONALITY);
        data->editColorIndex = 1;

        pal = GetUnifiedMonPalette(species, data->isShiny, personality, data->currentAlt);
        memcpy(data->mutablePalette, pal, 32);
        LoadSpritePaletteWithTag(data->mutablePalette, personality);

        HandleLoadSpecialPokePic(TRUE, gMonSpritesGfxPtr->spritesGfx[1], species, personality);
        HandleLoadSpecialPokePic(FALSE, gMonSpritesGfxPtr->spritesGfx[2], species, personality);

        struct SpriteSheet frontSheet = {gMonSpritesGfxPtr->spritesGfx[1], 0x800, 0x1234};
        struct SpriteSheet backSheet = {gMonSpritesGfxPtr->spritesGfx[2], 0x800, 0x1235};
        LoadSpriteSheet(&frontSheet);
        LoadSpriteSheet(&backSheet);

        SetMultiuseSpriteTemplateToPokemon(species, 1);
        gMultiuseSpriteTemplate.paletteTag = personality;
        gMultiuseSpriteTemplate.tileTag = 0x1234;
        data->frontSpriteId = CreateSprite(&gMultiuseSpriteTemplate, 48, 64, 0);
        gSprites[data->frontSpriteId].oam.paletteNum = IndexOfSpritePaletteTag(personality);
        gSprites[data->frontSpriteId].callback = SpriteCallbackDummy;
        gSprites[data->frontSpriteId].animPaused = TRUE;

        SetMultiuseSpriteTemplateToPokemon(species, 2);
        gMultiuseSpriteTemplate.paletteTag = personality;
        gMultiuseSpriteTemplate.tileTag = 0x1235;
        data->backSpriteId = CreateSprite(&gMultiuseSpriteTemplate, 48, 120 + gSpeciesInfo[species].backPicYOffset, 0);
        gSprites[data->backSpriteId].oam.paletteNum = IndexOfSpritePaletteTag(personality);
        gSprites[data->backSpriteId].callback = SpriteCallbackDummy;
        gSprites[data->backSpriteId].animPaused = TRUE;

        PrintEditorUI(data);
        gMain.state++;
        break;
    case 4:
        EnableInterrupts(1);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(CB2_PaletteEditorRunner);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        break;
    }
}

// --- INPUT & EXIT ---
static void HandleInput_PaletteEditor(u8 taskId)
{
    struct PaletteEditor *data = *(struct PaletteEditor **)(&gTasks[taskId].data[0]);
    if (gPaletteFade.active)
        return;

    // TOGGLE SHINY PALETTE (L or R Button)
    if (JOY_NEW(R_BUTTON) || JOY_NEW(L_BUTTON))
    {
        data->isShiny = !data->isShiny;

        u16 species = GetMonData(&data->mon, MON_DATA_SPECIES_OR_EGG);
        u32 personality = GetMonData(&data->mon, MON_DATA_PERSONALITY);

        memcpy(data->mutablePalette, GetUnifiedMonPalette(species, data->isShiny, personality, data->currentAlt), 32);

        u8 palSlot = IndexOfSpritePaletteTag(personality);
        if (palSlot != 0xFF)
        {
            LoadPalette(data->mutablePalette, OBJ_PLTT_ID(palSlot), 32);
        }

        PrintEditorUI(data);
        PlaySE(SE_SELECT);
        return;
    }

    // SAVE SELECTION
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        if (data->currentAlt > 0)
        {
            u32 personality = GetMonData(&data->mon, MON_DATA_PERSONALITY);
            s8 saveSlot = -1;
            struct CustomPaletteSave *wardrobe = data->isShiny ? gSaveBlock3Ptr->customPalettesShiny
                                                               : gSaveBlock3Ptr->customPalettesNormal;

            // 1. Check if this exact individual Pokemon ALREADY HAS THIS SPECIFIC SLOT saved
            for (u8 i = 0; i < MAX_CUSTOM_PALETTES; i++)
            {
                if (wardrobe[i].personality == personality && wardrobe[i].slotNum == data->currentAlt)
                {
                    saveSlot = i;
                    break;
                }
            }

            // 2. If not, look for an empty slot (personality == 0)
            if (saveSlot == -1)
            {
                for (u8 i = 0; i < MAX_CUSTOM_PALETTES; i++)
                {
                    if (wardrobe[i].personality == 0)
                    {
                        saveSlot = i;
                        break;
                    }
                }
            }

            // 3. If wardrobe is totally full, force overwrite slot 0
            if (saveSlot == -1)
                saveSlot = 0;

            // 4. Save the PID AND the Slot Number!
            wardrobe[saveSlot].personality = personality;
            wardrobe[saveSlot].slotNum = data->currentAlt;
            memcpy(wardrobe[saveSlot].palette, data->mutablePalette, 32);
        }

        if (gSpecialVar_0x8005)
            SetBoxMonData(&gPokemonStoragePtr->boxes[gSpecialVar_MonBoxId][gSpecialVar_MonBoxPos], MON_DATA_ALT_PALETTE, &data->currentAlt);
        else
            SetMonData(&gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004], MON_DATA_ALT_PALETTE, &data->currentAlt);

        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Exit_PaletteEditor;
        return;
    }

    // Move Cursor Up/Down
    if (JOY_NEW(DPAD_UP))
    {
        if (data->editChannel == 0)
            data->editChannel = 4;
        else
            data->editChannel--;
        PrintEditorUI(data);
        PlaySE(SE_SELECT);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        data->editChannel = (data->editChannel + 1) % 5;
        PrintEditorUI(data);
        PlaySE(SE_SELECT);
    }

    // Modify Values Left/Right
    if (JOY_REPEAT(DPAD_LEFT) || JOY_REPEAT(DPAD_RIGHT))
    {
        s8 dir = JOY_REPEAT(DPAD_RIGHT) ? 1 : -1;
        u16 *colorPtr = &data->mutablePalette[data->editColorIndex];
        u8 r = *colorPtr & 0x1F, g = (*colorPtr >> 5) & 0x1F, b = (*colorPtr >> 10) & 0x1F;
        bool8 changed = FALSE;
        u16 species = GetMonData(&data->mon, MON_DATA_SPECIES_OR_EGG);
        u32 personality = GetMonData(&data->mon, MON_DATA_PERSONALITY);

        switch (data->editChannel)
        {
        case 0:
            data->currentAlt = (data->currentAlt + dir + 3) % 3;
            memcpy(data->mutablePalette, GetUnifiedMonPalette(species, data->isShiny, personality, data->currentAlt), 32);
            changed = TRUE;
            break;
        case 1:
            data->editColorIndex = (data->editColorIndex + dir - 1 + 15) % 15 + 1;
            changed = TRUE;
            break;
        case 2:
            if (data->currentAlt > 0 && (int)r + dir >= 0 && (int)r + dir <= 31)
            {
                r += dir;
                changed = TRUE;
            }
            break;
        case 3:
            if (data->currentAlt > 0 && (int)g + dir >= 0 && (int)g + dir <= 31)
            {
                g += dir;
                changed = TRUE;
            }
            break;
        case 4:
            if (data->currentAlt > 0 && (int)b + dir >= 0 && (int)b + dir <= 31)
            {
                b += dir;
                changed = TRUE;
            }
            break;
        }

        if (changed)
        {
            if (data->editChannel >= 2)
                *colorPtr = RGB(r, g, b);

            u8 palSlot = IndexOfSpritePaletteTag(personality);
            if (palSlot != 0xFF)
            {
                LoadPalette(data->mutablePalette, OBJ_PLTT_ID(palSlot), 32);
            }

            PrintEditorUI(data);
            PlaySE(SE_SELECT);
        }
    }
}

static void Exit_PaletteEditor(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        struct PaletteEditor *data = *(struct PaletteEditor **)(&gTasks[taskId].data[0]);
        Free(data);
        FreeMonSpritesGfx();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToField);
    }
}