//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0)); // Seed the random number generator with the current time
    int num = rand() % 100 + 1; // Generate a random number between 1 and 100
  
    printf("Welcome to the Number Guessing Game!\n\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    int guess; // User's guess
    int numOfGuesses = 0; // Number of guesses made

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        numOfGuesses++;

        if (guess < num) 
            printf("Too low. Guess again.\n");
        else if (guess > num) 
            printf("Too high. Guess again.\n");
    } while (guess != num);

    printf("\nCongratulations, you guessed the number in %d guesses!\n", numOfGuesses);

    return 0;
}