//FormAI DATASET v1.0 Category: Game ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

// Future-Proof Style C Program Example
// A simple game of guessing the hidden number between 1 to 100

int main()
{
    int secret_number = rand() % 100 + 1; // Generate a random secret number
    int guess = 0, attempts = 0;
    printf("Welcome to the Guessing Game!\n");
    printf("The computer has picked a secret number between 1 to 100. You have 10 attempts to guess it.\n\n");

    // Loop to get user's input and check if it matches the secret number
    while(attempts < 10)
    {
        printf("Please enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if(guess > secret_number)
        {
            printf("Your guess is too high. Try again.\n");
        }
        else if(guess < secret_number)
        {
            printf("Your guess is too low. Try again.\n");
        }
        else
        {
            printf("Congratulations! You have guessed the secret number %d in %d attempts!\n", secret_number, attempts);
            return 0;
        }
    }

    // If user fails to guess the number in 10 attempts
    printf("\nSorry! You have failed to guess the secret number %d in 10 attempts.\nBetter luck next time!", secret_number);

    return 0;
}