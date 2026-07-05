#include "global.h"
#include "bg.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "m4a.h"
#include "malloc.h"
#include "menu_helpers.h"
#include "opowers_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/o_powers.h"
#include "opower_costs.h"

static const u8 sOPowerNames[NUM_O_POWERS][25] = {
    [OPOWER_NONE]          = _("None"),
    [OPOWER_HATCHING]      = _("Hatching Power"),
    [OPOWER_BARGAIN]       = _("Bargain Power"),
    [OPOWER_PRIZE_MONEY]   = _("Prize Money Power"),
    [OPOWER_EXP_POINT]     = _("Exp. Point Power"),
    [OPOWER_CAPTURE]       = _("Capture Power"),
    [OPOWER_ENCOUNTER]     = _("Encounter Power"),
    [OPOWER_STEALTH]       = _("Stealth Power"),
    [OPOWER_HP_RESTORING]  = _("HP Restoring"),
    [OPOWER_PP_RESTORING]  = _("PP Restoring"),
    [OPOWER_FULL_RECOVERY] = _("Full Recovery"),
    [OPOWER_BEFRIENDING]   = _("Befriending Power"),
    [OPOWER_ATTACK]        = _("Attack Power"),
    [OPOWER_DEFENSE]       = _("Defense Power"),
    [OPOWER_SP_ATK]        = _("Sp. Atk. Power"),
    [OPOWER_SP_DEF]        = _("Sp. Def. Power"),
    [OPOWER_SPEED]         = _("Speed Power"),
    [OPOWER_CRITICAL]      = _("Critical Power"),
    [OPOWER_ACCURACY]      = _("Accuracy Power"),
};

#define tCurrentPower data[0]
#define tCurrentLevel data[1]

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

enum {
    WIN_MAIN,
    WIN_COUNT
};

static const struct WindowTemplate sWindowTemplates[] =
{
    [WIN_MAIN] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 20,
        .paletteNum = 0xF,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE,
};

static u8 GetNextUnlockedPower(u8 currentId, int dir)
{
    u8 id = currentId;
    u8 i;
    for (i = 0; i < NUM_O_POWERS; i++)
    {
        if (dir > 0)
        {
            id++;
            if (id >= NUM_O_POWERS) id = 1;
        }
        else
        {
            if (id <= 1) id = NUM_O_POWERS - 1;
            else id--;
        }

        if (gSaveBlock2Ptr->oPowerLevels[id] > 0)
            return id;
    }
    return 0; // None unlocked
}

