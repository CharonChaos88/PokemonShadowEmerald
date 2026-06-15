#include "global.h"
#include "pokemon.h"
#include "strings.h"
#include "random.h"
#include "text.h"
#include "event_data.h"
#include "region_map.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "data/text/wonder_trade_OT_names.h"
#include "constants/region_map_sections.h"
#include "item.h"
#include "constants/item.h"
#include "constants/hold_effects.h"
#include "mail.h"
#include "constants/pokemon.h"
#include "party_menu.h"
#include "field_weather.h"
#include "constants/weather.h"
#include "battle.h"
#include "string_util.h"
#include "daycare.h"
#include "wonder_trade.h"
#include "pokemon_storage_system.h"
#include "constants/party_menu.h"

// This file's functions.
static u16 PickRandomSpecies(void);
static u8 GetWonderTradeOT(u8 *name);
static u16 GetWonderTradeEvolutionTargetSpecies(struct Pokemon *mon);
static u32 GetEvolutionSpecies(u16 speciesId);
static bool32 IsSpeciesFamilyMegaEvolutionCompatible(u16 species, u16 heldStone);
static u16 GetValidHeldItemForSpecies(u16 speciesId);
static u8 GetWonderTradeFamilyMinLevel(u16 species);
static bool8 CanReceiveLegendaries(void);

struct WonderTrade {
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 species;
    u8 ivs[NUM_STATS];
    u8 abilityNum;
    u32 otId;
    u8 conditions[CONTEST_CATEGORIES_COUNT];
    u32 personality;
    u16 heldItem;
    u8 mailNum;
    u8 otName[TRAINER_NAME_LENGTH + 1];
    u8 otGender;
    u8 sheen;
    u16 requestedSpecies;
};

// NEW: The curated pool of allowed Legendaries and Mythicals
static const u16 sLegendaryWonderTradePool[] = 
{
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_MEWTWO,
    SPECIES_MEW,
    SPECIES_RAIKOU,
    SPECIES_ENTEI,
    SPECIES_SUICUNE,
    SPECIES_LUGIA,
    SPECIES_HO_OH,
    SPECIES_CELEBI,
    SPECIES_REGIROCK,
    SPECIES_REGICE,
    SPECIES_REGISTEEL,
    SPECIES_LATIAS,
    SPECIES_LATIOS,
    SPECIES_KYOGRE,
    SPECIES_GROUDON,
    SPECIES_RAYQUAZA,
    SPECIES_JIRACHI,
    SPECIES_DEOXYS,
    SPECIES_UXIE,
    SPECIES_MESPRIT,
    SPECIES_AZELF,
    SPECIES_DIALGA,
    SPECIES_PALKIA,
    SPECIES_HEATRAN,
    SPECIES_REGIGIGAS,
    SPECIES_GIRATINA,
    SPECIES_CRESSELIA,
    SPECIES_PHIONE,
    SPECIES_MANAPHY,
    SPECIES_DARKRAI,
    SPECIES_SHAYMIN,
    SPECIES_ARCEUS,
    SPECIES_VICTINI,
    SPECIES_COBALION,
    SPECIES_TERRAKION,
    SPECIES_VIRIZION,
    SPECIES_TORNADUS,
    SPECIES_THUNDURUS,
    SPECIES_RESHIRAM,
    SPECIES_ZEKROM,
    SPECIES_LANDORUS,
    SPECIES_KYUREM,
    SPECIES_KELDEO,
    SPECIES_MELOETTA,
    SPECIES_GENESECT,
    SPECIES_XERNEAS,
    SPECIES_YVELTAL,
    SPECIES_ZYGARDE,
    SPECIES_DIANCIE,
    SPECIES_HOOPA,
    SPECIES_VOLCANION,
    SPECIES_TYPE_NULL,
    SPECIES_SILVALLY,
    SPECIES_TAPU_KOKO,
    SPECIES_TAPU_LELE,
    SPECIES_TAPU_BULU,
    SPECIES_TAPU_FINI,
    SPECIES_COSMOG,
    SPECIES_COSMOEM,
    SPECIES_SOLGALEO,
    SPECIES_LUNALA,
    SPECIES_NIHILEGO,
    SPECIES_BUZZWOLE,
    SPECIES_PHEROMOSA,
    SPECIES_XURKITREE,
    SPECIES_CELESTEELA,
    SPECIES_KARTANA,
    SPECIES_GUZZLORD,
    SPECIES_NECROZMA,
    SPECIES_MAGEARNA,
    SPECIES_MARSHADOW,
    SPECIES_POIPOLE,
    SPECIES_NAGANADEL,
    SPECIES_STAKATAKA,
    SPECIES_BLACEPHALON,
    SPECIES_ZERAORA,
    SPECIES_MELTAN,
    SPECIES_MELMETAL,
    SPECIES_ARTICUNO_GALAR,
    SPECIES_ZAPDOS_GALAR,
    SPECIES_MOLTRES_GALAR,
    SPECIES_ZACIAN,
    SPECIES_ZAMAZENTA,
    SPECIES_ETERNATUS,
    SPECIES_KUBFU,
    SPECIES_URSHIFU,
    SPECIES_ZARUDE,
    SPECIES_REGIELEKI,
    SPECIES_REGIDRAGO,
    SPECIES_GLASTRIER,
    SPECIES_SPECTRIER,
    SPECIES_CALYREX,
    SPECIES_ENAMORUS,
    SPECIES_WO_CHIEN,
    SPECIES_CHIEN_PAO,
    SPECIES_TING_LU,
    SPECIES_CHI_YU,
    SPECIES_ROARING_MOON,
    SPECIES_IRON_VALIANT,
    SPECIES_KORAIDON,
    SPECIES_MIRAIDON,
    SPECIES_OKIDOGI,
    SPECIES_MUNKIDORI,
    SPECIES_FEZANDIPITI,
    SPECIES_OGERPON,
    SPECIES_TERAPAGOS,
    SPECIES_PECHARUNT,
    SPECIES_GREAT_TUSK,
    SPECIES_SCREAM_TAIL,
    SPECIES_BRUTE_BONNET,
    SPECIES_FLUTTER_MANE,
    SPECIES_SLITHER_WING,
    SPECIES_SANDY_SHOCKS,
    SPECIES_IRON_TREADS,
    SPECIES_IRON_BUNDLE,
    SPECIES_IRON_HANDS,
    SPECIES_IRON_JUGULIS,
    SPECIES_IRON_MOTH,
    SPECIES_IRON_THORNS,
    SPECIES_GOUGING_FIRE,
    SPECIES_RAGING_BOLT,
    SPECIES_IRON_BOULDER,
    SPECIES_IRON_CROWN,
    SPECIES_WALKING_WAKE,
    SPECIES_IRON_LEAVES,
};

static const u16 sWonderTradePokeballs[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_PREMIER_BALL,
    ITEM_REPEAT_BALL,
    ITEM_TIMER_BALL,
    ITEM_NEST_BALL,
    ITEM_NET_BALL,
    ITEM_DIVE_BALL,
    ITEM_LUXURY_BALL,
    ITEM_SAFARI_BALL,
    ITEM_HEAL_BALL,
    ITEM_QUICK_BALL,
    ITEM_DUSK_BALL,
    ITEM_CHERISH_BALL,
    ITEM_FAST_BALL,
    ITEM_LEVEL_BALL,
    ITEM_LURE_BALL,
    ITEM_HEAVY_BALL,
    ITEM_LOVE_BALL,
    ITEM_FRIEND_BALL,
    ITEM_MOON_BALL,
    ITEM_SPORT_BALL,
    ITEM_DREAM_BALL,
    ITEM_BEAST_BALL,
};

