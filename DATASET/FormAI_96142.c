//FormAI DATASET v1.0 Category: Dice Roller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of dice to roll and the number of sides on each dice
#define NUM_DICE 3
#define NUM_SIDES 6

// Define a struct to hold the results of the dice rolls
typedef struct {
    int results[NUM_DICE];
    int total;
} RollResult;

// Define a function to roll a single dice and return the result
int roll_dice() {
    return rand() % NUM_SIDES + 1;
}

// Define a function to roll the specified number of dice and return the results
RollResult roll_dice_set() {
    RollResult result;
    result.total = 0;
    for (int i = 0; i < NUM_DICE; i++) {
        result.results[i] = roll_dice();
        result.total += result.results[i];
    }
    return result;
}

// Define the entry point for the program
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    RollResult result = roll_dice_set();
    printf("You rolled %d dice with %d sides each.\n", NUM_DICE, NUM_SIDES);
    for (int i = 0; i < NUM_DICE; i++) {
        printf("Dice %d rolled a %d.\n", i + 1, result.results[i]);
    }
    printf("The total of the dice rolls is %d.\n", result.total);
    return 0;
}