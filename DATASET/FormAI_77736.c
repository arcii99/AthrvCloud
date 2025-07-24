//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumber(int min, int max) {
    // Generate a random number between min and max
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Define variables
    int ghosts = 5;
    int floors = 3;
    int currentFloor = 1;
    int playerScore = 0;

    // Game loop
    while (1) {
        // Print current status
        printf("\n********** Haunted House Simulator **********\n");
        printf("Floor: %d/%d    Ghosts Remaining: %d    Score: %d\n", currentFloor, floors, ghosts, playerScore);

        // Generate a random number to determine if a ghost appears
        int ghostChance = randomNumber(1, 10);

        // If a ghost appears on this floor
        if (ghostChance >= 8) {
            printf("\n!!! A ghost has appeared !!!\n");
            ghosts--;

            // Generate a random number to determine if the player captures the ghost
            int captureChance = randomNumber(1, 10);

            // If the player captures the ghost
            if (captureChance >= 6) {
                printf("You have successfully captured the ghost!\n");
                playerScore++;

                // If there are no more ghosts on this floor
                if (ghosts == 0) {
                    printf("\nCongratulations, you have cleared floor %d!\n", currentFloor);

                    // If there are more floors to go to
                    if (currentFloor < floors) {
                        printf("Proceed to the next floor.\n");
                        currentFloor++;
                        ghosts = 5;
                    }

                    // If there are no more floors to go to
                    else {
                        printf("You have successfully cleared the haunted house! Congratulations!\n");
                        break;
                    }
                }
            }

            // If the player fails to capture the ghost
            else {
                printf("The ghost has escaped! Better luck next time.\n");
            }
        }

        // If no ghost appears on this floor
        else {
            printf("Phew, nothing to worry about on this floor.\n");
        }

        // Generate a random delay before proceeding to the next loop iteration
        int delay = randomNumber(1, 5);
        printf("Waiting for %d seconds...\n", delay);
        sleep(delay);
    }

    return 0;
}