static const u16 sIsValidSpecies[] = {
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PIDGEY,
    SPECIES_RATTATA,
    SPECIES_SPEAROW,
    SPECIES_EKANS,
    SPECIES_SANDSHREW,
    SPECIES_NIDORAN_F,
    SPECIES_NIDORAN_M,
    SPECIES_VULPIX,
    SPECIES_ZUBAT,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_VENONAT,
    SPECIES_DIGLETT,
    SPECIES_MEOWTH,
    SPECIES_PSYDUCK,
    SPECIES_MANKEY,
    SPECIES_GROWLITHE,
    SPECIES_POLIWAG,
    SPECIES_ABRA,
    SPECIES_MACHOP,
    SPECIES_BELLSPROUT,
    SPECIES_TENTACOOL,
    SPECIES_GEODUDE,
    SPECIES_PONYTA,
    SPECIES_SLOWPOKE,
    SPECIES_MAGNEMITE,
    SPECIES_FARFETCHD,
    SPECIES_DODUO,
    SPECIES_SEEL,
    SPECIES_GRIMER,
    SPECIES_SHELLDER,
    SPECIES_GASTLY,
    SPECIES_ONIX,
    SPECIES_DROWZEE,
    SPECIES_KRABBY,
    SPECIES_VOLTORB,
    SPECIES_EXEGGCUTE,
    SPECIES_CUBONE,
    SPECIES_LICKITUNG,
    SPECIES_KOFFING,
    SPECIES_RHYHORN,
    SPECIES_CHANSEY,
    SPECIES_TANGELA,
    SPECIES_KANGASKHAN,
    SPECIES_HORSEA,
    SPECIES_GOLDEEN,
    SPECIES_STARYU,
    SPECIES_SCYTHER,
    SPECIES_PINSIR,
    SPECIES_TAUROS,
    SPECIES_MAGIKARP,
    SPECIES_LAPRAS,
    SPECIES_DITTO,
    SPECIES_EEVEE,
    SPECIES_PORYGON,
    SPECIES_OMANYTE,
    SPECIES_KABUTO,
    SPECIES_AERODACTYL,
    SPECIES_DRATINI,
    SPECIES_CHIKORITA,
    SPECIES_TOTODILE,
    SPECIES_SENTRET,
    SPECIES_HOOTHOOT,
    SPECIES_LEDYBA,
    SPECIES_SPINARAK,
    SPECIES_CHINCHOU,
    SPECIES_PICHU,
    SPECIES_CLEFFA,
    SPECIES_IGGLYBUFF,
    SPECIES_TOGEPI,
    SPECIES_NATU,
    SPECIES_MAREEP,
    SPECIES_SUDOWOODO,
    SPECIES_HOPPIP,
    SPECIES_AIPOM,
    SPECIES_SUNKERN,
    SPECIES_YANMA,
    SPECIES_WOOPER,
    SPECIES_MURKROW,
    SPECIES_MISDREAVUS,
    SPECIES_UNOWN,
    SPECIES_GIRAFARIG,
    SPECIES_PINECO,
    SPECIES_DUNSPARCE,
    SPECIES_GLIGAR,
    SPECIES_SNUBBULL,
    SPECIES_QWILFISH,
    SPECIES_SHUCKLE,
    SPECIES_HERACROSS,
    SPECIES_SNEASEL,
    SPECIES_TEDDIURSA,
    SPECIES_SLUGMA,
    SPECIES_SWINUB,
    SPECIES_CORSOLA,
    SPECIES_REMORAID,
    SPECIES_DELIBIRD,
    SPECIES_MANTINE,
    SPECIES_SKARMORY,
    SPECIES_HOUNDOUR,
    SPECIES_PHANPY,
    SPECIES_STANTLER,
    SPECIES_SMEARGLE,
    SPECIES_TYROGUE,
    SPECIES_SMOOCHUM,
    SPECIES_ELEKID,
    SPECIES_MAGBY,
    SPECIES_MILTANK,
    SPECIES_LARVITAR,
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_POOCHYENA,
    SPECIES_ZIGZAGOON,
    SPECIES_WURMPLE,
    SPECIES_LOTAD,
    SPECIES_SEEDOT,
    SPECIES_NINCADA,
    SPECIES_TAILLOW,
    SPECIES_SHROOMISH,
    SPECIES_SPINDA,
    SPECIES_WINGULL,
    SPECIES_SURSKIT,
    SPECIES_WAILMER,
    SPECIES_SKITTY,
    SPECIES_KECLEON,
    SPECIES_BALTOY,
    SPECIES_NOSEPASS,
    SPECIES_TORKOAL,
    SPECIES_SABLEYE,
    SPECIES_BARBOACH,
    SPECIES_LUVDISC,
    SPECIES_CORPHISH,
    SPECIES_FEEBAS,
    SPECIES_CARVANHA,
    SPECIES_TRAPINCH,
    SPECIES_MAKUHITA,
    SPECIES_ELECTRIKE,
    SPECIES_NUMEL,
    SPECIES_SPHEAL,
    SPECIES_CACNEA,
    SPECIES_SNORUNT,
    SPECIES_LUNATONE,
    SPECIES_SOLROCK,
    SPECIES_AZURILL,
    SPECIES_SPOINK,
    SPECIES_PLUSLE,
    SPECIES_MINUN,
    SPECIES_MAWILE,
    SPECIES_MEDITITE,
    SPECIES_SWABLU,
    SPECIES_WYNAUT,
    SPECIES_DUSKULL,
    SPECIES_ROSELIA,
    SPECIES_SLAKOTH,
    SPECIES_GULPIN,
    SPECIES_TROPIUS,
    SPECIES_WHISMUR,
    SPECIES_CLAMPERL,
    SPECIES_ABSOL,
    SPECIES_SHUPPET,
    SPECIES_SEVIPER,
    SPECIES_ZANGOOSE,
    SPECIES_RELICANTH,
    SPECIES_ARON,
    SPECIES_CASTFORM,
    SPECIES_VOLBEAT,
    SPECIES_ILLUMISE,
    SPECIES_LILEEP,
    SPECIES_ANORITH,
    SPECIES_RALTS,
    SPECIES_BAGON,
    SPECIES_BELDUM,
    SPECIES_CHIMECHO,
    SPECIES_TURTWIG,
    SPECIES_CHIMCHAR,
    SPECIES_PIPLUP,
    SPECIES_STARLY,
    SPECIES_BIDOOF,
    SPECIES_KRICKETOT,
    SPECIES_SHINX,
    SPECIES_BUDEW,
    SPECIES_CRANIDOS,
    SPECIES_SHIELDON,
    SPECIES_BURMY,
    SPECIES_COMBEE,
    SPECIES_PACHIRISU,
    SPECIES_BUIZEL,
    SPECIES_CHERUBI,
    SPECIES_SHELLOS,
    SPECIES_DRIFLOON,
    SPECIES_BUNEARY,
    SPECIES_GLAMEOW,
    SPECIES_CHINGLING,
    SPECIES_STUNKY,
    SPECIES_BRONZOR,
    SPECIES_BONSLY,
    SPECIES_MIME_JR,
    SPECIES_HAPPINY,
    SPECIES_CHATOT,
    SPECIES_SPIRITOMB,
    SPECIES_GIBLE,
    SPECIES_MUNCHLAX,
    SPECIES_RIOLU,
    SPECIES_HIPPOPOTAS,
    SPECIES_SKORUPI,
    SPECIES_CROAGUNK,
    SPECIES_CARNIVINE,
    SPECIES_FINNEON,
    SPECIES_MANTYKE,
    SPECIES_SNOVER,
    SPECIES_ROTOM,
    SPECIES_SNIVY,
    SPECIES_TEPIG,
    SPECIES_OSHAWOTT,
    SPECIES_PATRAT,
    SPECIES_LILLIPUP,
    SPECIES_PURRLOIN,
    SPECIES_PANSAGE,
    SPECIES_PANSEAR,
    SPECIES_PANPOUR,
    SPECIES_MUNNA,
    SPECIES_PIDOVE,
    SPECIES_BLITZLE,
    SPECIES_ROGGENROLA,
    SPECIES_WOOBAT,
    SPECIES_DRILBUR,
    SPECIES_AUDINO,
    SPECIES_TIMBURR,
    SPECIES_TYMPOLE,
    SPECIES_THROH,
    SPECIES_SAWK,
    SPECIES_SEWADDLE,
    SPECIES_VENIPEDE,
    SPECIES_COTTONEE,
    SPECIES_PETILIL,
    SPECIES_BASCULIN,
    SPECIES_SANDILE,
    SPECIES_DARUMAKA,
    SPECIES_MARACTUS,
    SPECIES_DWEBBLE,
    SPECIES_SCRAGGY,
    SPECIES_SIGILYPH,
    SPECIES_YAMASK,
    SPECIES_TIRTOUGA,
    SPECIES_ARCHEN,
    SPECIES_TRUBBISH,
    SPECIES_ZORUA,
    SPECIES_MINCCINO,
    SPECIES_GOTHITA,
    SPECIES_SOLOSIS,
    SPECIES_DUCKLETT,
    SPECIES_VANILLITE,
    SPECIES_DEERLING,
    SPECIES_EMOLGA,
    SPECIES_KARRABLAST,
    SPECIES_FOONGUS,
    SPECIES_FRILLISH,
    SPECIES_ALOMOMOLA,
    SPECIES_JOLTIK,
    SPECIES_FERROSEED,
    SPECIES_KLINK,
    SPECIES_TYNAMO,
    SPECIES_ELGYEM,
    SPECIES_LITWICK,
    SPECIES_AXEW,
    SPECIES_CUBCHOO,
    SPECIES_CRYOGONAL,
    SPECIES_SHELMET,
    SPECIES_STUNFISK,
    SPECIES_MIENFOO,
    SPECIES_DRUDDIGON,
    SPECIES_GOLETT,
    SPECIES_PAWNIARD,
    SPECIES_BOUFFALANT,
    SPECIES_RUFFLET,
    SPECIES_VULLABY,
    SPECIES_HEATMOR,
    SPECIES_DURANT,
    SPECIES_DEINO,
    SPECIES_LARVESTA,
    SPECIES_CHESPIN,
    SPECIES_FENNEKIN,
    SPECIES_FROAKIE,
    SPECIES_BUNNELBY,
    SPECIES_FLETCHLING,
    SPECIES_SCATTERBUG,
    SPECIES_LITLEO,
    SPECIES_FLABEBE,
    SPECIES_SKIDDO,
    SPECIES_PANCHAM,
    SPECIES_FURFROU,
    SPECIES_ESPURR,
    SPECIES_HONEDGE,
    SPECIES_SPRITZEE,
    SPECIES_SWIRLIX,
    SPECIES_INKAY,
    SPECIES_BINACLE,
    SPECIES_SKRELP,
    SPECIES_CLAUNCHER,
    SPECIES_HELIOPTILE,
    SPECIES_TYRUNT,
    SPECIES_AMAURA,
    SPECIES_HAWLUCHA,
    SPECIES_DEDENNE,
    SPECIES_CARBINK,
    SPECIES_GOOMY,
    SPECIES_KLEFKI,
    SPECIES_PHANTUMP,
    SPECIES_PUMPKABOO,
    SPECIES_BERGMITE,
    SPECIES_NOIBAT,
    SPECIES_ROWLET,
    SPECIES_LITTEN,
    SPECIES_POPPLIO,
    SPECIES_PIKIPEK,
    SPECIES_YUNGOOS,
    SPECIES_GRUBBIN,
    SPECIES_CRABRAWLER,
    SPECIES_ORICORIO,
    SPECIES_CUTIEFLY,
    SPECIES_ROCKRUFF,
    SPECIES_WISHIWASHI,
    SPECIES_MAREANIE,
    SPECIES_MUDBRAY,
    SPECIES_DEWPIDER,
    SPECIES_FOMANTIS,
    SPECIES_MORELULL,
    SPECIES_SALANDIT,
    SPECIES_STUFFUL,
    SPECIES_BOUNSWEET,
    SPECIES_COMFEY,
    SPECIES_PASSIMIAN,
    SPECIES_WIMPOD,
    SPECIES_SANDYGAST,
    SPECIES_PYUKUMUKU,
    SPECIES_MINIOR,
    SPECIES_KOMALA,
    SPECIES_TURTONATOR,
    SPECIES_TOGEDEMARU,
    SPECIES_MIMIKYU,
    SPECIES_BRUXISH,
    SPECIES_DRAMPA,
    SPECIES_DHELMISE,
    SPECIES_JANGMO_O,
    SPECIES_GROOKEY,
    SPECIES_SCORBUNNY,
    SPECIES_SOBBLE,
    SPECIES_SKWOVET,
    SPECIES_ROOKIDEE,
    SPECIES_BLIPBUG,
    SPECIES_NICKIT,
    SPECIES_GOSSIFLEUR,
    SPECIES_WOOLOO,
    SPECIES_CHEWTLE,
    SPECIES_YAMPER,
    SPECIES_ROLYCOLY,
    SPECIES_APPLIN,
    SPECIES_SILICOBRA,
    SPECIES_CRAMORANT,
    SPECIES_ARROKUDA,
    SPECIES_TOXEL,
    SPECIES_SIZZLIPEDE,
    SPECIES_CLOBBOPUS,
    SPECIES_SINISTEA,
    SPECIES_HATENNA,
    SPECIES_IMPIDIMP,
    SPECIES_MILCERY,
    SPECIES_FALINKS,
    SPECIES_PINCURCHIN,
    SPECIES_SNOM,
    SPECIES_EISCUE,
    SPECIES_INDEEDEE,
    SPECIES_MORPEKO,
    SPECIES_CUFANT,
    SPECIES_DRACOZOLT,
    SPECIES_ARCTOZOLT,
    SPECIES_DRACOVISH,
    SPECIES_ARCTOVISH,
    SPECIES_DURALUDON,
    SPECIES_DREEPY,
    SPECIES_RATTATA_ALOLA,
    SPECIES_SANDSHREW_ALOLA,
    SPECIES_VULPIX_ALOLA,
    SPECIES_DIGLETT_ALOLA,
    SPECIES_MEOWTH_ALOLA,
    SPECIES_GEODUDE_ALOLA,
    SPECIES_GRIMER_ALOLA,
    SPECIES_MEOWTH_GALAR,
    SPECIES_PONYTA_GALAR,
    SPECIES_SLOWPOKE_GALAR,
    SPECIES_FARFETCHD_GALAR,
    SPECIES_MR_MIME_GALAR,
    SPECIES_CORSOLA_GALAR,
    SPECIES_ZIGZAGOON_GALAR,
    SPECIES_DARUMAKA_GALAR,
    SPECIES_YAMASK_GALAR,
    SPECIES_STUNFISK_GALAR,
    SPECIES_GROWLITHE_HISUI,
    SPECIES_VOLTORB_HISUI,
    SPECIES_QWILFISH_HISUI,
    SPECIES_SNEASEL_HISUI,
    SPECIES_ZORUA_HISUI,
    SPECIES_BURMY_SANDY,
    SPECIES_BURMY_TRASH,
    SPECIES_SHELLOS_EAST,
    SPECIES_BASCULIN_BLUE_STRIPED,
    SPECIES_BASCULIN_WHITE_STRIPED,
    SPECIES_DEERLING_SUMMER,
    SPECIES_DEERLING_AUTUMN,
    SPECIES_DEERLING_WINTER,
    SPECIES_FLABEBE_YELLOW,
    SPECIES_FLABEBE_ORANGE,
    SPECIES_FLABEBE_BLUE,
    SPECIES_FLABEBE_WHITE,
    SPECIES_MEOWSTIC_F,
    SPECIES_PUMPKABOO_SMALL,
    SPECIES_PUMPKABOO_LARGE,
    SPECIES_PUMPKABOO_SUPER,
    SPECIES_ORICORIO_POM_POM,
    SPECIES_ORICORIO_PAU,
    SPECIES_ORICORIO_SENSU,
    SPECIES_ROCKRUFF_OWN_TEMPO,
    SPECIES_MINIOR_METEOR_ORANGE,
    SPECIES_MINIOR_METEOR_YELLOW,
    SPECIES_MINIOR_METEOR_GREEN,
    SPECIES_MINIOR_METEOR_BLUE,
    SPECIES_MINIOR_METEOR_INDIGO,
    SPECIES_MINIOR_METEOR_VIOLET,
    SPECIES_SINISTEA_ANTIQUE,
    SPECIES_INDEEDEE,
    SPECIES_SPRIGATITO,
    SPECIES_FUECOCO,
    SPECIES_QUAXLY,
    SPECIES_LECHONK,
    SPECIES_TAROUNTULA,
    SPECIES_NYMBLE,
    SPECIES_PAWMI,
    SPECIES_TANDEMAUS,
    SPECIES_FIDOUGH,
    SPECIES_SMOLIV,
    SPECIES_SQUAWKABILLY_GREEN,
    SPECIES_SQUAWKABILLY_BLUE,
    SPECIES_SQUAWKABILLY_YELLOW,
    SPECIES_SQUAWKABILLY_WHITE,
    SPECIES_NACLI,
    SPECIES_CHARCADET,
    SPECIES_TADBULB,
    SPECIES_WATTREL,
    SPECIES_MASCHIFF,
    SPECIES_SHROODLE,
    SPECIES_BRAMBLIN,
    SPECIES_TOEDSCOOL,
    SPECIES_KLAWF,
    SPECIES_CAPSAKID,
    SPECIES_RELLOR,
    SPECIES_FLITTLE,
    SPECIES_TINKATINK,
    SPECIES_WIGLETT,
    SPECIES_BOMBIRDIER,
    SPECIES_FINIZEN,
    SPECIES_VAROOM,
    SPECIES_CYCLIZAR,
    SPECIES_ORTHWORM,
    SPECIES_GLIMMET,
    SPECIES_GREAVARD,
    SPECIES_FLAMIGO,
    SPECIES_CETODDLE,
    SPECIES_VELUZA,
    SPECIES_DONDOZO,
    SPECIES_TATSUGIRI_CURLY,
    SPECIES_TATSUGIRI_DROOPY,
    SPECIES_TATSUGIRI_STRETCHY,
    SPECIES_FRIGIBAX,
    SPECIES_GIMMIGHOUL_CHEST,
    SPECIES_GIMMIGHOUL_ROAMING,
    SPECIES_POLTCHAGEIST_COUNTERFEIT,
    SPECIES_POLTCHAGEIST_ARTISAN,
};

