//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, answer, num_guesses = 0;
    char play_again;

    srand(time(NULL)); // seed random number generator
    answer = rand() % 100 + 1; // generate random number between 1 and 100

    printf("*** WELCOME TO THE GUESSING GAME! ***\n");

    do {
        printf("Guess the number between 1 and 100 (inclusive): ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess == answer) {
            printf("Congratulations! You guessed the number in %d tries!\n", num_guesses);
        } else if (guess < answer) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing! Goodbye!\n");

    return 0;
}