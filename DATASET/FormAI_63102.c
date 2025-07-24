//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator

    int score = 0; // initialize score to zero
    int num_guesses = 0; // initialize number of guesses to zero
    int target_num = rand() % 100 + 1; // generate random target number between 1 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("You have 5 attempts to guess the number between 1 and 100.\n");

    while (num_guesses < 5) {
        int guess;
        printf("Guess #%d: ", num_guesses+1);
        scanf("%d", &guess);

        if (guess == target_num) {
            printf("You guessed the number! Congratulations!\n");
            score += 10; // add 10 points for correct guess
            break;
        } else if (guess < target_num) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        num_guesses++;
    }

    if (num_guesses == 5) {
        printf("Sorry, you ran out of guesses. The number was %d.\n", target_num);
    }

    printf("Your final score is %d.\n", score);

    return 0;
}