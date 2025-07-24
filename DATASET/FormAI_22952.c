//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate random numbers between 1 and 100
int generate_number() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

int main() {
    int number_to_guess = generate_number();
    int guess;
    int attempt = 1;
    char play_again = 'y';

    while (play_again == 'y') {
        printf("\nWelcome to Guess the Number Game!\n");
        printf("I'm thinking of a number between 1 and 100...\n");

        while (guess != number_to_guess) {
            printf("\nAttempt #%d: Enter your guess: ", attempt);
            scanf("%d", &guess);

            if (guess < number_to_guess) {
                printf("\nSorry, my number is higher than that.\n");
                attempt++;
            } else if (guess > number_to_guess) {
                printf("\nSorry, my number is lower than that.\n");
                attempt++;
            } else {
                printf("\nCongratulations! You guessed my number in %d attempts!\n", attempt);
            }
        }

        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &play_again);

        if (play_again == 'y') {
            number_to_guess = generate_number();
            guess = 0;
            attempt = 1;
        }
    }

    printf("\nThanks for playing!\n");

    return 0;
}