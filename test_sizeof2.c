#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
typedef char s8;

#define PLAYER_NAME_LENGTH 7
#define POKEMON_NAME_LENGTH 10

enum Type { TYPE_NONE };
enum Move { MOVE_NONE };

struct PokemonSubstruct0 { u32 d[3]; };
struct PokemonSubstruct1 { u32 d[3]; };
struct PokemonSubstruct2 { u32 d[3]; };
struct PokemonSubstruct3 { u32 d[3]; };

#define NUM_SUBSTRUCT_BYTES 12

union PokemonSubstruct
{
    struct PokemonSubstruct0 type0;
    struct PokemonSubstruct1 type1;
    struct PokemonSubstruct2 type2;
    struct PokemonSubstruct3 type3;
    u16 raw[NUM_SUBSTRUCT_BYTES / 2]; // /2 because it's u16, not u8
};

struct BoxPokemon
{
    u32 personality;
    u32 otId;
    u8 nickname[10];
    u8 language:3;
    u8 hiddenNatureModifier:5; // 31 natures.
    u8 isBadEgg:1;
    u8 hasSpecies:1;
    u8 isEgg:1;
    u8 blockBoxRS:1; // Unused, but Pokémon Box Ruby & Sapphire will refuse to deposit a Pokémon with this flag set.
    u8 daysSinceFormChange:3; // 7 days.
    u8 unused_13:1;
    u8 otName[PLAYER_NAME_LENGTH];
    u8 markings:4;
    u8 compressedStatus:4;
    u16 checksum;
    u16 hpLost:14; // 16383 HP.
    u16 shinyModifier:1;
    u16 unused_1E:1;

    union
    {
        u32 raw[(NUM_SUBSTRUCT_BYTES * 4) / 4]; // *4 because there are 4 substructs, /4 because it's u32, not u8
        union PokemonSubstruct substructs[4];
    } secure;
};

struct Pokemon
{
    struct BoxPokemon box;
    u32 status;
    u8 level;
    u8 mail;
    u16 hp;
    u16 maxHP;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 spAttack;
    u16 spDefense;
};

int main() {
    printf("Box=%lu Pokemon=%lu\n", sizeof(struct BoxPokemon), sizeof(struct Pokemon));
    return 0;
}
