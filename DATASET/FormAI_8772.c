//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10
#define MAX_HEALTH 100
#define MAX_SHIELD 50
#define MAX_DAMAGE 20

int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void battle(int *player_health, int *player_shield, int player_damage, 
            int enemy_health, int enemy_damage) {
    int turn = 1;
    int round_damage;

    while (*player_health > 0 && enemy_health > 0) {
        printf("\n--- Turn %d ---\n", turn);

        // Choose whether to attack or shield
        int action = random_int(1, 2);
        if (action == 1) {
            // Calculate damage
            round_damage = random_int(1, player_damage + 1);
            if (*player_shield > 0) {
                printf("Player attacked enemy with %d damage. Enemy shielded.\n", 
                       round_damage);
                *player_shield -= round_damage;
                if (*player_shield < 0) {
                    *player_shield = 0;
                }
            } else {
                printf("Player attacked enemy with %d damage.\n", round_damage);
                enemy_health -= round_damage;
            }
        } else {
            // Shield
            round_damage = random_int(1, enemy_damage + 1);
            printf("Player shielded. Enemy attacked with %d damage.\n", round_damage);
            if (*player_shield < MAX_SHIELD) {
                if ((*player_shield + round_damage) > MAX_SHIELD) {
                    *player_shield = MAX_SHIELD;
                } else {
                    *player_shield += round_damage;
                }
            }
        }

        // Enemy turn
        if (enemy_health > 0) {
            round_damage = random_int(1, enemy_damage + 1);
            printf("Enemy attacked with %d damage.\n", round_damage);
            if (*player_shield > 0) {
                printf("Player shielded.\n");
                *player_shield -= round_damage;
                if (*player_shield < 0) {
                    *player_shield = 0;
                }
            } else {
                *player_health -= round_damage;
            }
        }

        // Check for game over
        if (*player_health <= 0) {
            printf("\nGame over. You have been defeated.\n");
        } else if (enemy_health <= 0) {
            printf("\nCongratulations, you have won!\n");
        }

        turn++;
    }
}

int main() {
    srand(time(NULL));

    int player_health = MAX_HEALTH, player_shield = MAX_SHIELD, player_damage = MAX_DAMAGE;

    printf("Welcome to the Procedural Space Adventure game!\n");
    printf("You are the captain of a spaceship on a mission to explore the galaxy.\n");
    printf("Your first task is to navigate through a dangerous asteroid field...\n");
    printf("Press enter to begin.\n");
    getchar();

    // Asteroid field
    printf("\nYou have entered the asteroid field.\n");
    printf("Be careful, there are %d asteroids in this area.\n", MAX_ENEMIES);

    for (int i = 1; i <= MAX_ENEMIES; i++) {
        int asteroid_health = random_int(50, 100);
        int asteroid_damage = random_int(5, 10);

        printf("\n--- Asteroid %d ---\n", i);
        printf("Health: %d\n", asteroid_health);
        printf("Damage: %d\n", asteroid_damage);

        battle(&player_health, &player_shield, player_damage, asteroid_health, asteroid_damage);

        if (player_health <= 0) {
            return -1;
        }
    }

    printf("\nCongratulations, you have navigated the asteroid field safely!\n");

    return 0;
}