static u16 PickRandomSpecies(void)
{
    // 1. The "Jackpot" Roll!
    // If the player is Champion, 5% chance to pull instantly from the Legendary pool.
    if (CanReceiveLegendaries() && (Random() % 100) < 5)
    {
        u16 poolSize = ARRAY_COUNT(sLegendaryWonderTradePool);
        return sLegendaryWonderTradePool[Random() % poolSize];
    }

    // 2. The Standard Roll
    // Instantly grabs a safe, pre-curated base-form Pokemon from your existing list.
    // No loops, no lag, no accidental Megas!
    u16 standardPoolSize = ARRAY_COUNT(sIsValidSpecies);
    return sIsValidSpecies[Random() % standardPoolSize];
}

// static u16 PickRandomSpecies(void) // picks only base forms
// {
//     // TEMPORARY TEST: Force Pumpkaboo to always be chosen
//     return SPECIES_PUMPKABOO;

//     /*
//     // Original Code to restore later:
//     u16 species = sIsValidSpecies[Random() % NELEMS(sIsValidSpecies)];
//     return species;
//     */
// }

// static bool8 IsMonValidForWonderTrade(struct BoxPokemon *boxMon)
// {
//     u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
//     if (species == SPECIES_NONE || species == SPECIES_EGG)
//         return FALSE;
//     if (GetBoxMonData(boxMon, MON_DATA_IS_EGG) || GetBoxMonData(boxMon, MON_DATA_SANITY_IS_BAD_EGG))
//         return FALSE;
//     return TRUE;
// }


