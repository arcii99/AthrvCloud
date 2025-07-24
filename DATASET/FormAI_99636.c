//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0; // Declare variables

    srand(time(0)); // Seed random number generator
    num = rand() % 100 + 1; // Generate random number between 1 and 100

    // Game instructions
    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("You have to guess what that number is.\n");
    printf("You have 10 chances to guess the number.\n");

    // Loop until player runs out of tries or guesses correctly
    do {
        tries++; // Increment try count
        printf("Guess #%d: ", tries);
        scanf("%d", &guess);

        // Check if guess is too high or too low
        if (guess > num) {
            printf("Too high!\n");
        } else if (guess < num) {
            printf("Too low!\n");
        }
    } while (guess != num && tries < 10);

    // Check if player won or lost
    if (guess == num) {
        printf("Congratulations! You guessed the number in %d tries!\n", tries);
    } else {
        printf("Sorry, you ran out of tries. The number was %d.\n", num);
    }

    return 0;
}