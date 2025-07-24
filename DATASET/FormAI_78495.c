//FormAI DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is a mind-bending C program that simulates the rolling of a dice

int main() {
    int num_sides, num_dice, i, j, roll_total;
    char play_again = 'y';
    
    srand(time(NULL)); // Seed random number generator with current time
    
    printf("Welcome to the Dice Roller!\n");
    printf("----------------------------\n");
    
    // Loop until user doesn't want to play again
    while (play_again == 'y') {
        roll_total = 0; // Reset the roll total for each new roll
        
        // Get input from user for number of sides on dice
        printf("How many sides should the dice have? ");
        scanf("%d", &num_sides);
        
        // Get input from user for number of dice to roll
        printf("How many dice should be rolled? ");
        scanf("%d", &num_dice);
        
        // Roll the dice
        printf("\nRolling %d %d-sided dice...\n\n", num_dice, num_sides);
        for (i = 0; i < num_dice; i++) {
            int roll = rand() % num_sides + 1; // Generate random roll between 1 and num_sides
            printf("Dice %d: %d\n", i+1, roll); // Print out the roll for this die
            roll_total += roll; // Add the roll to the total
        }
        
        // Print the total of all the rolls
        printf("\nTotal roll: %d\n", roll_total);
        
        // Ask user if they want to play again
        printf("\nDo you want to roll again? (y/n) ");
        scanf(" %c", &play_again);
        printf("\n");
    }
    
    printf("Thanks for playing the Dice Roller!\n");
    
    return 0;
}