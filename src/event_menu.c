#include "global.h"
#include "main.h"
#include "menu.h"
#include "task.h"
#include "bg.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "string_util.h"
#include "sound.h"
#include "constants/songs.h"
#include "event_distribution.h"
#include "list_menu.h"
#include "malloc.h"
#include "palette.h"
#include "scanline_effect.h"
#include "gpu_regs.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/rgb.h"

// Define our list of events!
const struct EventPokemonTemplate gEventPokemonList[] = {
    {
        .title = _("Aura Mew"),
        .species = SPECIES_MEW,
        .level = 10,
        .nature = 0xFF, // Random Nature
        .heldItem = ITEM_NONE,
        .moves = {MOVE_POUND, MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE},
        .otName = _("Aura"),
        .otGender = 0,
        .otId = 20078,
        .pokeball = ITEM_POKE_BALL,
        .isShiny = FALSE,
        .isFatefulEncounter = TRUE,
    },
    {
        .title = _("10 ANIV Charizard"),
        .species = SPECIES_CHARIZARD,
        .level = 70,
        .nature = 0xFF, // Random Nature
        .heldItem = ITEM_NONE,
        .moves = {MOVE_WING_ATTACK, MOVE_SLASH, MOVE_DRAGON_RAGE, MOVE_FIRE_SPIN},
        .otName = _("10 ANIV"),
        .otGender = 0,
        .otId = 10,
        .pokeball = ITEM_POKE_BALL,
        .isShiny = FALSE,
        .isFatefulEncounter = TRUE,
    }
};

const u32 gNumEventPokemon = ARRAY_COUNT(gEventPokemonList);

static void Task_EventMenuProcessInput(u8 taskId);

static void VBlankCB_EventMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_EventMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    CopyBgTilemapBufferToVram(0);
}

static const struct WindowTemplate sEventMenuWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 26,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sEventMenuDummyWindow = DUMMY_WIN_TEMPLATE;

static const struct BgTemplate sEventMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

void CB2_InitEventDistributionMenu(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaClear32(3, OAM, OAM_SIZE);
    DmaClear16(3, PLTT, PLTT_SIZE);

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sEventMenuBgTemplates, ARRAY_COUNT(sEventMenuBgTemplates));
    FreeAllWindowBuffers();
    DeactivateAllTextPrinters();
    ResetPaletteFade();
    ResetTasks();
    SetVBlankCallback(VBlankCB_EventMenu);

    InitWindows(sEventMenuWindowTemplates);
    DeactivateAllTextPrinters();
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    LoadUserWindowBorderGfx(0, 1, BG_PLTT_ID(14));
    Menu_LoadStdPalAt(BG_PLTT_ID(15));
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetBackdropFromColor(RGB_BLACK);
    struct ListMenuItem* listItems = AllocZeroed(sizeof(struct ListMenuItem) * gNumEventPokemon);
    for (int i = 0; i < gNumEventPokemon; i++) {
        listItems[i].name = gEventPokemonList[i].title;
        listItems[i].id = i;
    }

    struct ListMenuTemplate listTemplate;
    listTemplate.items = listItems;
    listTemplate.moveCursorFunc = ListMenuDefaultCursorMoveFunc;
    listTemplate.itemPrintFunc = NULL;
    listTemplate.totalItems = gNumEventPokemon;
    listTemplate.maxShowed = (gNumEventPokemon < 8) ? gNumEventPokemon : 8;
    listTemplate.windowId = 0;
    listTemplate.header_X = 0;
    listTemplate.item_X = 8;
    listTemplate.cursor_X = 0;
    listTemplate.upText_Y = 1;
    listTemplate.cursorPal = 2;
    listTemplate.fillValue = 1;
    listTemplate.cursorShadowPal = 3;
    listTemplate.lettersSpacing = 0;
    listTemplate.itemVerticalPadding = 0;
    listTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    listTemplate.fontId = 1;
    listTemplate.cursorKind = 0;

    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 1, 14);
    PutWindowTilemap(0);
    u8 listTaskId = ListMenuInit(&listTemplate, 0, 0);

    CopyWindowToVram(0, COPYWIN_FULL);
    CopyBgTilemapBufferToVram(0);
    
    // We need to pass the listItems to the task so we can free it later
    u8 taskId = CreateTask(Task_EventMenuProcessInput, 0);
    gTasks[taskId].data[0] = listTaskId;
    gTasks[taskId].data[1] = ((u32)listItems) & 0xFFFF;
    gTasks[taskId].data[2] = ((u32)listItems) >> 16;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_BG0_ON);
    SetMainCallback2(CB2_EventMenu);
}

static void Task_EventMenuProcessInput(u8 taskId)
{
    u8 listTaskId = gTasks[taskId].data[0];
    s32 input = ListMenu_ProcessInput(listTaskId);
    struct ListMenuItem* listItems = (struct ListMenuItem*)((gTasks[taskId].data[1]) | (gTasks[taskId].data[2] << 16));

    if (JOY_NEW(A_BUTTON))
    {
        if (input != LIST_CANCEL && input != LIST_NOTHING_CHOSEN)
        {
            PlaySE(SE_SELECT);
            // They chose an event!
            Free(listItems);
            DestroyListMenuTask(listTaskId, NULL, NULL);
            DestroyTask(taskId);
            
            // Distribute and trigger the Berry Fix UI!
            DistributeEventPokemon(&gEventPokemonList[input]);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        // Cancel back to main menu
        Free(listItems);
        DestroyListMenuTask(listTaskId, NULL, NULL);
        DestroyTask(taskId);
        
        extern void CB2_InitMainMenu(void);
        SetMainCallback2(CB2_InitMainMenu);
    }
}
