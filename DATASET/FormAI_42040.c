//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkGuess(int guess, int answer) {
    if (guess == answer) {
        printf("You guessed correctly!\n");
        return 1;
    } else if (guess < answer) {
        printf("Too low. Guess again.\n");
        return 0;
    } else {
        printf("Too high. Guess again.\n");
        return 0;
    }
}

int main() {
    int answer, guess;
    int maxNumber = 100;
    srand(time(NULL));
    answer = rand() % maxNumber;
    printf("Welcome to the guessing game! I am thinking of a number between 0 and %d. Can you guess it?\n", maxNumber);

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
    } while (!checkGuess(guess, answer));

    return 0;
}