//FormAI DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, num_guesses = 0;

    // Generate a random number between 1 and 100
    srand(time(NULL));
    num = rand() % 100 + 1;

    printf("Welcome to Guess the Number!\n");
    printf("I'm thinking of a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess > num) {
            printf("Too high! Try again.\n");
        } else if (guess < num) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations, you guessed the number in %d guesses!\n", num_guesses);
        }
    } while (guess != num);

    return 0;
}