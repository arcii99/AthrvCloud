//FormAI DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return (rand() % 6) + 1; // return a random number between 1 and 6
}

int main() {
    srand(time(NULL)); // initialize random seed
    int dice1, dice2, total;
    char input;

    do {
        dice1 = rollDice();
        dice2 = rollDice();
        total = dice1 + dice2;

        printf("You rolled a %d and a %d for a total of %d.\n", dice1, dice2, total);
        printf("Roll again? (y/n) ");
        scanf(" %c", &input);

        while (input != 'y' && input != 'n') { // validate user input
            printf("Invalid input. Roll again? (y/n) ");
            scanf(" %c", &input);
        }
    } while (input == 'y');

    printf("Thanks for playing!\n");
    return 0;
}