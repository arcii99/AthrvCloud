//FormAI DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed random number generator

    int randomNumber = rand() % 100; // Generate a random number between 0 and 99

    int guess;
    int numGuesses = 0;

    printf("Guess a number between 0 and 99\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numGuesses++;

        if (guess < randomNumber) {
            printf("Too low. Try again.\n");
        }
        else if (guess > randomNumber) {
            printf("Too high. Try again.\n");
        }
        else {
            printf("Congratulations! You guessed the number in %d tries.\n", numGuesses);
        }
    } while (guess != randomNumber);

    return 0;
}