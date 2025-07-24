//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h> // Standard Input Output library.
#include <stdlib.h> // Standard library header file.
#include <time.h> // Date and Time library.

int main() {

    printf("Welcome to the Dice Roller!\n"); // Greeting message.

    printf("Are you ready to roll? Press Enter to continue...\n"); // Prompt message.
    getchar(); // Wait for user to press Enter.

    // Seed random number generator.
    srand(time(NULL));

    int roll; // Declare a variable to hold the roll value.

    for (int i = 0; i < 5; i++) { // Roll the dice 5 times.

        roll = (rand() % 6) + 1; // Generate a random number between 1 and 6.

        printf("Roll #%d: %d\n", i+1, roll); // Output the result.

        printf("Press Enter to roll again...\n"); // Prompt message.
        getchar(); // Wait for user to press Enter.
    }

    printf("Thanks for playing! Goodbye :)"); // Farewell message.

    return 0; // End of program.
}