//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_GUESSES = 10;

int main() {
    int secret_num, guess, num_guesses = 0;
    srand(time(NULL));
    secret_num = rand() % 100 + 1; // Generate random number between 1 and 100
    printf("Welcome to the Guessing Game! I'm thinking of a number between 1 and 100.\n");
    while (num_guesses < MAX_GUESSES) {
        printf("Please enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;
        if (guess == secret_num) {
            printf("Congratulations! You guessed the number in %d tries.\n", num_guesses);
            return 0;
        } else if (guess < secret_num) {
            printf("Too low! ");
        } else {
            printf("Too high! ");
        }
        printf("You have %d guesses left.\n", MAX_GUESSES - num_guesses);
    }
    printf("Sorry, you ran out of guesses. The number was %d.\n", secret_num);
    return 0;
}