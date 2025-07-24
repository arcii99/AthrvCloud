//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides, int rolls) {
    if (rolls == 1) {
        return rand() % sides + 1;
    }
    return rand() % sides + 1 + roll_dice(sides, rolls - 1);
}

int main() {
    int sides, rolls;
    char play_again = 'y';

    srand(time(NULL)); //seeding the PRNG with the current time

    printf("Welcome to the Recursive Dice Roller Program!\n");

    while (play_again == 'y') {
        printf("Enter the number of sides on the dice: ");
        scanf("%d", &sides);

        printf("Enter the number of times to roll the dice: ");
        scanf("%d", &rolls);

        int total = roll_dice(sides, rolls);

        printf("You rolled a total of %d\n", total);

        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &play_again);
    }

    printf("Thanks for playing! Goodbye!\n");

    return 0;
}