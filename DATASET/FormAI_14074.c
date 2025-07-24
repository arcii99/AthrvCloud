//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get random number between min and max
int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int guess, numAttempts = 0;
    const int MIN_VALUE = 1, MAX_VALUE = 100;
    int secretNumber = getRandomNumber(MIN_VALUE, MAX_VALUE);
    printf("-----------------------------------\n");
    printf("\tGuess the number game\n");
    printf("-----------------------------------\n");
    printf("Guess a number between %d and %d: ", MIN_VALUE, MAX_VALUE);
    scanf("%d", &guess);
    numAttempts++;
    while (guess != secretNumber) {
        if (guess < secretNumber) {
            printf("Wrong! Too low.\n");
        } else {
            printf("Wrong! Too high.\n");
        }
        printf("Guess again: ");
        scanf("%d", &guess);
        numAttempts++;
    }
    printf("\nCongratulations! You guessed the right number in %d tries.\n", numAttempts);
    return 0;
}