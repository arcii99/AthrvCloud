//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROLLS_PER_LINE 10
#define SIDES_PER_DIE 6

// Function declaration
int rolldice(int dice);

int main(void) {
    int dice, rolls, total, roll;
    
    srand(time(NULL)); // Seed random number generator with current time
    
    // Prompt user for number of dice
    printf("Enter the number of dice to roll: ");
    scanf("%d", &dice);
    
    // Prompt user for the number of rolls
    printf("Enter the number of times to roll the dice: ");
    scanf("%d", &rolls);
    
    // Roll the dice the specified number of times and display the results
    for (int i = 1; i <= rolls; i++) {
        total = 0;
        printf("Roll %d: ", i);
        for (int j = 1; j <= dice; j++) {
            roll = rolldice(SIDES_PER_DIE);
            total += roll;
            printf("%d ", roll);
        }
        printf("(Total: %d)\n", total);
        if (i % ROLLS_PER_LINE == 0) {
            printf("\n"); // Start new line after every 10 rolls
        }
    }
    
    return 0;
}

// Returns a random number between 1 and sides, inclusive
int rolldice(int sides) {
    return rand() % sides + 1;
}