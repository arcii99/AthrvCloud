//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SHIP_HEALTH 100
#define MAX_ENEMIES 5

// Define a struct for the player's spaceship
typedef struct {
    int health;
    int attackPower;
    int defensePower;
} Spaceship;

// Define a struct for enemy spaceships
typedef struct {
    int health;
    int attackPower;
} Enemy;

// Function to generate random numbers for enemy health, attack, and defense
int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    Spaceship player;
    player.health = SHIP_HEALTH;
    player.attackPower = 25;
    player.defensePower = 10;

    Enemy enemies[MAX_ENEMIES];

    // Generate random enemies
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].health = generateRandomNumber(50, 100);
        enemies[i].attackPower = generateRandomNumber(10, 20);
    }

    int currentEnemy = 0;

    while (currentEnemy < MAX_ENEMIES) {
        printf("You have encountered an enemy spaceship!\n");
        printf("Enemy health: %d\n", enemies[currentEnemy].health);

        // Battle loop
        while (player.health > 0 && enemies[currentEnemy].health > 0) {
            // Player attacks first
            int playerAttack = generateRandomNumber(0, player.attackPower);
            printf("You attacked the enemy spaceship for %d damage!\n", playerAttack);
            enemies[currentEnemy].health -= playerAttack;

            if (enemies[currentEnemy].health <= 0) {
                printf("You have defeated the enemy spaceship!\n");
                currentEnemy++;
                if (currentEnemy < MAX_ENEMIES) {
                    printf("You have %d enemies left to defeat.\n", MAX_ENEMIES - currentEnemy);
                    printf("Your spaceship has %d health left.\n", player.health);
                    printf("Press ENTER to continue.\n");
                    getchar();
                } else {
                    printf("You have defeated all the enemy spaceships. Congratulations!\n");
                }
                break;
            }

            // Enemy attack
            int enemyAttack = generateRandomNumber(0, enemies[currentEnemy].attackPower - player.defensePower);
            printf("The enemy spaceship attacked you for %d damage.\n", enemyAttack);
            player.health -= enemyAttack;
            printf("Your spaceship has %d health left.\n", player.health);

            if (player.health <= 0) {
                printf("Your spaceship has been destroyed. Game over!\n");
                return 0;
            }
        }
    }

    return 0;
}