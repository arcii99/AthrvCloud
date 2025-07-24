//FormAI DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, num;
    char choice;
    srand(time(0)); // seed random number generator with current time

    printf("Welcome to the Dice Roller program!\n");

    do {
        printf("\nHow many dice would you like to roll? ");
        scanf("%d", &num);

        if(num < 1) {
            printf("Sorry, you must roll at least one dice. Please try again.\n");
            continue;
        }

        printf("\nYou have chosen to roll %d dice.\n", num);

        printf("\nHere are the results of your dice roll(s):\n");

        for(i = 1; i <= num; i++) {
            printf("Dice %d: %d\n", i, rand() % 6 + 1); // roll each dice and print result
        }

        printf("\nWould you like to roll again? (y/n) ");
        scanf(" %c", &choice); // accept character input, ignoring leading whitespace

    } while(choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Dice Roller program!\n");

    return 0;
}