static u8 GetWonderTradeOT(u8 *name)
{
    u8 randGender = (Random() % 2); // 0 for male, 1 for female
    u8 numOTNames = 250;
    u8 selectedName = Random() % numOTNames;
    u8 i;
    if (randGender == MALE) // male OT selected
    {
        randGender = 0;
        for (i = 0; i < PLAYER_NAME_LENGTH; ++i)
        {
            name[i] = maleWTNames[selectedName][i];
        }
        name[PLAYER_NAME_LENGTH] = EOS;
    }
    else                    // female OT selected
    {
        randGender = 0xFF;
        for (i = 0; i < PLAYER_NAME_LENGTH; ++i)
        {
            name[i] = femaleWTNames[selectedName][i];
        }
        name[PLAYER_NAME_LENGTH] = EOS;
    }
    return randGender;
}

static bool32 HasCondition(const struct EvolutionParam *params, u16 conditionToFind, u16 *arg1)
{
    int k;
    if (params == NULL) return FALSE;
    for (k = 0; params[k].condition != 0; k++)
    {
        if (params[k].condition == conditionToFind)
        {
            if (arg1) *arg1 = params[k].arg1;
            return TRUE;
        }
    }
    return FALSE;
}

void CreateWonderTradePokemon(void)
{
    struct BoxPokemon *playerBoxMon = GetSelectedBoxMonFromPcOrParty();
    u16 wonderTradeSpecies = PickRandomSpecies();
    u8 playerMonLevel = GetLevelFromBoxMonExp(playerBoxMon);
    u8 chanceToEvolve = Random() % 99;
    u16 newHeldItem = ITEM_NONE;
    u16 playerMonHeldItem = GetBoxMonData(playerBoxMon, MON_DATA_HELD_ITEM);
    u16 randomPokeball = sWonderTradePokeballs[Random() % NELEMS(sWonderTradePokeballs)];
    u32 i;
    u8 abilityNum;
    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u8 genderOT = GetWonderTradeOT(otName);
    u8 metLocation = METLOC_IN_GAME_TRADE;
    
    struct WonderTrade sWonderTrades[] =
    {
        [0] = {
            .nickname = _(""),
            .species = wonderTradeSpecies,
            .ivs = {31, 31, 31, 31, 31, 31},
            .abilityNum = (Random() % 2),
            .otId = 0,
            .conditions = {0, 0, 0, 0, 0},
            .personality = 0,
            .heldItem = newHeldItem,
            .mailNum = -1,
            .otName = _("ERROR"),
            .otGender = FEMALE,
            .sheen = 0,
            .requestedSpecies = GetBoxMonData(playerBoxMon, MON_DATA_SPECIES)
        },
    };
    struct WonderTrade *wonderTrade = &sWonderTrades[0];

    // Creates the base of a Pokémon in the first slot of a nonexistent enemy's party.
    CreateMonWithIVs(&gParties[B_TRAINER_OPPONENT_A][0], wonderTradeSpecies, playerMonLevel, Random32(), OTID_STRUCT_PRESET(((Random() << 16) | Random())), MAX_PER_STAT_IVS);
    GiveMonInitialMoveset(&gParties[B_TRAINER_OPPONENT_A][0]);

    // 20% chance of having the generated Wonder Traded 'mon carry an item.
    if ((Random() % 100) < 20)
        newHeldItem = GetValidHeldItemForSpecies(wonderTradeSpecies);

    if (playerMonHeldItem == ITEM_NONE)
    {
        if (gSpeciesInfo[wonderTradeSpecies].evolutions != NULL)
        {
            for (i = 0; gSpeciesInfo[wonderTradeSpecies].evolutions[i].method != 0; i++)
            {
                const struct Evolution *evo = &gSpeciesInfo[wonderTradeSpecies].evolutions[i];
                u16 itemArg = 0;
                
                if (evo->method == EVO_TRADE && HasCondition(evo->params, IF_HOLD_ITEM, &itemArg) && Random() % 100 < 50)
                {
                    // 30% chance for the incoming Pokémon to hold the item they need to evolve
                    if (Random() % 100 <= 30)
                    {
                        newHeldItem = itemArg;
                        SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HELD_ITEM, &newHeldItem);
                    }
                }
            }
        }
    }

    if (chanceToEvolve > 69) // 30% to evolve into the highest stage.
    {
        wonderTradeSpecies = GetWonderTradeEvolutionTargetSpecies(&gParties[B_TRAINER_OPPONENT_A][0]);
        SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES, &wonderTradeSpecies);
        
        wonderTradeSpecies = GetWonderTradeEvolutionTargetSpecies(&gParties[B_TRAINER_OPPONENT_A][0]);
        SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES, &wonderTradeSpecies);
    }
    else if (chanceToEvolve >= 19 && chanceToEvolve <= 69) // 50% to evolve once.
    {
        wonderTradeSpecies = GetWonderTradeEvolutionTargetSpecies(&gParties[B_TRAINER_OPPONENT_A][0]);
        SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES, &wonderTradeSpecies);
    }

    // 10% chance of giving the incoming Pokémon their HA, if they have one
    if (gSpeciesInfo[wonderTradeSpecies].abilities[2] != ABILITY_NONE && (Random() % 99) < 50)
    {
        if ((Random() % 99) < 10)
        {
            abilityNum = 2;
            SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_ABILITY_NUM, &abilityNum);
        }
    }

    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_POKEBALL, &randomPokeball);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HELD_ITEM, &newHeldItem);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP_IV, &wonderTrade->ivs[0]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_ATK_IV, &wonderTrade->ivs[1]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_DEF_IV, &wonderTrade->ivs[2]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPEED_IV, &wonderTrade->ivs[3]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPATK_IV, &wonderTrade->ivs[4]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPDEF_IV, &wonderTrade->ivs[5]);
    
    StringCopy(monName, gSpeciesInfo[wonderTradeSpecies].speciesName);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_NICKNAME, monName);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_OT_NAME, otName);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_BEAUTY, &wonderTrade->conditions[1]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_CUTE, &wonderTrade->conditions[2]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_COOL, &wonderTrade->conditions[0]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SMART, &wonderTrade->conditions[3]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_TOUGH, &wonderTrade->conditions[4]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SHEEN, &wonderTrade->sheen);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_OT_GENDER, &genderOT);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_MET_LOCATION, &metLocation);
    CalculateMonStats(&gParties[B_TRAINER_OPPONENT_A][0]);
    StringCopy(monName, gSpeciesInfo[wonderTradeSpecies].speciesName);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_NICKNAME, monName);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_OT_NAME, otName);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_BEAUTY, &wonderTrade->conditions[1]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_CUTE, &wonderTrade->conditions[2]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_COOL, &wonderTrade->conditions[0]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SMART, &wonderTrade->conditions[3]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_TOUGH, &wonderTrade->conditions[4]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SHEEN, &wonderTrade->sheen);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_OT_GENDER, &genderOT);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_MET_LOCATION, &metLocation);
    CalculateMonStats(&gParties[B_TRAINER_OPPONENT_A][0]);
    

    // NEW: 5% chance to force the Wonder Traded Pokemon to be Shiny!
    if ((Random() % 100) < 5)
    {
        bool8 isShiny = TRUE;
        SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_IS_SHINY, &isShiny);
    }

    CalculateMonStats(&gParties[B_TRAINER_OPPONENT_A][0]);
    
    // NEW: Buffer the generated OT Name into String Variable 1 for the NPC script!
    GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_OT_NAME, gStringVar1);
}

