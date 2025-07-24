//FormAI DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateRandomNumber(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    // Variables for game
    int lowerBound = 1, upperBound = 100, guess;
    int randomNum = generateRandomNumber(lowerBound, upperBound);
    int attempts = 0;

    // Instructions for user
    printf("Guess the number between %d and %d\n", lowerBound, upperBound);

    // Loop until the correct number is guessed
    do {
        printf("Guess #%d: ", attempts+1);
        scanf("%d", &guess);

        // Check if guess is within range
        if (guess < lowerBound || guess > upperBound) {
            printf("Invalid guess. Number must be between %d and %d\n", lowerBound, upperBound);
            continue; // restart loop
        }

        // Increment attempts counter
        attempts++;

        // Compare guess with random number
        if (guess > randomNum) {
            printf("Too high!\n");
        } else if (guess < randomNum) {
            printf("Too low!\n");
        } else {
            printf("Congratulations, you guessed the number in %d attempt(s)!\n", attempts);
        }

    } while (guess != randomNum);

    return 0;
}