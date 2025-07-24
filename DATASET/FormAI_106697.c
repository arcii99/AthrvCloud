//FormAI DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100
#define MAX_TRIES 7

int main()
{
    int guess, secretNumber, attempt = 0;
    srand(time(NULL)); // initialize random number generator with current time

    secretNumber = rand() % MAX_NUMBER + 1; // generate a random number between 1-100

    printf("Guess the secret number (between 1 and 100) in %d tries.\n", MAX_TRIES);

    do {
        printf("Attempt %d: Enter your guess: ", attempt + 1);
        scanf("%d", &guess);

        if (guess < secretNumber) {
            printf("Too low.\n");
        } else if (guess > secretNumber) {
            printf("Too high.\n");
        }

        attempt++; // increment the attempt counter
    } while (guess != secretNumber && attempt < MAX_TRIES);

    if (guess == secretNumber) {
        printf("Congratulations! You guessed the secret number in %d tries!\n", attempt);
    } else {
        printf("Sorry, the secret number was %d. Better luck next time!\n", secretNumber);
    }

    return 0;
}