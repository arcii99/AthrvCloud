//FormAI DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll dice with given number of sides
int roll_dice(int sides) {
    return rand() % sides + 1;
}

int main() {
    int sides, num_dice, i, total = 0;

    // Seed the random number generator with the current time
    srand(time(NULL));

    printf("Welcome to the futuristic C dice roller! Please enter the number of sides on the dice: ");
    scanf("%d", &sides);

    printf("Please enter the number of dice you want to roll: ");
    scanf("%d", &num_dice);

    printf("Rolling %d %d-sided dice...\n", num_dice, sides);

    // Roll the dice and keep a running total
    for (i = 0; i < num_dice; i++) {
        int roll = roll_dice(sides);
        printf("Dice %d: %d\n", i + 1, roll);
        total += roll;
    }

    printf("Total: %d\n", total);

    return 0;
}