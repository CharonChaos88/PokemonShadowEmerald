#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
typedef char s8;

enum Type { TYPE_NONE };
enum Move { MOVE_NONE };

struct PokemonSubstruct0
{
    u16 species:11; // 2047 species.
    enum Type teraType:5; // 30 types.
    u16 heldItem:10; // 1023 items.
    u16 altPalette:4; // Stores 0-15 safely for custom colors
    u16 unused_02:2;  // Leaves 2 bits remaining
    u32 experience:21;
    u32 nickname11:8; // 11th character of nickname.
    u32 unused_04:3;
    u8 ppBonuses;
    u8 friendship;
    u16 pokeball:6; // 63 balls.
    u16 nickname12:8; // 12th character of nickname.
    u16 unused_0A:2;
};

struct PokemonSubstruct1
{
    enum Move move1:11; // 2047 moves.
    u16 evolutionTracker1:5;
    enum Move move2:11; // 2047 moves.
    u16 evolutionTracker2:5;
    enum Move move3:11; // 2047 moves.
    u16 lastSampleHour:5;
    enum Move move4:11; // 2047 moves.
    u16 unused_06:3;
    u16 hyperTrainedHP:1;
    u16 hyperTrainedAttack:1;
    u8 pp1:7; // 127 PP.
    u8 hyperTrainedDefense:1;
    u8 pp2:7; // 127 PP.
    u8 hyperTrainedSpeed:1;
    u8 pp3:7; // 127 PP.
    u8 hyperTrainedSpAttack:1;
    u8 pp4:7; // 127 PP.
    u8 hyperTrainedSpDefense:1;
};

struct PokemonSubstruct2
{
    u8 hpEV;
    u8 attackEV;
    u8 defenseEV;
    u8 speedEV;
    u8 spAttackEV;
    u8 spDefenseEV;
    u8 cool;
    u8 beauty;
    u8 cute;
    u8 smart;
    u8 tough;
    u8 sheen;
};

struct PokemonSubstruct3
{
    u8 pokerus;
    u8 metLocation;
    u16 metLevel:7;
    u16 metGame:4;
    u16 dynamaxLevel:4;
    u16 otGender:1;
    u32 hpIV:5;
    u32 attackIV:5;
    u32 defenseIV:5;
    u32 speedIV:5;
    u32 spAttackIV:5;
    u32 spDefenseIV:5;
    u32 isEgg:1;
    u32 gigantamaxFactor:1;
    u32 coolRibbon:3;     // Stores the highest contest rank achieved in the Cool category.
    u32 beautyRibbon:3;   // Stores the highest contest rank achieved in the Beauty category.
    u32 cuteRibbon:3;     // Stores the highest contest rank achieved in the Cute category.
    u32 smartRibbon:3;    // Stores the highest contest rank achieved in the Smart category.
    u32 toughRibbon:3;    // Stores the highest contest rank achieved in the Tough category.
    u32 championRibbon:1; // Given when defeating the Champion. Because both RSE and FRLG use it, later generations don't specify from which region it comes from.
    u32 winningRibbon:1;  // Given at the Battle Tower's Level 50 challenge by winning a set of seven battles that extends the current streak to 56 or more.
    u32 victoryRibbon:1;  // Given at the Battle Tower's Level 100 challenge by winning a set of seven battles that extends the current streak to 56 or more.
    u32 artistRibbon:1;   // Given at the Contest Hall by winning a Master Rank contest with at least 800 points, and agreeing to have the Pokémon's portrait placed in the museum after being offered.
    u32 effortRibbon:1;   // Given at Slateport's market to Pokémon with maximum EVs.
    u32 badEggVirus:8;
    u32 isShadow:1;
    u32 abilityNum:2;
    u32 modernFatefulEncounter:1;
};

int main() {
    printf("sub0=%lu sub1=%lu sub2=%lu sub3=%lu\n", sizeof(struct PokemonSubstruct0), sizeof(struct PokemonSubstruct1), sizeof(struct PokemonSubstruct2), sizeof(struct PokemonSubstruct3));
    return 0;
}
