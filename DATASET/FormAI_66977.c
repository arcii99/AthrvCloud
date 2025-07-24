//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up variables for our simulator
    int playerHealth = 100;
    int ghostHealth = 50;
    int isHaunted = 1;
    srand(time(NULL)); // Seed our random number generator

    // Intro message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a haunted house and must survive!\n");

    // Main game loop - keep going as long as the player is alive and the house is still haunted
    while(playerHealth > 0 && isHaunted) {
        printf("\n\n---\n");
        printf("Player health: %d\n", playerHealth);
        printf("Ghost health: %d\n", ghostHealth);

        // Get a random number between 1 and 10
        int randNum = rand() % 10 + 1;

        // 50% chance of encountering a ghost
        if(randNum <= 5) {
            printf("You have encountered a ghost!\n");

            // Fight the ghost
            while(playerHealth > 0 && ghostHealth > 0) {
                printf("\n---\n");
                printf("Player health: %d\n", playerHealth);
                printf("Ghost health: %d\n", ghostHealth);

                // Get a random number between 1 and 4
                randNum = rand() % 4 + 1;

                // 25% chance of dodging the ghost's attack
                if(randNum == 4) {
                    printf("You dodged the ghost's attack!\n");
                }
                else {
                    // Ghost does 10 damage
                    playerHealth -= 10;
                    printf("The ghost did 10 damage!\n");
                    printf("Your health is now %d\n", playerHealth);
                }

                // Player's turn to attack
                printf("\n---\n");
                printf("It's your turn to attack!\n");
                printf("Press enter to attack\n");
                getchar();
                
                // Get a random number between 1 and 6
                randNum = rand() % 6 + 1;

                // 50% chance of hitting the ghost
                if(randNum <= 3) {
                    // Player does 20 damage
                    ghostHealth -= 20;
                    printf("You hit the ghost!\n");
                    printf("The ghost's health is now %d\n", ghostHealth);
                }
                else {
                    printf("You missed!\n");
                }
            }

            // Check if the player won or lost the fight
            if(playerHealth <= 0) {
                printf("\n---\n");
                printf("You have been defeated by the ghost...\n");
                isHaunted = 0;
            }
            else {
                printf("\n---\n");
                printf("You have defeated the ghost!\n");
                printf("The house is still haunted...\n");
            }
        }
        else {
            // Player finds a health pack
            printf("You found a health pack!\n");
            playerHealth += 20;
            printf("Your health is now %d\n", playerHealth);
        }

        // 20% chance of unhaunting the house
        randNum = rand() % 5 + 1;
        if(randNum == 1) {
            printf("You have exorcised the ghost and survived!\n");
            isHaunted = 0;
        }
    }

    // Game over message
    if(playerHealth <= 0) {
        printf("Game over! You were not able to survive the haunted house...\n");
    }
    else {
        printf("Congratulations! You have survived the haunted house!\n");
    }

    return 0;
}