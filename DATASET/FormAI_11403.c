//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_number(int max) {
    srand(time(NULL)); // initialize random number generator only once
    return rand() % max;
}

int main() {
    // initialize game
    int max_guesses = 5;
    int number = random_number(100);
    int i, guess;
    printf("Welcome to the number guessing game!\n");
    printf("I'm thinking of a number between 0 and 100, can you guess it in %d tries?\n", max_guesses);

    // game loop
    for (i = 1; i <= max_guesses; i++) {
        printf("Guess #%d: ", i);
        scanf("%d", &guess);

        if (guess == number) {
            printf("Congrats! You guessed the number in %d attempts.\n", i);
            return 0;
        } else if (guess < number) {
            printf("Too low, try again.\n");
        } else {
            printf("Too high, try again.\n");
        }
    }

    // game over
    printf("Sorry, you ran out of guesses. The number I was thinking of was %d.\n", number);
    return 0;
}