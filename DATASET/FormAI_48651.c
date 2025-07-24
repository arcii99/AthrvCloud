//FormAI DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secretNumber, guess, attempts = 0;
    srand(time(0));  // generates random seed
    secretNumber = rand() % 100 + 1;  // generates random number between 1 and 100

    printf("\nWelcome to the Guessing Game! Can you guess the secret number between 1 and 100?\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("\nCongratulations! You guessed the secret number %d in %d attempts!\n\n", secretNumber, attempts);
            break;
        }

    } while (guess != secretNumber);

    return 0;
}