//FormAI DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h> // Standard Input-Output library
#include <stdlib.h> // Standard library

int main() {
    int dice; // Declare variable to represent the dice
    char input; // Declare variable to represent user input
    do {
        printf("How many sides does your dice have? "); // Prompt user for the number of sides on their dice
        scanf("%d", &dice); // Read user input
        if (dice <= 0) { // Check if the number of sides is greater than zero
            printf("Invalid input. Please enter a positive integer.\n"); // Display error message
        }
    } while (dice <= 0); // Continue prompting user until they enter a valid input
    do {
        printf("Roll the dice? (y/n) "); // Prompt user to roll the dice
        scanf(" %c", &input); // Read user input
        if (input == 'y') { // Check if user wants to roll the dice
            int result = rand() % dice + 1; // Generate a random number between 1 and the number of sides on the dice
            printf("Your roll was: %d\n", result); // Display the result of the roll
        } else if (input != 'n') { // Check if user inputs anything other than 'n'
            printf("Invalid input. Please enter 'y' or 'n'.\n"); // Display error message
        }
    } while (input != 'n'); // Continue rolling the dice until the user chooses to stop
    return 0; // Return control to the operating system
}