static u8 GetWonderTradeFamilyMinLevel(u16 species)
{
    switch (species)
    {
    // ==========================================
    // GATE 15: YOUR CUSTOM EARLY BUGS & STONES
    // ==========================================
#if P_FAMILY_SUNKERN
    case SPECIES_SUNKERN: case SPECIES_SUNFLORA:
#endif
#if P_FAMILY_PANSAGE
    case SPECIES_PANSAGE: case SPECIES_SIMISAGE:
#endif
#if P_FAMILY_PANSEAR
    case SPECIES_PANSEAR: case SPECIES_SIMISEAR:
#endif
#if P_FAMILY_PANPOUR
    case SPECIES_PANPOUR: case SPECIES_SIMIPOUR:
#endif
#if P_FAMILY_COTTONEE
    case SPECIES_COTTONEE: case SPECIES_WHIMSICOTT:
#endif
#if P_FAMILY_PETILIL
    case SPECIES_PETILIL: case SPECIES_LILLIGANT: case SPECIES_LILLIGANT_HISUI:
#endif
#if P_FAMILY_MINCCINO
    case SPECIES_MINCCINO: case SPECIES_CINCCINO:
#endif
#if P_FAMILY_FLABEBE
    case SPECIES_FLABEBE: case SPECIES_FLABEBE_YELLOW: case SPECIES_FLABEBE_ORANGE: case SPECIES_FLABEBE_BLUE: case SPECIES_FLABEBE_WHITE:
    case SPECIES_FLOETTE: case SPECIES_FLOETTE_YELLOW: case SPECIES_FLOETTE_ORANGE: case SPECIES_FLOETTE_BLUE: case SPECIES_FLOETTE_WHITE: case SPECIES_FLORGES:
#endif
#if P_FAMILY_CATERPIE
    case SPECIES_CATERPIE: case SPECIES_METAPOD: case SPECIES_BUTTERFREE:
#endif
#if P_FAMILY_WEEDLE
    case SPECIES_WEEDLE: case SPECIES_KAKUNA: case SPECIES_BEEDRILL:
#endif
#if P_FAMILY_WURMPLE
    case SPECIES_WURMPLE: case SPECIES_SILCOON: case SPECIES_BEAUTIFLY: case SPECIES_CASCOON: case SPECIES_DUSTOX:
#endif
#if P_FAMILY_KRICKETOT
    case SPECIES_KRICKETOT: case SPECIES_KRICKETUNE:
#endif
#if P_FAMILY_BURMY
    case SPECIES_BURMY: case SPECIES_BURMY_SANDY: case SPECIES_BURMY_TRASH: case SPECIES_WORMADAM: case SPECIES_MOTHIM:
#endif
#if P_FAMILY_SEWADDLE
    case SPECIES_SEWADDLE: case SPECIES_SWADLOON: case SPECIES_LEAVANNY:
#endif
#if P_FAMILY_SCATTERBUG
    case SPECIES_SCATTERBUG: case SPECIES_SPEWPA: case SPECIES_VIVILLON:
#endif
#if P_FAMILY_BLIPBUG
    case SPECIES_BLIPBUG: case SPECIES_DOTTLER: case SPECIES_ORBEETLE:
#endif
#if P_FAMILY_TAROUNTULA
    case SPECIES_TAROUNTULA: case SPECIES_SPIDOPS:
#endif
        return 15;

    // ==========================================
    // GATE 20: EARLY BIRDS & NINCADA
    // ==========================================
#if P_FAMILY_NINCADA
    case SPECIES_NINCADA: case SPECIES_NINJASK: case SPECIES_SHEDINJA:
#endif
#if P_FAMILY_PIDGEY
    case SPECIES_PIDGEY: case SPECIES_PIDGEOTTO: case SPECIES_PIDGEOT:
#endif
#if P_FAMILY_RATTATA
    case SPECIES_RATTATA: case SPECIES_RATICATE: case SPECIES_RATTATA_ALOLA: case SPECIES_RATICATE_ALOLA:
#endif
#if P_FAMILY_SPEAROW
    case SPECIES_SPEAROW: case SPECIES_FEAROW:
#endif
#if P_FAMILY_SENTRET
    case SPECIES_SENTRET: case SPECIES_FURRET:
#endif
#if P_FAMILY_HOOTHOOT
    case SPECIES_HOOTHOOT: case SPECIES_NOCTOWL:
#endif
#if P_FAMILY_ZIGZAGOON
    case SPECIES_ZIGZAGOON: case SPECIES_LINOONE: case SPECIES_ZIGZAGOON_GALAR: case SPECIES_LINOONE_GALAR: case SPECIES_OBSTAGOON:
#endif
#if P_FAMILY_TAILLOW
    case SPECIES_TAILLOW: case SPECIES_SWELLOW:
#endif
#if P_FAMILY_STARLY
    case SPECIES_STARLY: case SPECIES_STARAVIA: case SPECIES_STARAPTOR:
#endif
#if P_FAMILY_BIDOOF
    case SPECIES_BIDOOF: case SPECIES_BIBAREL:
#endif
#if P_FAMILY_SHINX
    case SPECIES_SHINX: case SPECIES_LUXIO: case SPECIES_LUXRAY:
#endif
#if P_FAMILY_FLETCHLING
    case SPECIES_FLETCHLING: case SPECIES_FLETCHINDER: case SPECIES_TALONFLAME:
#endif
#if P_FAMILY_ROOKIDEE
    case SPECIES_ROOKIDEE: case SPECIES_CORVISQUIRE: case SPECIES_CORVIKNIGHT:
#endif
        return 20;

    // ==========================================
    // GATE 21: PORYGON
    // ==========================================
#if P_FAMILY_PORYGON
    case SPECIES_PORYGON: case SPECIES_PORYGON2: case SPECIES_PORYGON_Z:
        return 21;
#endif

    // ==========================================
    // GATE 22: CLAMPERL
    // ==========================================
#if P_FAMILY_CLAMPERL
    case SPECIES_CLAMPERL: case SPECIES_HUNTAIL: case SPECIES_GOREBYSS:
        return 22;
#endif

    // ==========================================
    // GATE 26: NIDORAN, EXEGGCUTE, SCYTHER
    // ==========================================
#if P_FAMILY_NIDORAN
    case SPECIES_NIDORAN_F: case SPECIES_NIDORINA: case SPECIES_NIDOQUEEN: case SPECIES_NIDORAN_M: case SPECIES_NIDORINO: case SPECIES_NIDOKING:
#endif
#if P_FAMILY_EXEGGCUTE
    case SPECIES_EXEGGCUTE: case SPECIES_EXEGGUTOR: case SPECIES_EXEGGUTOR_ALOLA:
#endif
#if P_FAMILY_SCYTHER
    case SPECIES_SCYTHER: case SPECIES_SCIZOR: case SPECIES_KLEAVOR:
#endif
        return 26;

    // ==========================================
    // GATE 27: PIKACHU
    // ==========================================
#if P_FAMILY_PIKACHU
    case SPECIES_PICHU: case SPECIES_PIKACHU: case SPECIES_RAICHU: case SPECIES_RAICHU_ALOLA:
        return 27;
#endif

    // ==========================================
    // GATE 30: APPLIN, TOXEL, RALTS
    // ==========================================
#if P_FAMILY_APPLIN
    case SPECIES_APPLIN: case SPECIES_FLAPPLE: case SPECIES_APPLETUN: case SPECIES_DIPPLIN: case SPECIES_HYDRAPPLE:
#endif
#if P_FAMILY_TOXEL
    case SPECIES_TOXEL: case SPECIES_TOXTRICITY: case SPECIES_TOXTRICITY_LOW_KEY:
#endif
#if P_FAMILY_RALTS
    case SPECIES_RALTS: case SPECIES_KIRLIA: case SPECIES_GARDEVOIR: case SPECIES_GALLADE:
#endif
        return 30;

    // ==========================================
    // GATE 32: VULPIX, GROWLITHE
    // ==========================================
#if P_FAMILY_VULPIX
    case SPECIES_VULPIX: case SPECIES_NINETALES: case SPECIES_VULPIX_ALOLA: case SPECIES_NINETALES_ALOLA:
#endif
#if P_FAMILY_GROWLITHE
    case SPECIES_GROWLITHE: case SPECIES_ARCANINE: case SPECIES_GROWLITHE_HISUI: case SPECIES_ARCANINE_HISUI:
#endif
        return 32;

    // ==========================================
    // GATE 35: SNORUNT, TYNAMO, LITWICK, HELIOPTILE, DARUMAKA
    // ==========================================
#if P_FAMILY_SNORUNT
    case SPECIES_SNORUNT: case SPECIES_GLALIE: case SPECIES_FROSLASS:
#endif
#if P_FAMILY_TYNAMO
    case SPECIES_TYNAMO: case SPECIES_EELEKTRIK: case SPECIES_EELEKTROSS:
#endif
#if P_FAMILY_LITWICK
    case SPECIES_LITWICK: case SPECIES_LAMPENT: case SPECIES_CHANDELURE:
#endif
#if P_FAMILY_HELIOPTILE
    case SPECIES_HELIOPTILE: case SPECIES_HELIOLISK:
#endif
#if P_FAMILY_DARUMAKA
    case SPECIES_DARUMAKA: case SPECIES_DARMANITAN: case SPECIES_DARUMAKA_GALAR: case SPECIES_DARMANITAN_GALAR:
#endif
        return 35;

    // ==========================================
    // GATE 36: STARTERS & 3-STAGE STANDARDS
    // ==========================================
#if P_FAMILY_ODDISH
    case SPECIES_ODDISH: case SPECIES_GLOOM: case SPECIES_VILEPLUME: case SPECIES_BELLOSSOM:
#endif
#if P_FAMILY_BELLSPROUT
    case SPECIES_BELLSPROUT: case SPECIES_WEEPINBELL: case SPECIES_VICTREEBEL:
#endif
#if P_FAMILY_ABRA
    case SPECIES_ABRA: case SPECIES_KADABRA: case SPECIES_ALAKAZAM:
#endif
#if P_FAMILY_MACHOP
    case SPECIES_MACHOP: case SPECIES_MACHOKE: case SPECIES_MACHAMP:
#endif
#if P_FAMILY_GEODUDE
    case SPECIES_GEODUDE: case SPECIES_GRAVELER: case SPECIES_GOLEM: case SPECIES_GEODUDE_ALOLA: case SPECIES_GRAVELER_ALOLA: case SPECIES_GOLEM_ALOLA:
#endif
#if P_FAMILY_GASTLY
    case SPECIES_GASTLY: case SPECIES_HAUNTER: case SPECIES_GENGAR:
#endif
#if P_FAMILY_BULBASAUR
    case SPECIES_BULBASAUR: case SPECIES_IVYSAUR: case SPECIES_VENUSAUR:
#endif
#if P_FAMILY_CHARMANDER
    case SPECIES_CHARMANDER: case SPECIES_CHARMELEON: case SPECIES_CHARIZARD:
#endif
#if P_FAMILY_SQUIRTLE
    case SPECIES_SQUIRTLE: case SPECIES_WARTORTLE: case SPECIES_BLASTOISE:
#endif
#if P_FAMILY_CHIKORITA
    case SPECIES_CHIKORITA: case SPECIES_BAYLEEF: case SPECIES_MEGANIUM:
#endif
#if P_FAMILY_CYNDAQUIL
    case SPECIES_CYNDAQUIL: case SPECIES_QUILAVA: case SPECIES_TYPHLOSION: case SPECIES_TYPHLOSION_HISUI:
#endif
#if P_FAMILY_TOTODILE
    case SPECIES_TOTODILE: case SPECIES_CROCONAW: case SPECIES_FERALIGATR:
#endif
#if P_FAMILY_TREECKO
    case SPECIES_TREECKO: case SPECIES_GROVYLE: case SPECIES_SCEPTILE:
#endif
#if P_FAMILY_TORCHIC
    case SPECIES_TORCHIC: case SPECIES_COMBUSKEN: case SPECIES_BLAZIKEN:
#endif
#if P_FAMILY_MUDKIP
    case SPECIES_MUDKIP: case SPECIES_MARSHTOMP: case SPECIES_SWAMPERT:
#endif
        return 36;

    // ==========================================
    // GATE 37: SLOWPOKE
    // ==========================================
#if P_FAMILY_SLOWPOKE
    case SPECIES_SLOWPOKE: case SPECIES_SLOWBRO: case SPECIES_SLOWKING: case SPECIES_SLOWPOKE_GALAR: case SPECIES_SLOWBRO_GALAR: case SPECIES_SLOWKING_GALAR:
        return 37;
#endif

    // ==========================================
    // GATE 38: JIGGLYPUFF, CLEFAIRY, SKITTY, LOTAD, SEEDOT
    // ==========================================
#if P_FAMILY_JIGGLYPUFF
    case SPECIES_IGGLYBUFF: case SPECIES_JIGGLYPUFF: case SPECIES_WIGGLYTUFF:
#endif
#if P_FAMILY_CLEFAIRY
    case SPECIES_CLEFFA: case SPECIES_CLEFAIRY: case SPECIES_CLEFABLE:
#endif
#if P_FAMILY_SKITTY
    case SPECIES_SKITTY: case SPECIES_DELCATTY:
#endif
#if P_FAMILY_LOTAD
    case SPECIES_LOTAD: case SPECIES_LOMBRE: case SPECIES_LUDICOLO:
#endif
#if P_FAMILY_SEEDOT
    case SPECIES_SEEDOT: case SPECIES_NUZLEAF: case SPECIES_SHIFTRY:
#endif
        return 38;

    // ==========================================
    // GATE 40: ONIX, HORSEA
    // ==========================================
#if P_FAMILY_ONIX
    case SPECIES_ONIX: case SPECIES_STEELIX:
#endif
#if P_FAMILY_HORSEA
    case SPECIES_HORSEA: case SPECIES_SEADRA: case SPECIES_KINGDRA:
#endif
        return 40;

    // ==========================================
    // GATE 43: SHELLDER, STARYU
    // ==========================================
#if P_FAMILY_SHELLDER
    case SPECIES_SHELLDER: case SPECIES_CLOYSTER:
#endif
#if P_FAMILY_STARYU
    case SPECIES_STARYU: case SPECIES_STARMIE:
#endif
        return 43;

    // ==========================================
    // GATE 44: POLIWAG
    // ==========================================
#if P_FAMILY_POLIWAG
    case SPECIES_POLIWAG: case SPECIES_POLIWHIRL: case SPECIES_POLIWRATH: case SPECIES_POLITOED:
        return 44;
#endif

    // ==========================================
    // GATE 50: PSEUDOS & LATE BLOOMERS
    // ==========================================
#if P_FAMILY_DRATINI
    case SPECIES_DRATINI: case SPECIES_DRAGONAIR: case SPECIES_DRAGONITE:
#endif
#if P_FAMILY_LARVITAR
    case SPECIES_LARVITAR: case SPECIES_PUPITAR: case SPECIES_TYRANITAR:
#endif
#if P_FAMILY_BAGON
    case SPECIES_BAGON: case SPECIES_SHELGON: case SPECIES_SALAMENCE:
#endif
#if P_FAMILY_BELDUM
    case SPECIES_BELDUM: case SPECIES_METANG: case SPECIES_METAGROSS:
#endif
#if P_FAMILY_GIBLE
    case SPECIES_GIBLE: case SPECIES_GABITE: case SPECIES_GARCHOMP:
#endif
#if P_FAMILY_DEINO
    case SPECIES_DEINO: case SPECIES_ZWEILOUS: case SPECIES_HYDREIGON:
#endif
#if P_FAMILY_GOOMY
    case SPECIES_GOOMY: case SPECIES_SLIGGOO: case SPECIES_GOODRA: case SPECIES_SLIGGOO_HISUI: case SPECIES_GOODRA_HISUI:
#endif
#if P_FAMILY_JANGMO_O
    case SPECIES_JANGMO_O: case SPECIES_HAKAMO_O: case SPECIES_KOMMO_O:
#endif
#if P_FAMILY_DREEPY
    case SPECIES_DREEPY: case SPECIES_DRAKLOAK: case SPECIES_DRAGAPULT:
#endif
#if P_FAMILY_FRIGIBAX
    case SPECIES_FRIGIBAX: case SPECIES_ARCTIBAX: case SPECIES_BAXCALIBUR:
#endif
        return 50;

    // ==========================================
    // GATE 100: LEGENDARIES & MYTHICALS (NO EVOS)
    // ==========================================
#if P_FAMILY_ARTICUNO
    case SPECIES_ARTICUNO: case SPECIES_ARTICUNO_GALAR:
#endif
#if P_FAMILY_ZAPDOS
    case SPECIES_ZAPDOS: case SPECIES_ZAPDOS_GALAR:
#endif
#if P_FAMILY_MOLTRES
    case SPECIES_MOLTRES: case SPECIES_MOLTRES_GALAR:
#endif
#if P_FAMILY_MEWTWO
    case SPECIES_MEWTWO:
#endif
#if P_FAMILY_MEW
    case SPECIES_MEW:
#endif
#if P_FAMILY_RAYQUAZA
    case SPECIES_RAYQUAZA:
#endif
#if P_FAMILY_ARCEUS
    case SPECIES_ARCEUS:
#endif
        return 100;

    // ==========================================
    // GATE 25: THE DEFAULT SAFE NET
    // ==========================================
    // This catches everything else automatically (Eevee, Murkrow, Sandshrew, etc.)
    default:
        return 25; 
    }
}

