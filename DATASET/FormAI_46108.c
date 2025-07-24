//FormAI DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, dice, dice_rolls[7] = {0};
    // initialize dice_rolls array with 0s

    srand(time(NULL)); // seed the random number generator

    for (i = 0; i < 1000000; i++) {
        dice = rand() % 6 + 1; // roll the dice
        dice_rolls[dice]++; // increment the count for this number
    }

    // print the results
    printf("Dice rolls:\n");
    for (i = 1; i <= 6; i++) {
        printf("%d: %d\n", i, dice_rolls[i]);
    }

    return 0;
}