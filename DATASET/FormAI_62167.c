//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int generateNumber() {
    srand(time(NULL));
    int randNum = rand() % 100 + 1;
    return randNum;
}

int main() {
    // Welcome message
    printf("Welcome to Guess the Number Game!\n");

    // Generate a random number
    int randNum = generateNumber();

    // Loop until the user guesses the correct number
    int guess;
    int tries = 0;
    while (1) {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        tries++;
        if (guess == randNum) {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
            break;
        } else if (guess < randNum) {
            printf("Sorry, the number is higher than your guess. Try again.\n");
        } else {
            printf("Sorry, the number is lower than your guess. Try again.\n");
        }
    }

    return 0;
}