//FormAI DATASET v1.0 Category: Dice Roller ; Style: secure
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int roll_dice();

int main() {
    int num_rolls;

    // Get number of rolls from user
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &num_rolls);

    // Seed the random number generator
    srand(time(NULL));

    // Roll the dice and print the result
    printf("Rolling the dice %d times...\n", num_rolls);
    for (int i = 1; i <= num_rolls; i++) {
        int roll = roll_dice();
        printf("Roll %d: %d\n", i, roll);
    }

    return 0;
}

// Function to roll a single die
int roll_dice() {
    return rand() % 6 + 1;
}