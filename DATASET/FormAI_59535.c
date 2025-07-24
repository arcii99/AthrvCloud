//FormAI DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, num_guesses = 0;
    srand(time(NULL)); // seed random generator with current time
    number = rand() % 101; // generate random number between 0 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 0 and 100.\n");

    do {
        printf("Guess the number: ");
        scanf("%d", &guess);
        num_guesses++; // increment number of guesses
        if (guess < number) {
            printf("Too low, try again.\n");
        } else if (guess > number) {
            printf("Too high, try again.\n");
        }
    } while (guess != number);

    printf("Congratulations, you guessed the number in %d guesses!\n", num_guesses);

    return 0;
}