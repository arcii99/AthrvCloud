//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHealth = 100;
    int alienHealth = 100;

    printf("Welcome to the Procedural Space Adventure!\n");

    // Seed random number generator
    srand(time(NULL));

    while (playerHealth > 0 && alienHealth > 0) {
        // Player attack
        int playerAttack = rand() % 21;  // generates a random number between 0 and 20
        alienHealth -= playerAttack;
        printf("You hit the alien ship for %d damage! Its health is now %d.\n", playerAttack, alienHealth);

        if (alienHealth <= 0) {
            printf("Congratulations! You have defeated the alien ship!\n");
            break;
        }

        // Alien attack
        int alienAttack = rand() % 21;
        playerHealth -= alienAttack;
        printf("The alien ship hit you for %d damage! Your health is now %d.\n", alienAttack, playerHealth);

        if (playerHealth <= 0) {
            printf("Game over! The alien ship has defeated you.\n");
            break;
        }
    }

    return 0;
}