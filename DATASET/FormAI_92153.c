//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMY_HEALTH 50
#define MAX_PLAYER_HEALTH 100

void clearScreen() {
    printf("\033[2J\033[H");
}

void printIntro() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship on a mission to explore the galaxy.\n");
    printf("Your ship is equipped with a variety of weapons and shields to protect you from danger.\n");
    printf("But be careful, the dark reaches of space hold many unknown dangers...\n\n");
}

void generateEnemies(int* enemyCount, int* enemyHealth) {
    srand(time(NULL));

    *enemyCount = rand() % 6 + 1; // generate between 1 and 6 enemies
    printf("You have encountered %d enemies!\n", *enemyCount);

    for (int i = 0; i < *enemyCount; i++) {
        enemyHealth[i] = rand() % MAX_ENEMY_HEALTH + 1; // generate enemy health between 1 and 50
    }
}

void playerAttack(int* playerAttackPower, int* enemyHealth) {
    for (int i = 0; i < 3; i++) { // perform 3 attacks
        printf("You attack the enemy with a power of %d!\n", *playerAttackPower);
        enemyHealth[0] -= *playerAttackPower; // assume only 1 enemy for now

        if (enemyHealth[0] <= 0) {
            printf("The enemy has been defeated!\n\n");
            break;
        }
    }
}

void enemyAttack(int* playerHealth, int* enemyAttackPower) {
    printf("The enemy attacks you with a power of %d!\n", *enemyAttackPower);
    *playerHealth -= *enemyAttackPower;

    if (*playerHealth <= 0) {
        printf("You have died...\n");
        exit(0);
    }
}

void printBattleStatus(int* playerHealth, int* enemyHealth) {
    printf("Your health: %d\n", *playerHealth);
    printf("Enemy health: %d\n\n", enemyHealth[0]);
}

int main() {
    int playerHealth = MAX_PLAYER_HEALTH;
    int playerAttackPower = 20;
    int enemyCount, enemyHealth[6], enemyAttackPower = 10;

    clearScreen();
    printIntro();
    generateEnemies(&enemyCount, enemyHealth);

    while (enemyCount > 0) {
        printBattleStatus(&playerHealth, enemyHealth);

        // Player attacks
        playerAttack(&playerAttackPower, enemyHealth);

        // Enemies attack
        for (int i = 0; i < enemyCount; i++) {
            enemyAttack(&playerHealth, &enemyAttackPower);
        }
        
        // Check if all enemies have been defeated
        int defeatedEnemies = 0;
        for (int i = 0; i < enemyCount; i++) {
            if (enemyHealth[i] <= 0) {
                defeatedEnemies++;
            }
        }
        enemyCount -= defeatedEnemies;
    }
    
    printf("Congratulations! You have defeated all enemies.\n");

    return 0;
}