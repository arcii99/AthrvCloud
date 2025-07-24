//FormAI DATASET v1.0 Category: Game ; Style: calm
#include<stdio.h>

int main()
{
    // initialize variables`
    int secret_number = 7;
    int guess;
    int num_guesses = 0;
    char play_again = 'y';

    // loop while user wants to play again
    while (play_again == 'y') {
        printf("I'm thinking of a number between 1 and 10. Can you guess it?\n");
        scanf("%d", &guess);

        // loop while user has not guessed the secret number
        while (guess != secret_number) {
            // provide feedback
            if (guess < secret_number) {
                printf("Too low! Guess higher.\n");
            } else {
                printf("Too high! Guess lower.\n");
            }
            // prompt for new guess and increment number of guesses
            scanf("%d", &guess);
            num_guesses++;
        }

        // congratulate user and print number of guesses
        printf("Congratulations! You guessed it in %d tries.\n", num_guesses);

        // ask if user wants to play again
        printf("Do you want to play again? y/n\n");
        scanf(" %c", &play_again);

        // reset variables for new game
        secret_number = 7;
        guess = 0;
        num_guesses = 0;
    }

    printf("Thanks for playing!");

    return 0;
}