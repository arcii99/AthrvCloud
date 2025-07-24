//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0, guess, randomNumber;
    srand(time(NULL)); // seed the random number generator

    printf("--------Guess the Number Game--------\n");
    printf("Each correct guess scores 10 points.\n\n");

    // loop until the player decides to quit
    while (1) {
        randomNumber = rand() % 100 + 1; // generate a random number between 1 and 100

        printf("Guess the number (1-100) or enter 0 to quit: ");
        scanf("%d", &guess);

        if (guess == 0) {
            printf("Final score: %d\nThanks for playing!\n", score);
            break;
        }

        if (guess == randomNumber) {
            printf("Congratulations! You guessed the number.\n");
            score += 10; // add 10 points to the score for a correct guess
        } else {
            printf("Sorry, the number was %d.\n", randomNumber);
        }

        printf("Current score: %d\n\n", score);
    }

    return 0;
}