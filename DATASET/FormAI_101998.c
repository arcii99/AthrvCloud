//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

int main() {
    int randomNumber = generateRandomNumber();
    int attempts = 0;
    int guess;

    printf("Welcome to the guessing game!\n");
    printf("You have to guess a number between 1 and 100\n");

    // Loop to keep asking the user for a guess until they get it right
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < 1 || guess > 100) {
            printf("Invalid guess! Please enter a number between 1 and 100\n");
            continue;
        }

        if (guess < randomNumber) {
            printf("Too low! Try again\n");
        } else if (guess > randomNumber) {
            printf("Too high! Try again\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts\n", attempts);
            break;
        }
    }

    return 0;
}