//FormAI DATASET v1.0 Category: Dice Roller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Prompt user for number of dice and sides
    int num_dice, num_sides;
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides do the dice have? ");
    scanf("%d", &num_sides);

    // Roll the dice and print results
    int total = 0;
    for (int i = 0; i < num_dice; i++) {
        int roll = rand() % num_sides + 1;
        printf("Dice %d: %d\n", i+1, roll);
        total += roll;
    }

    // Print total
    printf("Total: %d\n", total);

    return 0;
}