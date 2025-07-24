//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize necessary variables
    int guess, numAttempts = 0, num, range;
    char playAgain = 'y';

    // Seed random number generator
    srand(time(0));

    printf("Welcome to the Guessing Game! \n");
    printf("Enter the range of numbers to guess from (1-1000 recommended): ");
    scanf("%d", &range);

    while (playAgain == 'y') {
        // Generate random number within given range
        num = rand() % range + 1;
        printf("\nI have chosen a number. Try to guess it!\n");

        while (guess != num) {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            numAttempts++;

            // Check if guess is correct and provide feedback
            if (guess == num) {
                printf("Congratulations! You guessed the number in %d attempts!\n", numAttempts);
            } else if (guess < num) {
                printf("Sorry, your guess was too low. Try again.\n");
            } else {
                printf("Sorry, your guess was too high. Try again.\n");
            }
        }

        // Ask if player wants to play again
        printf("\nWould you like to play again? (y/n)\n");
        scanf(" %c", &playAgain);

        // Reset necessary variables for new game
        numAttempts = 0;
        guess = 0;
    }

    printf("Thanks for playing the Guessing Game!\n");
    return 0;
}