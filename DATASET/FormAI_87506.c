//FormAI DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i, num_dice, num_sides, roll_sum = 0;
    int* results;
    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Welcome to the dice roller program!\n\n");

    // Get number of dice and sides from user
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides should each die have? ");
    scanf("%d", &num_sides);

    // Allocate space for an array to store the results
    results = (int*)malloc(num_dice * sizeof(int));

    // Roll the dice and store the results
    printf("\nRolling %d d%d...\n", num_dice, num_sides);
    for (i = 0; i < num_dice; i++) {
        results[i] = rand() % num_sides + 1;
        printf("Die %d: %d\n", i+1, results[i]);
        roll_sum += results[i];
    }
    printf("\nTotal: %d\n", roll_sum);

    // Free the dynamically allocated array
    free(results);

    return 0;
}