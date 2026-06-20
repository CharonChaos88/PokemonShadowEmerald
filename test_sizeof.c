#include <stdio.h>
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

    u32 coolRibbon:3;     
    u32 beautyRibbon:3;   
    u32 cuteRibbon:3;     
    u32 smartRibbon:3;    
    u32 toughRibbon:3;    
    u32 championRibbon:1; 
    u32 winningRibbon:1;  
    u32 victoryRibbon:1;  
    u32 artistRibbon:1;   
    u32 effortRibbon:1;   
    u32 badEggVirus:8;
    u32 isShadow:1;
    u32 abilityNum:2;

    u32 modernFatefulEncounter:1;
};

int main() {
    printf("%zu\n", sizeof(struct PokemonSubstruct3));
    return 0;
}
