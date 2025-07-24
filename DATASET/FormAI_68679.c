//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerChoice, ghostChoice, roundCount=1;
    srand(time(NULL)); // generating random seed

    printf("Welcome to the Haunted House Simulator\n");

    do {
        printf("\n--- Round %d ---\n", roundCount);

        // player's choice
        printf("Choose a room (1-5): ");
        scanf("%d", &playerChoice);

        // validating input
        if (playerChoice < 1 || playerChoice > 5) {
            printf("Invalid choice. Please choose from 1 to 5.\n");
            continue;
        }

        // ghost's choice
        ghostChoice = rand() % 5 + 1;

        if (ghostChoice == playerChoice) {
            printf("You have encountered a ghost in room %d!\n", playerChoice);
            printf("GAME OVER\n");
            break;
        } else {
            printf("No ghost in room %d. You're safe for now.\n");
        }

        roundCount++;

    } while (roundCount <= 10);

    printf("\n\nYou have survived the Haunted House Simulator! Congratulations!\n");

    return 0;
}