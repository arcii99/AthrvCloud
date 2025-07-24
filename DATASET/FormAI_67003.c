//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 1000
#define MAX_ENEMY_HEALTH 100
#define MAX_SHIP_HEALTH 200
#define MAX_ENERGY 200

struct Player {
    int health;
    int energy;
    int distance_travelled;
};

struct Enemy {
    int health;
};

int main() {
    srand(time(0)); // set seed for randomization

    // initialize player and enemy
    struct Player player = {MAX_SHIP_HEALTH, MAX_ENERGY, 0};
    struct Enemy enemy = {MAX_ENEMY_HEALTH};

    printf("Welcome to Procedural Space Adventure!\n");

    while (player.health > 0 && enemy.health > 0 && player.distance_travelled < MAX_DISTANCE) {
        printf("\nYou have travelled %d miles away from Earth!\n", player.distance_travelled);
        printf("\nYour ship has %d health and %d energy.\n", player.health, player.energy);
        printf("The enemy has %d health.\n", enemy.health);

        // generate random event
        int event_type = rand() % 3; // 0: nothing happens, 1: asteroid field, 2: enemy encounter

        if (event_type == 1) {
            printf("\n\nYou have entered an asteroid field!\n\n");

            // deduct random health and energy from ship
            int damage = rand() % 50 + 1; // damage is between 1 and 50
            player.health -= damage;
            player.energy -= damage;

            if (player.health <= 0) {
                printf("\n\nYour ship has been destroyed by the asteroid field. Game over!\n\n");
                return 0;
            }
            if (player.energy < 0) {
                player.energy = 0;
            }
        } else if (event_type == 2) {
            printf("\n\nYou have encountered an enemy ship!\n\n");
            while (enemy.health > 0 && player.health > 0 && player.energy > 0) {
                // player attack
                int damage_dealt = rand() % 10 + 10; // damage dealt is between 10 and 20
                player.energy -= 10; // cost of attack is 10 energy
                printf("\nYou deal %d damage to the enemy!\n", damage_dealt);
                enemy.health -= damage_dealt;

                // enemy attack
                damage_dealt = rand() % 5 + 5; // damage dealt is between 5 and 10
                player.health -= damage_dealt;
                printf("The enemy deals %d damage to your ship!\n", damage_dealt);

                if (player.health <= 0) {
                    printf("\n\nYour ship has been destroyed by the enemy. Game over!\n\n");
                    return 0;
                }
            }
            if (enemy.health <= 0) {
                int loot = rand() % 50 + 50; // loot is between 50 and 100
                player.energy += loot;
                printf("\n\nYou have defeated the enemy and gained %d energy!\n\n", loot);
            }
        } else {
            printf("\n\nNothing happens...\n\n");
        }

        // update distance travelled
        player.distance_travelled += 50;

        // replenish energy
        player.energy += 20;
        if (player.energy > MAX_ENERGY) {
            player.energy = MAX_ENERGY;
        }
    }

    if (player.distance_travelled >= MAX_DISTANCE) {
        printf("\n\nCongratulations, you have reached the end of the universe!\n\n");
    }
    
    return 0;
}