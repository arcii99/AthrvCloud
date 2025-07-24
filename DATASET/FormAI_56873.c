//FormAI DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j, sum;
    char rollAgain;

    srand(time(NULL)); // seed the rand() function with current time

    printf("Welcome to the Multivariable Dice Roller!\n\n");

    do {
        sum = 0; // initialize the sum to 0

        // prompt the user to enter the number of dice and sides
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);

        printf("How many sides do the dice have? ");
        scanf("%d", &numSides);

        // roll the dice and print the results
        printf("\nYou rolled:\n\n");
        for (i = 1; i <= numDice; i++) {
            int result = rand() % numSides + 1;
            printf("Die %d: %d\n", i, result);
            sum += result; // add the result to the sum
        }

        // print the sum of the rolls
        printf("\nTotal: %d\n", sum);

        // ask the user if they want to roll again
        printf("\nRoll again? (y/n) ");
        scanf(" %c", &rollAgain);

    } while (rollAgain == 'y' || rollAgain == 'Y');

    printf("\nThanks for rolling with us! Goodbye!\n");

    return 0;
}