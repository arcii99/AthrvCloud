//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guesses = 0;
    int number, guess;
    srand(time(0)); // seed random number generator
    number = rand() % 100 + 1; // generate random number between 1 and 100
    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guesses++;

        if (guess > number) {
            printf("Sorry, your guess is too high. Try again.\n");
        }
        else if (guess < number) {
            printf("Sorry, your guess is too low. Try again.\n");
        }
        else {
            printf("Congratulations, you guessed the number in %d guesses!\n", guesses);
        }
    } while (guess != number);

    return 0;
}