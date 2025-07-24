//FormAI DATASET v1.0 Category: Dice Roller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_dice, num_sides;

    printf("Welcome to Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides should these dice have? ");
    scanf("%d", &num_sides);

    // Seed the random number generator
    srand(time(NULL));

    // Roll the dice
    printf("\nRolling %d %d-sided dice...\n", num_dice, num_sides);
    int total = 0;
    for (int i = 1; i <= num_dice; i++) {
        int result = rand() % num_sides + 1;
        printf("Die %d: %d\n", i, result);
        total += result;
    }
    printf("\nTotal: %d\n", total);

    return 0;
}