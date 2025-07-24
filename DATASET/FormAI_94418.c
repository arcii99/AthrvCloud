//FormAI DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Dice Roller! Roll the dice to determine your fate in the post-apocalyptic world.\n");

    // Initialize random seed
    srand(time(NULL));

    // Main game loop
    while (1) {
        // Prompt the user to roll the dice
        printf("Press enter to roll the dice...");
        getchar();

        // Roll the dice: 1d6
        int diceRoll = rand() % 6 + 1;

        // Display the result
        printf("\nYou rolled a %d.\n", diceRoll);

        // Determine the outcome based on the dice roll
        switch (diceRoll) {
            case 1:
                printf("You were attacked by a group of raiders and barely escaped with your life.\n");
                break;
            case 2:
                printf("You found a stash of food and water that will sustain you for a few days.\n");
                break;
            case 3:
                printf("You stumbled upon an abandoned car and found some useful supplies.\n");
                break;
            case 4:
                printf("You got lost in a maze of ruins and wasted precious time.\n");
                break;
            case 5:
                printf("You successfully scavenged an old medical kit, which will be useful for healing your wounds.\n");
                break;
            case 6:
                printf("You didn't find anything of value, but at least you avoided getting radiation sickness.\n");
                break;
            default:
                printf("Something went wrong. Please try again.\n");
                break;
        }

        // Prompt the user to continue playing or quit
        printf("Do you want to roll again? (y/n) ");
        char choice = getchar();
        getchar(); // Clear input buffer

        // Check if the user wants to quit
        if (choice == 'n') {
            printf("Thanks for playing! Good luck out there in the wasteland.\n");
            break;
        }
    }

    return 0;
}