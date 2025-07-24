//FormAI DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_of_rolls = 0;
    int sides_of_dice = 0;

    printf("\n*** WELCOME TO THE DICE ROLLER! ***\n");

    // Get number of rolls from user
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &num_of_rolls);

    // Get number of sides from user
    printf("How many sides does the dice have? ");
    scanf("%d", &sides_of_dice);

    // Seed the random number generator
    srand(time(NULL));

    // Roll the dice the specified number of times
    for (int i = 0; i < num_of_rolls; i++) {
        int roll = rand() % sides_of_dice + 1;
        printf("Roll %d of %d: %d\n", i+1, num_of_rolls, roll);
    }

    printf("\n*** THANK YOU FOR USING THE DICE ROLLER! ***\n\n");

    return 0;
}