static u16 GetWonderTradeEvolutionTargetSpecies(struct Pokemon *mon)
{
    int i, j;
    u16 targetSpecies = 0;
    struct BoxPokemon *playerBoxMon = GetSelectedBoxMonFromPcOrParty();
    u16 partnerSpecies = GetMonData(mon, MON_DATA_SPECIES);
    u32 partnerPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
    u16 upperPersonality = partnerPersonality >> 16;
    u8 partnerLevel = GetMonData(mon, MON_DATA_LEVEL);
    u16 rndEeveevolutionChance = Random() % 8;
    u16 rndAlcrememeEvoChance = Random() % 9;
    u16 currentMap = ((gSaveBlock1Ptr->location.mapGroup) << 8 | gSaveBlock1Ptr->location.mapNum);
    u16 partnerHeldItem = GetMonData(mon, MON_DATA_HELD_ITEM);
    u16 playerSpecies = GetBoxMonData(playerBoxMon, MON_DATA_SPECIES);
    u16 partnerHoldEffect = GetItemHoldEffect(partnerHeldItem);

    // partnerSpecies-specific exceptions.
    if (partnerSpecies == SPECIES_NINCADA && partnerLevel >= 20)
    {
        if ((Random() % 2) == 0)
            targetSpecies = SPECIES_NINJASK;
        else
            targetSpecies = SPECIES_SHEDINJA;
        return targetSpecies;
    }
    else if (partnerSpecies == SPECIES_EEVEE && partnerLevel >= 25)
    {
        if (rndEeveevolutionChance == 0)
            targetSpecies = SPECIES_VAPOREON;
        else if (rndEeveevolutionChance == 1)
            targetSpecies = SPECIES_JOLTEON;
        else if (rndEeveevolutionChance == 2)
            targetSpecies = SPECIES_FLAREON;
        else if (rndEeveevolutionChance == 3)
            targetSpecies = SPECIES_ESPEON;
        else if (rndEeveevolutionChance == 4)
            targetSpecies = SPECIES_UMBREON;
        else if (rndEeveevolutionChance == 5)
            targetSpecies = SPECIES_LEAFEON;
        else if (rndEeveevolutionChance == 6)
            targetSpecies = SPECIES_GLACEON;
        else if (rndEeveevolutionChance == 7)
            targetSpecies = SPECIES_SYLVEON;
        return targetSpecies;
    }
    else if (partnerSpecies == SPECIES_MILCERY && partnerLevel >= 25)
    {
        if (rndAlcrememeEvoChance == 0)
            targetSpecies = SPECIES_ALCREMIE;
        else if (rndAlcrememeEvoChance == 1)
            targetSpecies = SPECIES_ALCREMIE_RUBY_CREAM;
        else if (rndAlcrememeEvoChance == 2)
            targetSpecies = SPECIES_ALCREMIE_MATCHA_CREAM;
        else if (rndAlcrememeEvoChance == 3)
            targetSpecies = SPECIES_ALCREMIE_MINT_CREAM;
        else if (rndAlcrememeEvoChance == 4)
            targetSpecies = SPECIES_ALCREMIE_LEMON_CREAM;
        else if (rndAlcrememeEvoChance == 5)
            targetSpecies = SPECIES_ALCREMIE_SALTED_CREAM;
        else if (rndAlcrememeEvoChance == 6)
            targetSpecies = SPECIES_ALCREMIE_RUBY_SWIRL;
        else if (rndAlcrememeEvoChance == 7)
            targetSpecies = SPECIES_ALCREMIE_CARAMEL_SWIRL;
        else if (rndAlcrememeEvoChance == 8)
            targetSpecies = SPECIES_ALCREMIE_RAINBOW_SWIRL;
        return targetSpecies;
    }

    if (gSpeciesInfo[partnerSpecies].evolutions != NULL)
    {
        for (i = 0; gSpeciesInfo[partnerSpecies].evolutions[i].method != 0; i++)
        {
            const struct Evolution *evo = &gSpeciesInfo[partnerSpecies].evolutions[i];
            u16 arg1 = 0;

            if (evo->method == EVO_LEVEL)
            {
                if (HasCondition(evo->params, IF_MIN_FRIENDSHIP, NULL))
                {
                    if ((partnerSpecies == SPECIES_PICHU || partnerSpecies == SPECIES_CLEFFA || partnerSpecies == SPECIES_IGGLYBUFF
                      || partnerSpecies == SPECIES_TOGEPI || partnerSpecies == SPECIES_AZURILL || partnerSpecies == SPECIES_BUDEW
                      || partnerSpecies == SPECIES_BUNEARY || partnerSpecies == SPECIES_SWOOBAT || partnerSpecies == SPECIES_SWADLOON)
                      && partnerLevel >= 16)
                        targetSpecies = evo->targetSpecies;
                    else if (partnerSpecies == SPECIES_MEOWTH_ALOLA && partnerLevel >= 28)
                        targetSpecies = evo->targetSpecies;
                    else if ((partnerSpecies == SPECIES_GOLBAT || partnerSpecies == SPECIES_CHANSEY
                           || partnerSpecies == SPECIES_MUNCHLAX) && partnerLevel >= 35)
                        targetSpecies = evo->targetSpecies;
                }
                else if (HasCondition(evo->params, IF_ATK_GT_DEF, NULL))
                {
                    if (evo->param <= partnerLevel && GetMonData(mon, MON_DATA_ATK, 0) > GetMonData(mon, MON_DATA_DEF, 0))
                        targetSpecies = evo->targetSpecies;
                }
                else if (HasCondition(evo->params, IF_ATK_EQ_DEF, NULL))
                {
                    if (evo->param <= partnerLevel && GetMonData(mon, MON_DATA_ATK, 0) == GetMonData(mon, MON_DATA_DEF, 0))
                        targetSpecies = evo->targetSpecies;
                }
                else if (HasCondition(evo->params, IF_ATK_LT_DEF, NULL))
                {
                    if (evo->param <= partnerLevel && GetMonData(mon, MON_DATA_ATK, 0) < GetMonData(mon, MON_DATA_DEF, 0))
                        targetSpecies = evo->targetSpecies;
                }
                else if (HasCondition(evo->params, IF_PID_UPPER_MODULO_10_GT, NULL))
                {
                    if (evo->param <= partnerLevel && (upperPersonality % 10) <= 4)
                        targetSpecies = evo->targetSpecies;
                }
                else if (HasCondition(evo->params, IF_PID_UPPER_MODULO_10_LT, NULL))
                {
                    if (evo->param <= partnerLevel && (upperPersonality % 10) > 4)
                        targetSpecies = evo->targetSpecies;
                }
                else if (HasCondition(evo->params, IF_MIN_BEAUTY, NULL))
                {
                    if (partnerLevel >= 30)
                        targetSpecies = evo->targetSpecies;
                }
                else if (HasCondition(evo->params, IF_KNOWS_MOVE, &arg1))
                {
                    if (MonKnowsMove(mon, arg1))
                        targetSpecies = evo->targetSpecies;
                }
                else if (HasCondition(evo->params, IF_KNOWS_MOVE_TYPE, &arg1))
                {
                    for (j = 0; j < MAX_MON_MOVES; j++)
                    {
                        if (gMovesInfo[GetMonData(mon, MON_DATA_MOVE1 + j, NULL)].type == arg1)
                        {
                            targetSpecies = evo->targetSpecies;
                            break;
                        }
                    }
                }
                else if (HasCondition(evo->params, IF_TYPE_IN_PARTY, &arg1))
                {
                    if (evo->param <= partnerLevel)
                    {
                        for (j = 0; j < PARTY_SIZE; j++)
                        {
                            u16 currSpecies = GetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_SPECIES, NULL);
                            if (gSpeciesInfo[currSpecies].types[0] == arg1 || gSpeciesInfo[currSpecies].types[1] == arg1)
                            {
                                targetSpecies = evo->targetSpecies;
                                break;
                            }
                        }
                    }
                }
                else if (HasCondition(evo->params, IF_WEATHER, &arg1))
                {
                    j = GetCurrentWeather();
                    if (arg1 == WEATHER_RAIN)
                    {
                        if (j == WEATHER_RAIN || j == WEATHER_RAIN_THUNDERSTORM || j == WEATHER_DOWNPOUR)
                            targetSpecies = evo->targetSpecies;
                    }
                    else if (arg1 == WEATHER_FOG)
                    {
                        if (evo->param <= partnerLevel && (j == WEATHER_FOG_HORIZONTAL || j == WEATHER_FOG_DIAGONAL))
                            targetSpecies = evo->targetSpecies;
                    }
                }
                else if (HasCondition(evo->params, IF_IN_MAPSEC, &arg1))
                {
                    if (gMapHeader.regionMapSectionId == arg1)
                        targetSpecies = evo->targetSpecies;
                }
                else if (HasCondition(evo->params, IF_IN_MAP, &arg1))
                {
                    if (currentMap == arg1)
                        targetSpecies = evo->targetSpecies;
                }
                else if (HasCondition(evo->params, IF_SPECIES_IN_PARTY, &arg1))
                {
                    for (j = 0; j < PARTY_SIZE; j++)
                    {
                        if (GetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_SPECIES) == arg1)
                            targetSpecies = evo->targetSpecies;
                    }
                }
                else if (HasCondition(evo->params, IF_AMPED_NATURE, NULL))
                {
                    if (evo->param <= partnerLevel)
                    {
                        u8 nature = GetNature(mon);
                        if (nature == NATURE_HARDY || nature == NATURE_BRAVE || nature == NATURE_ADAMANT || nature == NATURE_NAUGHTY || nature == NATURE_DOCILE || nature == NATURE_IMPISH || nature == NATURE_LAX || nature == NATURE_HASTY || nature == NATURE_JOLLY || nature == NATURE_NAIVE || nature == NATURE_RASH || nature == NATURE_SASSY || nature == NATURE_QUIRKY)
                            targetSpecies = evo->targetSpecies;
                    }
                }
                else if (HasCondition(evo->params, IF_LOW_KEY_NATURE, NULL))
                {
                    if (evo->param <= partnerLevel)
                    {
                        u8 nature = GetNature(mon);
                        if (nature == NATURE_LONELY || nature == NATURE_BOLD || nature == NATURE_RELAXED || nature == NATURE_TIMID || nature == NATURE_SERIOUS || nature == NATURE_MODEST || nature == NATURE_MILD || nature == NATURE_QUIET || nature == NATURE_BASHFUL || nature == NATURE_CALM || nature == NATURE_GENTLE || nature == NATURE_CAREFUL)
                            targetSpecies = evo->targetSpecies;
                    }
                }
                else if (HasCondition(evo->params, IF_HOLD_ITEM, &arg1))
                {
                    if (partnerHeldItem == arg1)
                    {
                        partnerHeldItem = 0;
                        SetMonData(mon, MON_DATA_HELD_ITEM, &partnerHeldItem);
                        targetSpecies = evo->targetSpecies;
                    }
                }
                else if (evo->params == NULL || evo->params[0].condition == 0) // Standard Level Evolutions
                {
                    if (partnerSpecies == SPECIES_SLOWPOKE && partnerLevel >= 37)
                    {
                        if ((Random() % 2) == 0)
                            targetSpecies = SPECIES_SLOWBRO;
                        else
                            targetSpecies = SPECIES_SLOWKING;
                    }
                    else if (partnerSpecies == SPECIES_TOXEL && partnerLevel >= 30)
                    {
                        u8 nature = GetNature(mon);
                        if (nature == NATURE_HARDY || nature == NATURE_BRAVE || nature == NATURE_ADAMANT || nature == NATURE_NAUGHTY || nature == NATURE_DOCILE || nature == NATURE_IMPISH || nature == NATURE_LAX || nature == NATURE_HASTY || nature == NATURE_JOLLY || nature == NATURE_NAIVE || nature == NATURE_RASH || nature == NATURE_SASSY || nature == NATURE_QUIRKY)
                            targetSpecies = SPECIES_TOXTRICITY;
                        else
                            targetSpecies = SPECIES_TOXTRICITY_LOW_KEY;
                    }
                    else if (evo->param <= partnerLevel)
                    {
                        targetSpecies = evo->targetSpecies;
                    }
                }
            }
            else if (evo->method == EVO_ITEM)
            {
                // Request the minimum required level based on the Pokémon's Family Group
                u8 familyMinLevel = GetWonderTradeFamilyMinLevel(partnerSpecies);

                if (HasCondition(evo->params, IF_GENDER, &arg1))
                {
                    if (arg1 == MON_FEMALE && GetMonGender(mon) == MON_FEMALE && partnerSpecies == SPECIES_SNORUNT && partnerLevel >= familyMinLevel)
                        targetSpecies = evo->targetSpecies;
                    else if (arg1 == MON_MALE && GetMonGender(mon) == MON_MALE && partnerSpecies == SPECIES_KIRLIA && partnerLevel >= familyMinLevel)
                        targetSpecies = evo->targetSpecies;
                }
                else if (partnerLevel >= familyMinLevel)
                {
                    // Universal Gate for all standard Stone evolutions based on family limits
                    targetSpecies = evo->targetSpecies;
                }
            }
            else if (evo->method == EVO_TRADE)
            {
                // Request the minimum required level based on the Pokémon's Family Group
                u8 familyMinLevel = GetWonderTradeFamilyMinLevel(partnerSpecies);

                if (partnerLevel >= familyMinLevel)
                {
                    if (HasCondition(evo->params, IF_HOLD_ITEM, &arg1))
                    {
                        if (arg1 == partnerHeldItem)
                        {
                            partnerHeldItem = ITEM_NONE;
                            SetMonData(mon, MON_DATA_HELD_ITEM, &partnerHeldItem);
                            targetSpecies = evo->targetSpecies;
                        }
                    }
                    else if (HasCondition(evo->params, IF_TRADE_PARTNER_SPECIES, &arg1))
                    {
                        if (arg1 == playerSpecies && partnerHoldEffect != HOLD_EFFECT_PREVENT_EVOLVE)
                            targetSpecies = evo->targetSpecies;
                    }
                    else
                    {
                        // Universal Gate for all Trade evolutions based on family limits
                        targetSpecies = evo->targetSpecies;
                    }
                }
            }
        }
    }

    return (targetSpecies == 0) ? partnerSpecies : targetSpecies;
}

