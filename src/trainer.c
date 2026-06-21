#include "global.h"
#include "constants/trainers.h"
#include "outfit_menu.h"

static enum TrainerPicID GetEmeraldTrainerPic(enum Gender gender)
{
#ifdef MUDSKIP_OUTFIT_SYSTEM
    return GetPlayerTrainerPicIdByOutfitGenderType(gSaveBlock2Ptr->currOutfitId, gender, 0);
#else
    return gender == MALE ? TRAINER_PIC_MAGMA_GRUNT_M_PLAYER : TRAINER_PIC_MAGMA_GRUNT_F_PLAYER;
#endif
}
static enum TrainerPicID GetRSTrainerPic(enum Gender gender)
{
    return gender == MALE ? TRAINER_PIC_RS_BRENDAN : TRAINER_PIC_RS_MAY;
}

static enum TrainerPicID GetKantoTrainerPic(enum Gender gender)
{
    return gender == MALE ? TRAINER_PIC_RED : TRAINER_PIC_LEAF;
}

enum TrainerPicID GetPlayerTrainerPic(enum Gender gender, enum GameVersion version)
{
    switch (version)
    {
        case VERSION_SAPPHIRE:
        case VERSION_RUBY:
            return GetRSTrainerPic(gender);
        case VERSION_LEAF_GREEN:
        case VERSION_FIRE_RED:
            return GetKantoTrainerPic(gender);
        case VERSION_EMERALD:
        default:
            return GetEmeraldTrainerPic(gender);
    }
}
