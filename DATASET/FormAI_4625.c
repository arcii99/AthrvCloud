//FormAI DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int dice, sides, roll, total = 0;
    char choice;

    // seed random number generator
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");

    do {
        // get user input
        printf("How many dice would you like to roll? ");
        scanf("%d", &dice);
        printf("How many sides does the dice have? ");
        scanf("%d", &sides);

        // roll dice and calculate total
        for (int i = 0; i < dice; i++) {
            roll = rand() % sides + 1;
            total += roll;
            printf("Dice %d rolled a %d.\n", i+1, roll);
        }

        // print total and ask if user wants to roll again
        printf("Total of all dice rolls: %d\n", total);
        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &choice);

        // reset total for next roll
        total = 0;

    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}