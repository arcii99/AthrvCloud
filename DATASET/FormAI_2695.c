//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_GHOSTS 5
#define MAX_GHOST_HP 10
#define MIN_GHOST_HP 1

int main() {
    srand(time(NULL)); // Seed random generator with current time

    char rooms[MAX_ROOMS][20] = {"Ballroom", "Library", "Kitchen", "Bedroom", "Study", "Attic", "Cellar", "Bathroom", "Closet", "Pantry"};
    // Define the names of the rooms in the haunted house

    int current_room = 0; // The room the player is currently in
    int player_hp = 50; // The player's starting health
    int ghosts_remaining = MAX_GHOSTS; // The number of ghosts remaining in the house
    int ghost_hp[MAX_GHOSTS]; // The health of each ghost
    int i;

    // Initialize ghost health randomly
    for (i = 0; i < MAX_GHOSTS; i++) {
        ghost_hp[i] = rand() % (MAX_GHOST_HP - MIN_GHOST_HP + 1) + MIN_GHOST_HP;
    }

    printf("You have entered a haunted house. Be careful!\n");

    // Main game loop
    while (ghosts_remaining > 0 && player_hp > 0) {

        printf("\nYou are in the %s.\n", rooms[current_room]);

        // Generate a random chance for a ghost encounter
        int encounter_chance = rand() % 5;

        if (encounter_chance == 0) {
            // Ghost encounter!
            int ghost_index = rand() % MAX_GHOSTS; // Choose a random ghost
            printf("You have encountered a ghost with %dHP!\n", ghost_hp[ghost_index]);

            // Attack the ghost until it is defeated or the player dies
            while (ghost_hp[ghost_index] > 0 && player_hp > 0) {
                int attack_amount = rand() % 5 + 1; // Generate random attack amount between 1 and 5
                printf("You hit the ghost for %d damage!\n", attack_amount);
                ghost_hp[ghost_index] -= attack_amount;

                // Ghost attacks back
                if (ghost_hp[ghost_index] > 0) {
                    int ghost_attack_amount = rand() % 3 + 1; // Generate random attack amount between 1 and 3
                    printf("The ghost hits you for %d damage!\n", ghost_attack_amount);
                    player_hp -= ghost_attack_amount;
                }
            }

            if (player_hp <= 0) {
                printf("You have died!\n");
            } else {
                printf("You have defeated the ghost!\n");
                ghosts_remaining--;
            }
        }

        // Move to a new room
        if (ghosts_remaining > 0) {
            int move_chance = rand() % 2;
            if (move_chance == 0) {
                printf("You move to the next room.\n");
                current_room = (current_room + 1) % MAX_ROOMS;
            } else {
                printf("You decide not to move.\n");
            }
        }
    }

    // End of game
    if (player_hp <= 0) {
        printf("You have lost the game.\n");
    } else {
        printf("Congratulations, you have survived the haunted house!\n");
    }

    return 0;
}