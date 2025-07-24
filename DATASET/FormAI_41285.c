//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Welcome message
    printf("Welcome to the exciting dice game!\n");

    int playerTotal = 0;
    int computerTotal = 0;
    srand(time(NULL)); // Seed the random number generator
    
    // Game loop
    while (1) {
        printf("\nYour turn:\n");

        // Roll the dice
        int roll1 = rand() % 6 + 1;
        int roll2 = rand() % 6 + 1;
        printf("You rolled: %d and %d\n", roll1, roll2);
        playerTotal += roll1 + roll2;

        // Check for a win
        if (playerTotal >= 100) {
            printf("Congratulations! You win!\n");
            break;
        }

        printf("Your total is now %d\n\n", playerTotal);

        printf("Computer's turn:\n");

        // Roll the dice
        int computerRoll = rand() % 6 + 1;
        computerTotal += computerRoll;

        // Check for a win
        if (computerTotal >= 100) {
            printf("Sorry, the computer wins.\n");
            break;
        }

        printf("The computer rolled: %d\n", computerRoll);
        printf("The computer's total is now %d\n", computerTotal);
    }

    return 0;
}