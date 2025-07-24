//FormAI DATASET v1.0 Category: Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    // Declare variables
    int num, guess, numGuesses = 0;
    time_t t;

    // Initialize random seed
    srand((unsigned) time(&t));

    // Generate random number
    num = generateRandomNumber(1, 100);

    // Game instructions
    printf("Welcome to the Guessing Game!\nGuess a number between 1 and 100.\n");

    // Game loop
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < num) {
            printf("Your guess is too low.\n");
            numGuesses++;
        } else if (guess > num) {
            printf("Your guess is too high.\n");
            numGuesses++;
        } else {
            numGuesses++;
            printf("Congratulations! You guessed the number in %d attempts.\n", numGuesses);
        }
    } while (guess != num);

    return 0;
}