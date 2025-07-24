//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 100
int generateRandomNum() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

int main() {
    int randomNumber = generateRandomNum();
    int guess, attempts = 0;
    printf("\nWelcome to the Guessing Game!\n\n");
    printf("You have 5 attempts to guess a number between 1 and 100.\n\n");

    // Game loop
    while (attempts < 5) {
        printf("Attempt %d: ", attempts + 1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Invalid input! Guess must be between 1 and 100.\n\n");
            continue;
        }

        if (guess == randomNumber) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts + 1);
            return 0;
        } else if (guess < randomNumber) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Too high! Guess again.\n");
        }

        attempts++;
        printf("\n");
    }

    // Game over
    printf("Game over! The number was %d.\n", randomNumber);
    return 0;
}