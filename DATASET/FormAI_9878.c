//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear screen
void clearScreen() {
    system("clear||cls");
}

int main() {
    srand(time(NULL)); // Seed for random numbers
    int randomNum = rand() % 100 + 1; // Generating random number between 1 and 100
    int guess = 0; // Initializing guess variable

    clearScreen(); // Clearing screen

    printf("\n\n\t\t***Welcome to Guess the Number Game!***\n\n");
    printf("\t\tGuess a number between 1 and 100.\n\n");

    // Loop until the user guesses the correct number
    while (guess != randomNum) {
        printf("\t\tEnter your guess: ");
        scanf("%d", &guess);

        if (guess < randomNum) {
            printf("\t\tToo low! Try again.\n\n");
        } else if (guess > randomNum) {
            printf("\t\tToo high! Try again.\n\n");
        } else {
            printf("\n\n\t\tCongratulations! You guessed the number %d.\n\n", randomNum);
        }
    }

    return 0;
}