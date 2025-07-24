//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5

int main() {
    char play_again = 'y';
    int guess, number, num_guesses = 0, max_num = 10;

    printf("Welcome to the Guessing Game!\n");

    while (play_again == 'y') {
        // Generate random number
        srand(time(NULL));
        number = rand() % max_num + 1;

        printf("I'm thinking of a number between 1 and %d. You have %d guesses to get it right.\n", max_num, MAX_GUESSES);

        while (num_guesses < MAX_GUESSES) {
            printf("Enter your guess: ");
            scanf("%d", &guess);

            // Check if guess is correct
            if (guess == number) {
                printf("Congratulations, you guessed correctly!\n");
                break;
            } else {
                num_guesses++;
                printf("Sorry, that's not correct. You have %d guesses left.\n", MAX_GUESSES - num_guesses);
            }
        }

        // Check if player wants to play again
        printf("Do you want to play again? (y/n) ");
        scanf("%s", &play_again);
        num_guesses = 0;
    }

    printf("Thanks for playing the Guessing Game!\n");

    return 0;
}