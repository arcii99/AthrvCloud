//FormAI DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time.
    int num_dice, num_faces, total = 0; // Declare variables.

    printf("How many dice would you like to roll? "); 
    scanf("%d", &num_dice); // Get user input for number of dice to roll.

    printf("How many faces should the dice have? ");
    scanf("%d", &num_faces); // Get user input for number of faces on each die.

    printf("\nRolling %d %d-sided dice...\n\n", num_dice, num_faces); // Let the user know what's happening.

    for (int i = 0; i < num_dice; i++) { // Loop through each die.
        int roll = rand() % num_faces + 1; // Generate a random number between 1 and the number of faces.
        printf("Die %d: %d\n", i+1, roll); // Print the result of the roll.
        total += roll; // Add the roll to the running total.
    }

    printf("\nTotal: %d\n", total); // Print the final total.

    return 0; // Exit the program.
}