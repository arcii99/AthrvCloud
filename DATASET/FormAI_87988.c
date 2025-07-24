//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, guess, attempts = 0;
    time_t t;

    // Initializing the random number generator
    srand((unsigned) time(&t));

    int randomNumber = rand() % 101; // Generating random number between 0 and 100

    printf("\nWelcome to the Guessing Game!\n");
    printf("\nYou must guess the number between 0 and 100.\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        if (guess < 0 || guess > 100) {
            printf("\nInvalid input. Please enter a number between 0 and 100.\n");
        }
        else if (guess < randomNumber) {
            printf("\nYour guess is too low. Try again.\n");
            attempts++;
        }
        else if (guess > randomNumber) {
            printf("\nYour guess is too high. Try again.\n");
            attempts++;
        }
        else {
            attempts++;
            printf("\nCongratulations! You've guessed the correct number in %d attempts.\n", attempts);
        }

    } while (guess != randomNumber);

    return 0;
}