//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 to 6
int roll_dice() {
    return (rand() % 6) + 1;
}

// Function to recursively roll dice and print the result
void roll_and_print(int num_rolls) {
    if(num_rolls > 0) {
        int roll = roll_dice();
        printf("Roll %d: %d\n", num_rolls, roll);
        roll_and_print(num_rolls - 1);
    }
}

int main() {
    int num_rolls;
    srand(time(NULL)); // Seed random number generator with current time
    
    // Get number of rolls input from user
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &num_rolls);
    
    // Roll the dice and print the result using recursive function
    printf("Rolling dice...\n\n");
    roll_and_print(num_rolls);
    printf("\nDone rolling!\n");
    
    return 0;
}