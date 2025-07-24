//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int playerHealth = 100;
    int alienHealth = 100;
    int playerAttackPower = 10;
    int alienAttackPower = 5;
    
    printf("Welcome to the Procedural Space Adventure!\n");
    
    while (playerHealth > 0 && alienHealth > 0) {
        int playerAttackRoll = rand() % 6 + 1;
        int alienAttackRoll = rand() % 6 + 1;
        
        if (playerAttackRoll > 3) {
            printf("You hit the alien and dealt %d damage!\n", playerAttackPower);
            alienHealth -= playerAttackPower;
        } else {
            printf("Your attack missed!\n");
        }
        
        if (alienAttackRoll > 3) {
            printf("The alien hit you and dealt %d damage!\n", alienAttackPower);
            playerHealth -= alienAttackPower;
        } else {
            printf("The alien's attack missed!\n");
        }
        
        printf("Your health: %d / Alien's health: %d\n\n", playerHealth, alienHealth);
    }
    
    if (playerHealth <= 0) {
        printf("GAME OVER! The alien defeated you.\n");
    } else {
        printf("CONGRATULATIONS! You defeated the alien.\n");
    }
    
    return 0;
}