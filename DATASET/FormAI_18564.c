//FormAI DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator with the current time
    int choice, numDice, numSides;

    printf("** Welcome to the C Dice Roller! **\n");
    printf("How many dice would you like to roll?\n");
    scanf("%d", &numDice);
    printf("How many sides should each die have?\n");
    scanf("%d", &numSides);

    printf("\nYou have chosen to roll %d dice with %d sides each.\n\n", numDice, numSides);
    printf("Press 1 to roll! Press 0 to quit!\n");

    while (1) { // loop until the user decides to quit
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("Thanks for playing! Goodbye!\n");
                return 0;
            case 1:
                printf("Rolling...\n\n");

                for (int i = 1; i <= numDice; i++) {
                    printf("Die %d: %d\n", i, rand() % numSides + 1);
                }

                printf("\nPress 1 to roll again! Press 0 to quit!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}