//FormAI DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * This program rolls a dice based on user input and returns the result.
 */

int main() {
    int sides, roll;
    char choice;

    printf("How many sides does your dice have? ");
    scanf("%d", &sides);

    // seed the random number generator
    srand(time(0));

    do {
        // roll the dice
        roll = rand() % sides + 1;
        printf("Rolling the %d-sided dice...\n", sides);
        printf("The result is: %d\n", roll);

        printf("Do you want to roll again? (Y/N) ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("Thanks for playing!\n");

    return 0;
}