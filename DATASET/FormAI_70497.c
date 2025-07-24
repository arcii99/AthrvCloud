//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between min and max
int randomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to print starship information
void printShipInfo(int shipClass, int shipWeapon, int shipHealth) {
    printf("Starship Class: %d\n", shipClass);
    printf("Starship Weapon: %d\n", shipWeapon);
    printf("Starship Health: %d\n", shipHealth);
}

// Function to simulate a space battle
void spaceBattle(int playerClass, int playerWeapon, int playerHealth) {
    
    // Generate random enemy starship information
    int enemyClass = randomInt(1, 3);
    int enemyWeapon = randomInt(1, 3);
    int enemyHealth = randomInt(50, 150);
    
    // Print enemy starship information
    printf("Enemy Starship Information:\n");
    printShipInfo(enemyClass, enemyWeapon, enemyHealth);
    
    // Battle loop
    while (1) {
        // Player attack
        int playerDamage = randomInt(10, 20) * playerWeapon;
        printf("Player dealt %d damage to enemy starship!\n", playerDamage);
        enemyHealth -= playerDamage;
        if (enemyHealth <= 0) {
            printf("Player wins the battle!\n");
            break;
        }
        
        // Enemy attack
        int enemyDamage = randomInt(10, 20) * enemyWeapon;
        printf("Enemy dealt %d damage to player's starship!\n", enemyDamage);
        playerHealth -= enemyDamage;
        if (playerHealth <= 0) {
            printf("Enemy wins the battle!\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    
    // Generate player starship information
    int playerClass = randomInt(1, 3);
    int playerWeapon = randomInt(1, 3);
    int playerHealth = randomInt(50, 150);
    
    // Print player starship information
    printf("Player Starship Information:\n");
    printShipInfo(playerClass, playerWeapon, playerHealth);
    
    // Start space adventure loop
    while (1) {
        // Generate random space event
        int event = randomInt(1, 3);
        
        if (event == 1) {
            printf("You encounter an enemy starship!\n");
            spaceBattle(playerClass, playerWeapon, playerHealth);
            break;
        }
        else if (event == 2) {
            printf("You find a new weapon for your starship!\n");
            playerWeapon++;
        }
        else {
            printf("You find a repair kit for your starship!\n");
            playerHealth += 20;
            if (playerHealth > 150) {
                playerHealth = 150; // Cap health at 150
            }
        }
    }
    
    return 0;
}