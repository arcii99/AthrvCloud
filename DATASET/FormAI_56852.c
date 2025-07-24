//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to randomly generate a number between 1 and 100
int generateRandomNumber() {
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    return rand() % 100 + 1;
}

int main() {
    // Greeting message and game instructions
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have to guess a random number between 1 and 100\n");
    printf("You have 10 chances to get it right\n");

    // generate the random number to guess
    int numberToGuess = generateRandomNumber();
    int guessedNumber;

    // loop for 10 chances or until the correct number is guessed
    for (int i = 0; i < 10; i++) {
        printf("Enter your guessed number: ");
        scanf("%d", &guessedNumber);

        if (guessedNumber < numberToGuess) {
            printf("Your guess is too low\n");
        } else if (guessedNumber > numberToGuess) {
            printf("Your guess is too high\n");
        } else {
            printf("Congratulations! You have guessed the correct number in %d attempts\n", i+1);
            return 0;
        }
    }

    // if the correct number is not guessed in 10 attempts
    printf("Sorry, you did not guess the correct number\n");
    printf("The number was %d\n", numberToGuess);
    return 0;
}