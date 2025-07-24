//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int secret_num, guess, num_guesses = 0;
    secret_num = rand() % 100 + 1;

    printf("\nWelcome to the Guessing Game!\n");
    printf("You have to guess a number between 1 and 100.\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess > secret_num) {
            printf("Too high. Try again.\n");
        }
        else if (guess < secret_num) {
            printf("Too low. Try again.\n");
        }
        else {
            printf("\nCongratulations! You guessed the number in %d guesses!\n\n", num_guesses);
        }

    } while (guess != secret_num);

    return 0;
}