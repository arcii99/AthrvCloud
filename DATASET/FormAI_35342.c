//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Generate random seed

    int guess, num, tries = 0, range;

    // Get the range of numbers from the user
    printf("Enter the range of numbers you want to guess from (e.g. 0 to 100): ");
    scanf("%d", &range);

    // Generate a random number between 1 and the range
    num = rand() % range + 1;

    // Loop until the user guesses the correct number
    while (guess != num) {
        printf("Guess a number between 1 and %d: ", range);
        scanf("%d", &guess);

        // Check if the guess is higher or lower than the generated number
        if (guess < num) {
            printf("Too low!\n");
        } else if (guess > num) {
            printf("Too high!\n");
        }

        tries++;  // Increment the number of tries
    }

    // Congratulate the user and display the number of tries it took
    printf("Congratulations! You guessed the number %d in %d tries.", num, tries);

    return 0;
}