static void PrintMenuText(u8 taskId)
{
    u8 fontId = FONT_NORMAL;
    u8 textBuffer[64];
    u8 orbsStr[4];
    u8 maxOrbsStr[4];
    u8 costStr[4];
    
    u8 currentPower = gTasks[taskId].tCurrentPower;
    u8 currentLevel = gTasks[taskId].tCurrentLevel;
    u8 orbs = gSaveBlock2Ptr->oPowerOrbs;
    u8 maxOrbs = 10;
    
    static const u8 sText_Title[] = _("O-POWERS");
    static const u8 sText_Power[] = _("Power: ");
    static const u8 sText_Cost[] = _("Cost: ");
    static const u8 sText_Orbs[] = _("Orbs: ");
    static const u8 sText_Slash[] = _("/");
    static const u8 sText_Instructions[] = _("Up/Down: Select Power\nLeft/Right: Select Level\nA: Use  B: Exit");
    static const u8 sText_NoneUnlocked[] = _("No O-Powers unlocked.");
    static const u8 sText_Active[] = _("ACTIVE");

    static const u8 sText_Space[] = _(" ");

    FillWindowPixelBuffer(WIN_MAIN, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_MAIN, fontId, sText_Title, 16, 16, 0, NULL);

    if (currentPower == 0)
    {
        AddTextPrinterParameterized(WIN_MAIN, fontId, sText_NoneUnlocked, 16, 32, 0, NULL);
    }
    else
    {
        // Print current power
        StringCopy(textBuffer, sText_Power);
        StringAppend(textBuffer, sOPowerNames[currentPower]);
        StringAppend(textBuffer, sText_Space);
        StringAppend(textBuffer, sLevelNames[currentLevel - 1]);
        AddTextPrinterParameterized(WIN_MAIN, fontId, textBuffer, 16, 32, 0, NULL);

        // Print cost
        u8 cost = sOPowerCosts[currentPower][currentLevel - 1];
        StringCopy(textBuffer, sText_Cost);
        ConvertIntToDecimalStringN(costStr, cost, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(textBuffer, costStr);
        AddTextPrinterParameterized(WIN_MAIN, fontId, textBuffer, 16, 48, 0, NULL);
    }

    // Print Orbs gauge
    StringCopy(textBuffer, sText_Orbs);
    ConvertIntToDecimalStringN(orbsStr, orbs, STR_CONV_MODE_LEFT_ALIGN, 2);
    ConvertIntToDecimalStringN(maxOrbsStr, maxOrbs, STR_CONV_MODE_LEFT_ALIGN, 2);
    StringAppend(textBuffer, orbsStr);
    StringAppend(textBuffer, sText_Slash);
    StringAppend(textBuffer, maxOrbsStr);
    AddTextPrinterParameterized(WIN_MAIN, fontId, textBuffer, 16, 64, 0, NULL);
    
    static const u8 sText_Is[] = _(" is ");
    if (gSaveBlock2Ptr->activeOPower != 0)
    {
        StringCopy(textBuffer, sOPowerNames[gSaveBlock2Ptr->activeOPower]);
        StringAppend(textBuffer, sText_Is);
        StringAppend(textBuffer, sText_Active);
        AddTextPrinterParameterized(WIN_MAIN, fontId, textBuffer, 16, 80, 0, NULL);
    }

    // Instructions
    AddTextPrinterParameterized(WIN_MAIN, fontId, sText_Instructions, 16, 112, 0, NULL);

    PutWindowTilemap(WIN_MAIN);
    CopyWindowToVram(WIN_MAIN, COPYWIN_FULL);
}

static void Exit_OPowersMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        Free(GetBgTilemapBuffer(0));
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}

static void UseOPower(u8 powerId, u8 level)
{
    u8 cost = sOPowerCosts[powerId][level - 1];
    gSaveBlock2Ptr->oPowerOrbs -= cost;

    gSaveBlock2Ptr->activeOPower = powerId;
    gSaveBlock2Ptr->activeOPowerLevel = level;
    gSaveBlock2Ptr->activeOPowerTimer = sOPowerDurations[level - 1];

    if (gSaveBlock2Ptr->oPowerLevels[powerId] == level)
    {
        if (level == OPOWER_LVL_1)
        {
            gSaveBlock2Ptr->oPowerUses[powerId]++;
            if (gSaveBlock2Ptr->oPowerUses[powerId] >= 15)
            {
                gSaveBlock2Ptr->oPowerLevels[powerId] = OPOWER_LVL_2;
                gSaveBlock2Ptr->oPowerUses[powerId] = 0;
            }
        }
        else if (level == OPOWER_LVL_2)
        {
            gSaveBlock2Ptr->oPowerUses[powerId]++;
            if (gSaveBlock2Ptr->oPowerUses[powerId] >= 30)
            {
                gSaveBlock2Ptr->oPowerLevels[powerId] = OPOWER_LVL_3;
                gSaveBlock2Ptr->oPowerUses[powerId] = 0;
            }
        }
    }
}

