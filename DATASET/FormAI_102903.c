//FormAI DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice() {    // Function to roll the dice
    return (rand() % 6) + 1;
}

int main() {
    int dice_rolls[6] = {0};   // Array to count the number of times each number is rolled
    int num_rolls;
    printf("Enter the number of times to roll the dice: ");
    scanf("%d", &num_rolls);
    srand(time(NULL));   // Setting the seed for the random number generator

    for (int i = 0; i < num_rolls; i++) {
        int roll = roll_dice();
        printf("Roll %d: %d\n", i+1, roll);
        dice_rolls[roll-1]++;   // Incrementing the count for that number
    }

    printf("\nHere's a summary of how many times each number was rolled:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d: %d\n", i+1, dice_rolls[i]);
    }

    return 0;
}