//FormAI DATASET v1.0 Category: Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Genius Game!\n\n");

    int answer = 7;
    int guess = 0;
    int num_guesses = 0;

    printf("I'm thinking of a number between 1 and 10. Can you guess what it is?\n");

    while(guess != answer) {
        printf("Guess a number between 1 and 10: ");
        scanf("%d", &guess);
        num_guesses++;

        if(guess < answer) {
            printf("Too low! Try again.\n");
        } else if(guess > answer) {
            printf("Too high! Try again.\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d tries.\n", num_guesses);
        }
    }

    return 0;
}