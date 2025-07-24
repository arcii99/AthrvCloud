//FormAI DATASET v1.0 Category: Dice Roller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to generate a random number between 1 and 6
int roll_dice() {
    return (rand() % 6) + 1;
}

int main() {
    int num_rolls = 0;
    int total_score = 0;
    int dice1 = 0;
    int dice2 = 0;

    printf("Welcome to the dice roller program!\n\n");
    
    // Prompt user for number of rolls
    printf("How many rolls would you like to perform: ");
    scanf("%d", &num_rolls);
    printf("\n");

    // Roll the dice and print out the results
    for (int i = 0; i < num_rolls; i++) {
        dice1 = roll_dice();
        dice2 = roll_dice();
        int roll_sum = dice1 + dice2;
        total_score += roll_sum;
        printf("Roll %d: Dice 1 = %d, Dice 2 = %d, Total score = %d\n", i+1, dice1, dice2, roll_sum);
    }

    // Print out total score
    printf("\nTotal score for %d rolls: %d\n", num_rolls, total_score);

    return 0;
}