static void HandleInput_OPowersMenu(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Exit_OPowersMenu;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        u8 next = GetNextUnlockedPower(gTasks[taskId].tCurrentPower, -1);
        if (next != gTasks[taskId].tCurrentPower && next != 0)
        {
            gTasks[taskId].tCurrentPower = next;
            gTasks[taskId].tCurrentLevel = gSaveBlock2Ptr->oPowerLevels[next];
            PlaySE(SE_SELECT);
            PrintMenuText(taskId);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        u8 next = GetNextUnlockedPower(gTasks[taskId].tCurrentPower, 1);
        if (next != gTasks[taskId].tCurrentPower && next != 0)
        {
            gTasks[taskId].tCurrentPower = next;
            gTasks[taskId].tCurrentLevel = gSaveBlock2Ptr->oPowerLevels[next];
            PlaySE(SE_SELECT);
            PrintMenuText(taskId);
        }
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gTasks[taskId].tCurrentPower != 0)
        {
            if (gTasks[taskId].tCurrentLevel > 1)
            {
                gTasks[taskId].tCurrentLevel--;
                PlaySE(SE_SELECT);
                PrintMenuText(taskId);
            }
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (gTasks[taskId].tCurrentPower != 0)
        {
            u8 maxUnlocked = gSaveBlock2Ptr->oPowerLevels[gTasks[taskId].tCurrentPower];
            if (gTasks[taskId].tCurrentLevel < maxUnlocked)
            {
                gTasks[taskId].tCurrentLevel++;
                PlaySE(SE_SELECT);
                PrintMenuText(taskId);
            }
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (gTasks[taskId].tCurrentPower != 0)
        {
            u8 cost = sOPowerCosts[gTasks[taskId].tCurrentPower][gTasks[taskId].tCurrentLevel - 1];
            if (gSaveBlock2Ptr->oPowerOrbs >= cost)
            {
                PlaySE(SE_USE_ITEM);
                UseOPower(gTasks[taskId].tCurrentPower, gTasks[taskId].tCurrentLevel);
                PrintMenuText(taskId);
                
                // For now, close menu on use
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
                gTasks[taskId].func = Exit_OPowersMenu;
            }
            else
            {
                PlaySE(SE_FAILURE);
            }
        }
    }
}

static void CB2_OPowersMenuRunner(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_OPowersMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state = 1;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state = 2;
        break;
    case 2:
        ResetVramOamAndBgCntRegs();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
        InitWindows(sWindowTemplates);
        DeactivateAllTextPrinters();
        
        LoadPalette(GetTextWindowPalette(0), BG_PLTT_ID(15), 2 * PLTT_SIZE_4BPP);
        {
            u16 bgColor = GetTextWindowPalette(0)[1];
            LoadPalette(&bgColor, BG_PLTT_ID(0), 2);
        }
        FillBgTilemapBufferRect(0, 0, 0, 0, 32, 20, 15);
        
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        gMain.state = 3;
        break;
    case 3:
        taskId = CreateTask(HandleInput_OPowersMenu, 0);
        gTasks[taskId].tCurrentPower = GetNextUnlockedPower(0, 1);
        if (gTasks[taskId].tCurrentPower != 0)
            gTasks[taskId].tCurrentLevel = gSaveBlock2Ptr->oPowerLevels[gTasks[taskId].tCurrentPower];
        
        if (gSaveBlock2Ptr->oPowerOrbs > 10)
            gSaveBlock2Ptr->oPowerOrbs = 10;
            
        PrintMenuText(taskId);
        
        gMain.state = 4;
        break;
    case 4:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(CB2_OPowersMenuRunner);
        break;
    }
}

void UpdateOPowersTime(int minutes)
{
    u32 steps = gSaveBlock2Ptr->oPowerDailySteps;
    int targetMinutes;

    if (gSaveBlock2Ptr->oPowerOrbs >= 10)
    {
        gSaveBlock2Ptr->oPowerRegenTimer = 0;
        return;
    }

    if (steps <= 2000)
        targetMinutes = 4;
    else if (steps <= 3000)
        targetMinutes = 3;
    else if (steps <= 4000)
        targetMinutes = 2;
    else
        targetMinutes = 1;

    gSaveBlock2Ptr->oPowerRegenTimer += minutes;

    while (gSaveBlock2Ptr->oPowerRegenTimer >= targetMinutes && gSaveBlock2Ptr->oPowerOrbs < 10)
    {
        gSaveBlock2Ptr->oPowerRegenTimer -= targetMinutes;
        gSaveBlock2Ptr->oPowerOrbs++;
    }

    if (gSaveBlock2Ptr->oPowerOrbs >= 10)
        gSaveBlock2Ptr->oPowerRegenTimer = 0;
}
