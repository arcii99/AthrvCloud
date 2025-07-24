//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A simple Terminal based game where the player has to guess the correct number */

int main(void) {
    int num, guess, tries = 0;
    srand(time(0)); /* Set the seed for random number generator */

    num = rand() % 100 + 1; /* Generate a random number between 1 and 100 */
    printf("\nWelcome to the Number Guessing Game! \nThe computer has a picked a number between 1 and 100. \nCan you guess what it is?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Your guess is too high! Guess again.\n");
        } else if (guess < num) {
            printf("Your guess is too low! Guess again.\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);

            /* Additional bonus feature to calculate score based on how many tries it took to guess */
            if (tries == 1) {
                printf("You are a GENIUS! You got a perfect score of 100\n");
            } else if (tries < 5) {
                printf("You got a score of 90\n");
            } else if (tries < 10) {
                printf("You got a score of 75\n");
            } else if (tries < 15) {
                printf("You got a score of 50\n");
            } else if (tries < 20) {
                printf("You got a score of 25\n");
            } else {
                printf("You got a score of 10\n");
            }
        }
    } while (guess != num);

    return 0;
}