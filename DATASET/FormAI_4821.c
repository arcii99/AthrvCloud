//FormAI DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 6
int roll_dice() {
    srand(time(NULL));
    int dice_num = (rand() % 6) + 1;
    return dice_num;
}

int main() {
    // Declare variables to store number of rolls and sum of dice rolls
    int num_rolls = 0;
    int sum = 0;

    // Loop until user decides to stop rolling
    while (1) {
        // Ask user if they want to roll again
        char input;
        printf("Roll dice? (y/n): ");
        scanf(" %c", &input);

        // Check input and break loop if user doesn't want to roll again
        if (input == 'n' || input == 'N') {
            break;
        }

        // Roll dice and add to sum
        int roll = roll_dice();
        printf("Roll %d: %d\n", num_rolls+1, roll);
        sum += roll;
        num_rolls++;
    }

    // Print out total number of rolls and sum of dice rolls
    printf("Total rolls: %d\n", num_rolls);
    printf("Sum: %d\n", sum);

    return 0;
}