//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playGame(int guess) {
    int number = rand() % 100 + 1;
    if (guess == number) {
        printf("Congratulations! You guessed it correctly.");
        return 1;
    } else if (guess < number) {
        printf("Too low! Guess again.\n");
    } else {
        printf("Too high! Guess again.\n");
    }
    return playGame(guess);
}

int main() {
    int guess;
    srand(time(NULL));
    printf("Welcome to the Guessing Game!\n");
    printf("I have a number between 1 and 100. Can you guess what it is?\n");
    printf("Enter your guess: ");
    scanf("%d", &guess);
    playGame(guess);
    return 0;
}