#ifndef OPOWER_COSTS_H
#define OPOWER_COSTS_H

static const u8 sOPowerCosts[19][5] = {
    // 0: NONE
    {0, 0, 0, 0, 0},
    // 1: HATCHING
    {2, 3, 4, 8, 0},
    // 2: BARGAIN
    {2, 3, 4, 8, 0},
    // 3: PRIZE MONEY
    {4, 5, 6, 10, 0},
    // 4: EXP POINT
    {4, 5, 6, 10, 0},
    // 5: CAPTURE
    {4, 5, 6, 10, 0},
    // 6: ENCOUNTER
    {2, 3, 4, 0, 0},
    // 7: STEALTH
    {2, 3, 4, 0, 0},
    // 8: HP RESTORING
    {2, 3, 4, 0, 0},
    // 9: PP RESTORING
    {2, 3, 4, 0, 0},
    // 10: FULL RECOVERY (MAX only)
    {0, 0, 0, 0, 0},
    // 11: BEFRIENDING
    {2, 3, 4, 8, 0},
    // 12: ATTACK
    {3, 5, 8, 0, 0},
    // 13: DEFENSE
    {3, 5, 8, 0, 0},
    // 14: SP ATK
    {3, 5, 8, 0, 0},
    // 15: SP DEF
    {3, 5, 8, 0, 0},
    // 16: SPEED
    {3, 5, 8, 0, 0},
    // 17: CRITICAL
    {3, 5, 8, 0, 0},
    // 18: ACCURACY
    {3, 5, 8, 0, 0},
};

static const u32 sOPowerDurations[5] = {
    10800, // Lv 1 (3 min)
    10800, // Lv 2 (3 min)
    10800, // Lv 3 (3 min)
    28800, // Lv S (8 min)
    216000 // Lv MAX (60 min)
};

static const u8 sLevelNames[5][10] = {
    _("Lv. 1"),
    _("Lv. 2"),
    _("Lv. 3"),
    _("Lv. S"),
    _("MAX")
};

#endif
