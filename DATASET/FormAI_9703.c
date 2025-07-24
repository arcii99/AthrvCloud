//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ENEMIES 20
#define MAX_HEALTH 100
#define MIN_HEALTH 1
#define MAX_DAMAGE 50
#define MIN_DAMAGE 10

struct Enemy {
    int health;
    int damage;
    bool defeated;
};

struct Player {
    int health;
    int score;
};

// Function to initialize enemies
void initializeEnemies(struct Enemy enemies[MAX_ENEMIES], int numEnemies) {
    srand(time(NULL));
    for (int i = 0; i < numEnemies; i++) {
        enemies[i].health = rand() % (MAX_HEALTH - MIN_HEALTH + 1) + MIN_HEALTH;
        enemies[i].damage = rand() % (MAX_DAMAGE - MIN_DAMAGE + 1) + MIN_DAMAGE;
        enemies[i].defeated = false;
    }
}

// Function to check if all enemies have been defeated
bool allEnemiesDefeated(struct Enemy enemies[MAX_ENEMIES], int numEnemies) {
    for (int i = 0; i < numEnemies; i++) {
        if (!enemies[i].defeated) {
            return false;
        }
    }
    return true;
}

int main() {
    // Initialize game variables
    struct Player player = {MAX_HEALTH, 0};
    int numEnemies = 5;
    struct Enemy enemies[MAX_ENEMIES];
    initializeEnemies(enemies, numEnemies);
    int round = 1;

    // Start game loop
    while (true) {
        printf("Round %d\n", round);

        // Display player and enemy stats
        printf("Player Stats\nHealth: %d\nScore: %d\n", player.health, player.score);
        printf("Enemy Stats\n");
        for (int i = 0; i < numEnemies; i++) {
            printf("Enemy %d\n", i+1);
            printf("Health: %d\n", enemies[i].health);
            printf("Damage: %d\n", enemies[i].damage);
            if (enemies[i].defeated) {
                printf("Status: Defeated\n");
            } else {
                printf("Status: Active\n");
            }
        }

        // Player attacks each enemy once
        for (int i = 0; i < numEnemies; i++) {
            if (!enemies[i].defeated) {
                enemies[i].health -= player.score;
                printf("Player attacks Enemy %d for %d damage\n", i+1, player.score);
                if (enemies[i].health <= 0) {
                    enemies[i].defeated = true;
                    printf("Enemy %d defeated!\n", i+1);
                }
            }
        }

        // Enemies attack player
        for (int i = 0; i < numEnemies; i++) {
            if (!enemies[i].defeated) {
                player.health -= enemies[i].damage;
                printf("Enemy %d attacks player for %d damage\n", i+1, enemies[i].damage);
            }
        }

        // Check if game is over
        if (player.health <= 0) {
            printf("Game Over! Player has been defeated.\n");
            break;
        } else if (allEnemiesDefeated(enemies, numEnemies)) {
            printf("Congratulations! All enemies have been defeated.\n");
            break;
        }

        // Increase player score and go to next round
        player.score += numEnemies * 10;
        round++;
    }

    return 0;
}