//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Seed for random number generator

    int random_num = rand() % 10 + 1; // Generate a random number between 1 and 10

    printf("Welcome to the Guessing Game! Can you guess the secret number?\n");

    int guess;
    int num_guesses = 0;

    do {

        printf("Enter your guess: ");
        scanf("%d", &guess);

        num_guesses++;

        if (guess > random_num) {
            printf("Too high!\n");
        } else if (guess < random_num) {
            printf("Too low!\n");
        } else {
            printf("Congratulations, you won! It took you %d guesses.\n", num_guesses);
        }

    } while (guess != random_num);

    return 0;
}