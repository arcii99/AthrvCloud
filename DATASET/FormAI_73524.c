//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5 // Maximum number of attempts allowed.

int main()
{
    int randomNumber, guess, attempts, i;

    srand(time(0)); // Set the random seed.

    randomNumber = rand() % 100 + 1; // Generate a random number between 1 and 100.

    printf("\n\nWelcome to the Number Guessing Game!\n\n");
    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n\n");

    attempts = 0;

    while (attempts < MAX_TRIES) {
        printf("Enter your guess (attempt %d): ", attempts + 1);
        scanf("%d", &guess);

        if (guess == randomNumber) {
            printf("Congratulations! You guessed the number in %d attempts!\n", attempts + 1);
            break;
        }
        else if (guess < randomNumber) {
            printf("Too low! ");
        }
        else {
            printf("Too high! ");
        }

        attempts++;
        printf("You have %d tries left.\n\n", MAX_TRIES - attempts);
    }

    if (attempts == MAX_TRIES) {
        printf("Sorry, you failed to guess the number in %d attempts. The number was %d.\n", MAX_TRIES, randomNumber);
    }

    return 0;
}