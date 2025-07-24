//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand(time(NULL));
    int num_guesses;
    printf("Welcome to the Number Guessing Game!\n");
    printf("How many guesses would you like?\n");
    scanf("%d", &num_guesses);

    int num_to_guess = rand() % 100 + 1;
    int guess;
    int num_remaining = num_guesses;

    printf("Guess a number between 1 and 100.\n");
    while (num_remaining > 0) {
        printf("You have %d guesses remaining.\n", num_remaining);
        scanf("%d", &guess);
        if (guess == num_to_guess) {
            printf("Congratulations, you guessed the number!\n");
            break;
        } else if (guess < num_to_guess) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Too high! Guess again.\n");
        }
        num_remaining--;
    }
    if (num_remaining == 0) {
        printf("Sorry, you ran out of guesses. The number was %d.\n", num_to_guess);
    }
    return 0;
}