//FormAI DATASET v1.0 Category: Dice Roller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice;
    char rollAgain;

    // seed random number generator
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");

    do {
        // get random number between 1 and 6
        dice = (rand() % 6) + 1;
        printf("You rolled a %d!\n", dice);

        // ask user if they want to roll again
        printf("Roll again? (y/n) ");
        scanf(" %c", &rollAgain);
    } while (rollAgain == 'y');

    printf("Thanks for playing!\n");

    return 0;
}