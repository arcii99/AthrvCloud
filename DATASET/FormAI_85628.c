//FormAI DATASET v1.0 Category: Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    int secret_number = rand() % 100 + 1; // generate random secret number between 1 and 100
    int guess;
    int attempt = 0;

    printf("Welcome to the Guessing Game! You have 10 attempts to guess the secret number between 1 and 100.\n");

    while (attempt < 10)
    {
        printf("Attempt %d. Enter your guess: ", attempt + 1);
        scanf("%d", &guess);

        if (guess < secret_number)
            printf("Your guess is too low. Try again.\n");
        else if (guess > secret_number)
            printf("Your guess is too high. Try again.\n");
        else
        {
            printf("\nCongratulations! You guessed the secret number (%d) in %d attempts.\n", secret_number, attempt + 1);
            return 0;
        }

        attempt++;
    }

    printf("\nSorry, you failed to guess the secret number (%d) in 10 attempts. Game over!\n", secret_number);

    return 0;
}