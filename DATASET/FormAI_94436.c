//FormAI DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // generate random seed
    printf("Welcome to the hilarious number guessing game!\n");
    printf("You have 5 guesses to guess the secret number between 0 and 1000.\n");

    int secret_num = rand() % 1000; // random number between 0-999
    int guess = -1;
    int attempts = 5;

    while (guess != secret_num && attempts > 0) {
        printf("You have %d attempts left.\n", attempts);
        printf("Enter your guess (0-1000): ");
        scanf("%d", &guess);

        if (guess < 0 || guess > 1000) {
            printf("Invalid guess, try again!\n");
            continue;
        }

        if (guess == secret_num) {
            printf("You guessed it! Congratulations!\n");
        } else if (guess < secret_num) {
            printf("Sorry, your guess is too low. Try again.\n");
            attempts--;
        } else {
            printf("Sorry, your guess is too high. Try again.\n");
            attempts--;
        }
    }

    if (attempts == 0) {
        printf("Sorry, you ran out of attempts. The secret number was %d. Better luck next time!\n", secret_num);
    }

    return 0;
}