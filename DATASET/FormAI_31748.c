//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Initializing variables
    int playerChoice;
    int isGhostAlive = 1;
    int playerEscaped = 0;
    char input[5];
    srand(time(NULL));

    // Introduction
    printf("Welcome to the Haunted House Simulator\n");
    printf("You have entered a haunted house, and there is a ghost lurking around somewhere.\n");
    printf("You must find a way to escape before the ghost catches you.\n");

    // Game loop
    while(isGhostAlive && !playerEscaped) {
        // Display options
        printf("\nWhat do you want to do?\n");
        printf("1. Search for a way out\n");
        printf("2. Hide\n");
        printf("3. Confront the ghost\n");

        // Get player's choice
        printf("Your choice: ");
        fgets(input, 5, stdin);
        playerChoice = atoi(input);

        // Perform action based on player's choice
        if(playerChoice == 1) {
            // Random chance of finding a key
            int hasKey = rand() % 2;
            if(hasKey) {
                printf("You found a key! Use it to open the door and escape.\n");
                playerEscaped = 1;
            }
            else {
                printf("You couldn't find a way out. Keep searching!\n");
            }
        }
        else if(playerChoice == 2) {
            printf("You are hiding. The ghost is searching for you...\n");
            // Random chance of ghost finding player's hiding spot
            int found = rand() % 2;
            if(found) {
                printf("The ghost found you! You couldn't escape...\n");
                isGhostAlive = 0;
            }
            else {
                printf("You successfully evaded the ghost. Keep hiding or try to escape.\n");
            }
        }
        else if(playerChoice == 3) {
            printf("You confront the ghost...\n");
            // Random chance of winning the confrontation
            int win = rand() % 2;
            if(win) {
                printf("You defeated the ghost! You can now leave the haunted house.\n");
                playerEscaped = 1;
            }
            else {
                printf("The ghost was too powerful and killed you. Game over.\n");
                isGhostAlive = 0;
            }
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    // End of game message
    if(playerEscaped) {
        printf("\nCongratulations! You have escaped the haunted house alive.\n");
    }
    else {
        printf("\nYou were not able to escape the haunted house. Better luck next time.\n");
    }

    return 0;
}