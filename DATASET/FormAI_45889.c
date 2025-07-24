//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, random_num, attempt_limit = 5, attempts = 0;
    char play_again = 'y';

    // initialize random seed
    srand(time(NULL));

    printf("Welcome to the Guessing Game!\n");

    while (play_again == 'y') {
        random_num = rand() % 100 + 1; // generate a random number between 1-100
        printf("A random number has been generated. You have %d attempts to guess it.\n", attempt_limit);

        while (attempts < attempt_limit) {
            printf("Guess #%d: ", attempts+1);
            scanf("%d", &guess);

            if (guess < random_num) {
                printf("Your guess is too low.\n");
            } else if (guess > random_num) {
                printf("Your guess is too high.\n");
            } else {
                printf("Congratulations! You guessed the number in %d attempt(s).\n", attempts+1);
                break;
            }

            attempts++;
        }

        if (attempts == attempt_limit) {
            printf("Sorry, you did not guess the number within the %d attempts limit. The number was %d.\n", attempt_limit, random_num);
        }

        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &play_again);

        attempts = 0; // reset attempts counter for new game
    }

    printf("Thanks for playing the Guessing Game!");

    return 0;
}