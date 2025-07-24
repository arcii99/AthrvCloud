//FormAI DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice() {
    // Generate and return a random number between 1 and 6
    return (rand() % 6) + 1;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Declare variables to store the results of the dice rolls
    int roll1, roll2;

    // Get user input for number of dice to roll
    int num_rolls;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_rolls);

    // Roll the dice the specified number of times and display the results
    printf("Rolling %d dice...\n\n", num_rolls);

    for (int i = 1; i <= num_rolls; i++) {
        roll1 = roll_dice();
        roll2 = roll_dice();

        // Print the results of each roll
        printf("Roll %d: %d + %d = %d\n", i, roll1, roll2, roll1 + roll2);
    }

    return 0;
}