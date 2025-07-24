//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setting up the game
    srand(time(NULL));
    int secretNumber = rand() % 100 + 1;
    int attempt = 1;
    int guess;

    // Displaying welcome message
    printf("\n\nWelcome to Guess the Secret Number game!\n");
    printf("----------------------------------------\n\n");
    printf("I have chosen a number between 1 and 100. You have to guess it within 10 attempts. Good luck!\n\n");

    // Starting the game
    while (attempt <= 10) {
        printf("Attempt #%d: ", attempt);
        scanf("%d", &guess);

        if (guess == secretNumber) {
            printf("\nCongratulations! You guessed the secret number in %d attempt(s)!\n", attempt);
            return 0;
        } else if (guess < secretNumber) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }

        attempt++;
    }

    // Game over
    printf("\nGame over. You couldn't guess the secret number within 10 attempts.\n");
    printf("The secret number was %d. Better luck next time!\n\n", secretNumber);

    return 0;
}