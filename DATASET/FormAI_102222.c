//FormAI DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Initialize the game
    int secret_num, guess, num_guesses = 0;
    srand(time(NULL));
    secret_num = rand() % 100 + 1;
    printf("Welcome to the Guess the Number game!\n\n");

    //Start the game
    while (1) {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &guess);
        num_guesses++;

        //Check the guess
        if (guess == secret_num) {
            printf("Congratulations! You guessed the secret number in %d guesses!\n", num_guesses);
            break;
        } else if (guess < secret_num) {
            printf("Your guess is too low. Try again!\n");
        } else {
            printf("Your guess is too high. Try again!\n");
        }

        //Maximum number of guesses reached
        if (num_guesses == 10) {
            printf("Sorry, you have reached the maximum number of guesses.\nThe secret number was %d.\n", secret_num);
            break;
        }
    }

    return 0;
}