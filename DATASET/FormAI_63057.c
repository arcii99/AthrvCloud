//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Introduction
    printf("********************************\n");
    printf("*        NUMBER GUESSER        *\n");
    printf("********************************\n");

    printf("Welcome to the Number Guesser game!\n\n");
    printf("The game will randomly generate a number between 1 and 100, and it will be your job to guess the number.\n\n");

    printf("You will get 10 chances to guess the number.\n\n");

    printf("Let's begin!\n\n");

    // Generate random number
    srand(time(NULL));
    int number = rand() % 100 + 1;
    int guess, guess_count = 0;

    // Get user guesses
    while (guess_count < 10) {
        printf("Guess #%d: ", guess_count + 1);
        scanf("%d", &guess);

        // Check if guess is correct
        if (guess == number) {
            printf("\nCongratulations! You guessed the number in %d attempts.\n", guess_count + 1);
            return 0;
        }

        // Check if guess is too high or too low
        if (guess > number) {
            printf("Your guess is too high. ");
        } else {
            printf("Your guess is too low. ");
        }

        printf("You have %d guesses left.\n\n", 10 - guess_count - 1);

        guess_count++;
    }

    printf("\nSorry, you didn't guess the number. The number was %d.\n", number);
    return 0;
}