static u32 GetEvolutionSpecies(u16 speciesId)
{
    u32 i;

    if (gSpeciesInfo[speciesId].evolutions != NULL)
    {
        for (i = 0; gSpeciesInfo[speciesId].evolutions[i].method != 0; i++)
        {
            if (gSpeciesInfo[speciesId].evolutions[i].targetSpecies)
                return gSpeciesInfo[speciesId].evolutions[i].targetSpecies;
        }
    }
    return SPECIES_NONE;
}

static bool32 IsSpeciesFamilyMegaEvolutionCompatible(u16 species, u16 heldStone)
{
    u32 i;
    const struct FormChange *formChanges = gSpeciesInfo[species].formChangeTable;
    u16 nextEvo = GetEvolutionSpecies(species);

    if (formChanges != NULL)
    {
        for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
        {
            if (formChanges[i].method == FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM && formChanges[i].param1 == heldStone)
                return TRUE;
        }
    }

    if (nextEvo != SPECIES_NONE)
        return IsSpeciesFamilyMegaEvolutionCompatible(nextEvo, heldStone);

    return FALSE;
}

// Generates an item randomly for a Pokémon received via Wonder Trade to hold, with a few exceptions.
static u16 GetValidHeldItemForSpecies(u16 species)
{
    u16 item;
    u16 itemHoldEffect;
    u16 itemPocket;
    u8 itemImportance;

    ROLL:
        item = Random() % ITEMS_COUNT;

    itemHoldEffect = GetItemHoldEffect(item);
    itemPocket = GetItemPocket(item);
    itemImportance = GetItemImportance(item);

    if (item == ITEM_NONE || item == ITEM_ENIGMA_BERRY)
        goto ROLL;
    else if (itemHoldEffect == HOLD_EFFECT_NONE)
        goto ROLL;
    else if (IS_ITEM_MAIL(item))
        goto ROLL;
    else if (itemPocket == POCKET_KEY_ITEMS || itemPocket == POCKET_TM_HM)
        goto ROLL;
    else if (item == ITEM_GRACIDEA
          || item == ITEM_RED_ORB
          || item == ITEM_BLUE_ORB
          || item == ITEM_ADAMANT_ORB
          || item == ITEM_LUSTROUS_ORB
          || item == ITEM_GRISEOUS_ORB
          || item == ITEM_ADAMANT_CRYSTAL
          || item == ITEM_LUSTROUS_GLOBE
          || item == ITEM_GRISEOUS_CORE)
        goto ROLL;
    else if ((itemHoldEffect == HOLD_EFFECT_MEMORY || itemHoldEffect == HOLD_EFFECT_DRIVE
           || itemHoldEffect == HOLD_EFFECT_PLATE || itemHoldEffect == HOLD_EFFECT_GEMS)
           && (gSpeciesInfo[species].types[0] != GetItemHoldEffectParam(item)
            || gSpeciesInfo[species].types[1] != GetItemHoldEffectParam(item)))
        goto ROLL;
    else if (itemHoldEffect == HOLD_EFFECT_MEGA_STONE && !IsSpeciesFamilyMegaEvolutionCompatible(species, item))
        goto ROLL;
    else if (itemHoldEffect == HOLD_EFFECT_Z_CRYSTAL || itemHoldEffect == HOLD_EFFECT_OGERPON_MASK)
        goto ROLL;
    else if (itemImportance > 0)
        goto ROLL;

    return item;
}




static bool8 CanReceiveLegendaries(void)
{
    // Returns TRUE only if the player has all 8 badges AND the Champion flag
    if (FlagGet(FLAG_BADGE01_GET) && 
        FlagGet(FLAG_BADGE02_GET) &&
        FlagGet(FLAG_BADGE03_GET) && 
        FlagGet(FLAG_BADGE04_GET) &&
        FlagGet(FLAG_BADGE05_GET) && 
        FlagGet(FLAG_BADGE06_GET) &&
        FlagGet(FLAG_BADGE07_GET) && 
        FlagGet(FLAG_BADGE08_GET) &&
        FlagGet(FLAG_IS_CHAMPION))
    {
        return TRUE;
    }
    
    return FALSE;
}