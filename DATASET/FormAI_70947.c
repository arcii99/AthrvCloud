//FormAI DATASET v1.0 Category: Dice Roller ; Style: thoughtful
// C Dice Roller - A unique program to simulate rolling dice
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides;
    int roll, total = 0;
    char confirm;

    srand(time(0)); // Seed the random number generator with the current time

    printf("Welcome to C Dice Roller!\n\n");
    do {
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);

        printf("How many sides do the dice have? ");
        scanf("%d", &numSides);

        printf("\nRolling %d %d-sided dice...\n", numDice, numSides);

        for(int i = 0; i < numDice; i++) {
            roll = rand() % numSides + 1; // Generate a random number from 1 to numSides
            printf("Dice %d: %d\n", i+1, roll);
            total += roll;
        }

        printf("\nTotal: %d\n", total);

        printf("\nWould you like to roll again? (Y/N) ");
        scanf(" %c", &confirm); // The space before %c is to consume the newline character

        if(confirm == 'n' || confirm == 'N') {
            printf("\nThank you for using C Dice Roller!\n");
        }

        total = 0; // Reset the total for the next roll

    } while(confirm == 'y' || confirm == 'Y');

    return 0;
}