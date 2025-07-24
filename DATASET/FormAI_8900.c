//FormAI DATASET v1.0 Category: Dice Roller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numSides, numRolls, i, j;
    char userChoice;

    srand(time(NULL));

    printf("Welcome to the Ken Thompson-style Dice Roller!\n");

    do {
        printf("How many sides do your dice have? ");
        scanf("%d", &numSides);

        printf("How many times would you like to roll the dice? ");
        scanf("%d", &numRolls);

        printf("\n");

        for (i = 1; i <= numRolls; i++) {
            int roll = rand() % numSides + 1;
            printf("%d\n", roll);
        }

        printf("\nWould you like to roll again? (y/n) ");
        scanf(" %c", &userChoice);
    } while (userChoice == 'y' || userChoice == 'Y');

    printf("Thanks for playing the Ken Thompson-style Dice Roller!\n");

    return 0;
}