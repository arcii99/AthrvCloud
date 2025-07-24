//FormAI DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between 1-100
int generateRandomNumber() {
    srand(time(NULL));
    return (rand() % 100) + 1;
}

// function to check if guess is correct or not
void checkGuess(int guess, int answer) {
    if (guess == answer) {
        printf("Congratulations! Your guess %d is correct!\n", guess);
    } else if (guess < answer) {
        printf("Your guess %d is too low. Try again!\n", guess);
    } else {
        printf("Your guess %d is too high. Try again!\n", guess);
    }
}

int main() {
    int answer = generateRandomNumber();
    int guess;

    printf("Welcome to the Guessing Game!\n");
    printf("You have to guess a number between 1-100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        checkGuess(guess, answer);
    } while (guess != answer);

    return 0;
}