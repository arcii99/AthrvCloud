//FormAI DATASET v1.0 Category: Dice Roller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 // function for generating random number from 1 to 6
int roll() {
    return rand() % 6 + 1;
}

int main() {
    int dice_1, dice_2, total;
    char play_again = 'y';

    // seed the random number generator using current time
    srand(time(NULL));

    printf("*** Welcome to the Dice Roller ***\n");

    // loop until user chooses to quit
    while (play_again == 'y') {
        printf("\nRolling the dice...\n");
        dice_1 = roll();   // roll the first dice
        dice_2 = roll();   // roll the second dice
        total = dice_1 + dice_2;

        printf("Dice 1: %d\n", dice_1);
        printf("Dice 2: %d\n", dice_2);
        printf("Total: %d\n", total);

        // ask user if they want to roll again
        printf("Roll again? (y/n): ");
        scanf(" %c", &play_again);
        play_again = tolower(play_again);
    }

    printf("\nThank you for playing! Goodbye.\n");

    return 0;
}