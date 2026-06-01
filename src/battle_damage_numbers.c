#include "global.h"
#include "battle_damage_numbers.h"
#include "battle.h"
#include "battle_anim.h"
#include "constants/battle_anim.h"

#include "data/battle_damage_numbers.h"

// Updated prototype to take the battler ID
static u8 GetDamageNumberPalette(u8 battler, s32 damage);

#define sDelay data[0] // wait time until sprite appears
#define sStayTimer data[1] // number of frames sprite stays onscreen
#define sState data[2] // state tracker for the little bounce the number does when it appears 
#define sTracker data[3] // timer for the state-based little bounce

static void SpriteCB_DamageNumber(struct Sprite *sprite)
{
	sprite->sTracker++;
	
	switch (sprite->sState)
	{
		case 0: // Sprites appear in sequence if there are multiple
			if (sprite->sDelay == 0)
			{
				sprite->invisible = FALSE;
				sprite->sState++;
				sprite->sTracker = 0;
			}
			else
				sprite->sDelay--;
			break;
		case 1: // Sprite bounces up a teeny bit 
			sprite->y--;
			if (sprite->sTracker == 4)
			{
				sprite->sTracker = 0;
				sprite->sState++;
			}
			break;
		case 2:
			sprite->y++; // Sprite slides back down to a resting position
			if (sprite->sTracker == 2)
			{
				sprite->sTracker = 0;
				sprite->sState++;
			}
			break;
		case 3: // Sprite slides down again when it's about to disappear
			if (sprite->sStayTimer < 4)
				sprite->y++;
			break;
		default:
			sprite->sTracker = 0;
	}
	
	if (sprite->invisible == FALSE)
    {
        sprite->sStayTimer--;
        if (sprite->sStayTimer == 0)
        {   // <-- ADD BRACE HERE
            DestroySprite(sprite);
            FreeSpritePaletteByTag(PALETTE_TAG_DAMAGE_NUMS);
        }   // <-- ADD BRACE HERE
    }
}
static u32 GetDamageDigit(u32 damage, u32 digit) 
{
	u32 result = 0;
	while (damage >= digit)
	{
		result++;
		damage -= digit;
	}
	
	return result;
}

static void CreateDamageNumberSprite(u32 number, u32 numPrinted, u8 battler, u8 palette)
{
    u32 spriteId;

	// ADD THIS: Increment the palette reference count for this specific sprite
    // LoadSpritePalette(&sDamageNumSpritePalette_Normal);
    
    spriteId = CreateSprite(&sDamageNumberSpriteTemplate, GetBattlerSpriteCoord(battler, BATTLER_COORD_X) + (7 * numPrinted),
                            GetBattlerSpriteCoord(battler, BATTLER_COORD_Y) + 2, 0);
    
    // THE CRITICAL FIX: Prevent memory corruption if the GBA runs out of sprite slots!
    if (spriteId >= MAX_SPRITES)
    {
        // ADD THIS: Free the palette immediately to prevent a leak if creation fails
        FreeSpritePaletteByTag(PALETTE_TAG_DAMAGE_NUMS);
        return;
    }

    StartSpriteAnim(&gSprites[spriteId], number + (10 * palette));
    gSprites[spriteId].sDelay = DAMAGE_NUMBER_DELAY * numPrinted;
    gSprites[spriteId].sStayTimer = DAMAGE_NUMBER_TIME;
    gSprites[spriteId].invisible = TRUE;
}

// Updated function to check the specific battler's stats inside gBattleStruct
static u8 GetDamageNumberPalette(u8 battler, s32 damage)
{
	if (damage < 0)
	{
		return 1; // healing - green
	}
	// Only apply Effectiveness colors if this is an actual attack (moveDamage)
	else if (damage == gBattleStruct->moveDamage[battler]) 
	{
		if (DN_CONFIG_EFFECTIVENESS_PALETTE && (gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_SUPER_EFFECTIVE))
			return 2; // super effective - orange	
			
		if (DN_CONFIG_EFFECTIVENESS_PALETTE && (gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_NOT_VERY_EFFECTIVE))
			return 3; // not very effective - gray	
	}
	
	return 0; // default - white (used for normal attacks AND all passive damage/hazards)
}


void ShowDamageNumbers(u8 battler, s32 damage)
{
	u8 palette;
	u32 spriteNumber;
	u32 numPrinted = 0;
	
	palette = GetDamageNumberPalette(battler, damage); 
	
    // ADD THIS BLOCK: Load the correct GBA Palette into memory
    switch (palette)
    {
        case 2: // Super Effective
            LoadSpritePalette(&sDamageNumSpritePalette_SE);
            break;
        case 3: // Not Very Effective
            LoadSpritePalette(&sDamageNumSpritePalette_NVE);
            break;
        case 1: // Healing
            // Use your healing palette if you have one, or fallback to normal
            LoadSpritePalette(&sDamageNumSpritePalette_Normal); 
            break;
        default: // Normal
            LoadSpritePalette(&sDamageNumSpritePalette_Normal);
            break;
    }
	
	// Cap damage safely for both positive (damage) and negative (healing)
	if (damage > 9999) damage = 9999;
	if (damage < -9999) damage = -9999;
	
	if (damage < 0)
		damage *= -1; // healing is shown as a positive value with a green palette
	
	// thousands place
	spriteNumber = GetDamageDigit(damage, 1000);
	damage -= spriteNumber * 1000;
	if (spriteNumber > 0)
	{
		CreateDamageNumberSprite(spriteNumber, numPrinted, battler, palette);
		numPrinted++;
	}
	
	// hundreds place
	spriteNumber = GetDamageDigit(damage, 100);
	damage -= spriteNumber * 100;
	if (spriteNumber > 0 || numPrinted != 0)
	{
		CreateDamageNumberSprite(spriteNumber, numPrinted, battler, palette);
		numPrinted++;
	}
	
	// tens place
	spriteNumber = GetDamageDigit(damage, 10);
	damage -= spriteNumber * 10;
	if (spriteNumber > 0 || numPrinted != 0)
	{
		CreateDamageNumberSprite(spriteNumber, numPrinted, battler, palette);
		numPrinted++;
	}
	
	// ones place
	spriteNumber = damage;
	CreateDamageNumberSprite(spriteNumber, numPrinted, battler, palette);
}

#undef sDelay
#undef sStayTimer
#undef sState
#undef sTracker
