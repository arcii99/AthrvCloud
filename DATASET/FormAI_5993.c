//FormAI DATASET v1.0 Category: Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed random number generator with current time
    int secret_number = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess;
    int tries = 0;

    printf("Welcome to Guess the Number!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        tries++;

        if (guess > secret_number) {
            printf("Your guess is too high. Try again.\n");
        } else if (guess < secret_number) {
            printf("Your guess is too low. Try again.\n");
        }
    } while (guess != secret_number);

    printf("Congratulations! You guessed the number in %d tries!\n", tries);

    return 0;
}