//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(NULL)); // seed the random number generator with the current time

    int answer = rand() % 100 + 1; // generate a random number between 1 and 100, inclusive

    printf("Welcome to the number guessing game!\n");
    printf("Guess a number between 1 and 100:\n");

    int guess;
    scanf("%d", &guess); // get the user's guess

    int num_guesses = 1; // keep track of the number of guesses

    while (guess != answer)
    {
        num_guesses++; // increment the number of guesses

        if (guess < answer)
        {
            printf("Too low! Guess again:\n");
        }
        else
        {
            printf("Too high! Guess again:\n");
        }

        scanf("%d", &guess); // get the user's new guess
    }

    printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses);
    printf("Press enter to exit.\n");
    getchar(); // wait for enter to be pressed before exiting

    return 0;
}