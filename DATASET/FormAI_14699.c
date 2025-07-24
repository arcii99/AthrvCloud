//FormAI DATASET v1.0 Category: Dice Roller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, rolls, i, total = 0;

    // Seed the random number generator with current system time
    srand(time(NULL));

    // Prompt the user for the number of sides on the dice
    printf("How many sides does your dice have? ");
    scanf("%d", &sides);

    // Prompt the user for the number of rolls to perform
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &rolls);

    // Roll the dice
    for (i = 0; i < rolls; i++) {
        int roll = rand() % sides + 1; // Generate random number between 1 and the number of sides
        printf("Roll #%d: %d\n", i+1, roll);
        total += roll; // Add the roll to the running total
    }

    // Print the total and average of all the rolls
    printf("Total: %d\n", total);
    printf("Average: %.2f\n", (float)total/rolls);

    return 0;
}