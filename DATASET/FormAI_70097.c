//FormAI DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5
#define MAX_NUMBER 100

int main(void) {
    int secretNum, guess, numGuesses = 0;
    srand(time(0)); // seed the random number generator
    secretNum = rand() % MAX_NUMBER + 1; // generate a random number between 1 and 100
    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numGuesses++;
        if (guess > secretNum) {
            printf("Too high! Try again.\n");
        } else if (guess < secretNum) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations, you guessed correctly!\n");
            break;
        }
    } while (numGuesses < MAX_GUESSES);
    if (numGuesses == MAX_GUESSES) {
        printf("Sorry, you ran out of guesses. The number was %d.\n", secretNum);
    }
    return 0;
}