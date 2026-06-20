#ifndef GUARD_CRAFTING_RECIPES_H
#define GUARD_CRAFTING_RECIPES_H

#include "craft_logic.h"
#include "constants/flags.h"

struct CraftRecipe
{
    u16 pattern[CRAFT_ROWS][CRAFT_COLS];
    u16 resultQuantity;
    u16 unlockFlag; // FLAG_NONE for always unlocked
};

struct CraftRecipeList
{
    const struct CraftRecipe *recipes;
    u8 count;
};

static const struct CraftRecipeList gCraftRecipes[ITEMS_COUNT] =
{
    [ITEM_ANTIDOTE] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern =
                {
                    { ITEM_POTION },
                    { ITEM_PECHA_BERRY },
                },
                .resultQuantity = 3,
                .unlockFlag = 0,
            },
        },
        .count = 1,
    },
    [ITEM_POTION] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern =
                {
                    { ITEM_ORAN_BERRY, },
                    { ITEM_FRESH_WATER, },
                },
                .resultQuantity = 1,
                .unlockFlag = 0,
            },
        },
        .count = 1,
    },
    [ITEM_SUPER_POTION] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern =
                {
                    { ITEM_POTION, ITEM_POTION, ITEM_POTION },
                },
                .resultQuantity = 2,
                .unlockFlag = FLAG_ITEM_ROUTE_102_POTION,
            },
            {
                .pattern =
                {
                    { ITEM_ORAN_BERRY, ITEM_ORAN_BERRY },
                    { ITEM_FRESH_WATER },
                },
                .resultQuantity = 2,
                .unlockFlag = 0,
            },
        },
        .count = 2,
    },
    [ITEM_PARALYZE_HEAL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_POTION }, { ITEM_CHERI_BERRY } },
                .resultQuantity = 3,
            },
        },
        .count = 1,
    },
    [ITEM_AWAKENING] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_POTION }, { ITEM_CHESTO_BERRY } },
                .resultQuantity = 3,
            },
        },
        .count = 1,
    },
    [ITEM_BURN_HEAL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_POTION }, { ITEM_RAWST_BERRY } },
                .resultQuantity = 3,
            },
        },
        .count = 1,
    },
    [ITEM_ICE_HEAL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_POTION }, { ITEM_ASPEAR_BERRY } },
                .resultQuantity = 3,
            },
        },
        .count = 1,
    },
    [ITEM_FULL_HEAL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_LUM_BERRY }, { ITEM_FRESH_WATER } },
                .resultQuantity = 2,
            },
        },
        .count = 1,
    },
    [ITEM_HYPER_POTION] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_SUPER_POTION, ITEM_SUPER_POTION, ITEM_SUPER_POTION } },
                .resultQuantity = 2,
            },
        },
        .count = 1,
    },
    [ITEM_MAX_POTION] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_HYPER_POTION, ITEM_HYPER_POTION, ITEM_HYPER_POTION } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_FULL_RESTORE] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_MAX_POTION }, { ITEM_FULL_HEAL } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_REVIVE] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_REVIVAL_HERB }, { ITEM_FRESH_WATER } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_MAX_REVIVE] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_REVIVE }, { ITEM_FULL_RESTORE } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_ETHER] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_LEPPA_BERRY }, { ITEM_FRESH_WATER } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_MAX_ETHER] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_ETHER, ITEM_ETHER, ITEM_ETHER } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_ELIXIR] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_ETHER }, { ITEM_ETHER } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_MAX_ELIXIR] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_ELIXIR, ITEM_ELIXIR, ITEM_ELIXIR } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_LEVEL_BALL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_RED_APRICORN } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_LURE_BALL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_BLUE_APRICORN } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_MOON_BALL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_YELLOW_APRICORN } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_FRIEND_BALL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_GREEN_APRICORN } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_LOVE_BALL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_PINK_APRICORN } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_FAST_BALL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_WHITE_APRICORN } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_HEAVY_BALL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_BLACK_APRICORN } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_HEAL_BALL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_POKE_BALL }, { ITEM_POTION } },
                .resultQuantity = 1,
            },
        },
        .count = 1,
    },
    [ITEM_GREAT_BALL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_POKE_BALL, ITEM_POKE_BALL, ITEM_POKE_BALL } },
                .resultQuantity = 2,
            },
        },
        .count = 1,
    },
    [ITEM_ULTRA_BALL] =
    {
        .recipes = (const struct CraftRecipe[])
        {
            {
                .pattern = { { ITEM_GREAT_BALL, ITEM_GREAT_BALL, ITEM_GREAT_BALL } },
                .resultQuantity = 2,
            },
        },
        .count = 1,
    },
};

static const u16 gCraftRecipeCount = ARRAY_COUNT(gCraftRecipes);

#endif // GUARD_CRAFTING_RECIPES_H
