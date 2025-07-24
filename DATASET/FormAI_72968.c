//FormAI DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// The above libraries are required for this Dice Roller program.

int main() {
    int dice; // Initialize dice value.
    int sides = 6; // Set number of sides on the dice (in this case, default 6 sides).
    int roll_again = 1; // Initialize "roll_again" variable to allow user to roll dice again.

    // Print out a unique welcome message!
    printf("Welcome to the exciting Dice Roller program! Get ready to roll the dice!\n\n");

    // Allow user to input number of sides for the dice.
    printf("How many sides would you like to have on your dice (minimum 1)? ");
    scanf("%d", &sides);
    printf("\n");

    /* While loop will allow the user to continue rolling the dice 
    until they decide they no longer want to roll again ("roll_again" == 0)*/
    while (roll_again == 1) {
        printf("Rolling the dice...\n");
        srand(time(0)); // Seed the random number generator.

        // Generate and print out a random number between 1 and the number of sides on the dice.
        dice = (rand() % sides) + 1;
        printf("The dice landed on %d!\n\n", dice);

        /* Ask the user if they want to roll again - 
        1 for "Yes" and 0 for "No" (stop the program)*/
        printf("Would you like to roll the dice again? (1 for Yes or 0 for No)");
        scanf("%d", &roll_again);
        printf("\n");
    }

    /* Thank the user for playing this fun and exciting game 
    (and for being an amazing coder) */
    printf("Thank you for playing the Dice Roller program! We hope you enjoyed it!\n");

    return 0;
}