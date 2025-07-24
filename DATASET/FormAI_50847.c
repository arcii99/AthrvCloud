//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int isRunning = 1;

    printf("Welcome to the Number Guessing Game!\n");

    while (isRunning) {
        // Generate a random number between 1 and 10
        srand(time(NULL));
        int randomNumber = rand() % 10 + 1;

        printf("Guess a number between 1 and 10: ");

        // Get user input
        int guess;
        scanf("%d", &guess);

        // Check if guess is correct
        if (guess == randomNumber) {
            score++;
            printf("Correct! Your score is now %d.\n", score);
        } else {
            printf("Wrong! The correct number was %d.\n", randomNumber);
            printf("Game Over! Your final score was %d.\n", score);

            // Ask user if they want to play again
            printf("Do you want to play again? (1 for yes / 0 for no): ");
            int playAgain;
            scanf("%d", &playAgain);

            if (playAgain == 1) {
                score = 0;
            } else {
                isRunning = 0;
            }
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}