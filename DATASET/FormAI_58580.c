//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between a and b
int generateRandom(int a, int b) {
    return rand() % (b - a + 1) + a;
}

// Function to simulate travelling through space
void travel() {
    printf("Travelling through space...\n\n");
}

// Function to simulate a space battle
void battle() {
    printf("Entering space battle mode...\n");
    int enemyHealth = generateRandom(500, 1000);
    int playerHealth = generateRandom(500, 1000);
    while (enemyHealth > 0 && playerHealth > 0) {
        // Simulate player attack
        int playerDmg = generateRandom(50, 200);
        printf("You attack the enemy for %d damage!\n", playerDmg);
        enemyHealth -= playerDmg;
        
        // Simulate enemy attack
        int enemyDmg = generateRandom(50, 200);
        printf("The enemy attacks you for %d damage!\n", enemyDmg);
        playerHealth -= enemyDmg;
        
        // Print health status
        printf("Your health: %d / Enemy health: %d\n\n", playerHealth, enemyHealth);
    }
    if (enemyHealth <= 0) {
        printf("You have defeated the enemy!\n\n");
    } else {
        printf("You have been defeated by the enemy!\n\n");
    }
}

// Main function to run the space adventure game
int main() {
    srand(time(NULL));
    int currentSystem = 1;
    int systemCount = 5; // Number of systems to travel through
    printf("Welcome to the Procedural Space Adventure Game!\n");
    printf("You have %d systems to travel through to reach your destination.\n\n", systemCount);
    while (currentSystem <= systemCount) {
        printf("Entering system %d...\n", currentSystem);
        int event = generateRandom(1, 3); // Generate a random event (1 = travel, 2 = battle, 3 = nothing)
        if (event == 1) {
            travel();
        } else if (event == 2) {
            battle();
        } else {
            printf("Nothing happened in this system...\n\n");
        }
        currentSystem++;
    }
    printf("Congratulations! You have successfully completed the Procedural Space Adventure Game!\n");
    return 0;
}