#ifndef GUARD_EVENT_DISTRIBUTION_H
#define GUARD_EVENT_DISTRIBUTION_H

#include "global.h"

// Define the template structure for Event Pokemon
struct EventPokemonTemplate {
    u8 title[30]; // Title displayed in the UI menu (e.g., "Aura Mew")
    u16 species;
    u8 level;
    u8 nature; // Use 0xFF for a random nature
    u16 heldItem;
    u16 moves[4]; // Array of 4 moves. Use MOVE_NONE for empty slots.
    u8 otName[11]; // Up to 10 characters + null terminator
    u8 otGender; // 0 for Male, 1 for Female
    u32 otId; // The Trainer ID (combines both visible and secret ID)
    u8 pokeball; // e.g., ITEM_POKE_BALL, ITEM_CHERISH_BALL
    bool8 isShiny; // TRUE to force shiny
    bool8 isFatefulEncounter; // Set to TRUE to give it Fateful Encounter flags
};

// Function declarations
void DistributeEventPokemon(const struct EventPokemonTemplate* template);

#endif // GUARD_EVENT_DISTRIBUTION_H
