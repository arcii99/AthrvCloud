//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize random number generator with current time

    int num, guesses = 0, guess;

    num = rand() % 100 + 1; // Generate random number between 1 and 100

    printf("*** Welcome to the Guessing Game ***\n");
    printf("I am thinking of a number between 1 and 100.\n");

    do // Loop until user guesses the correct number
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < num)
            printf("Too low! Try again.\n");
        else if (guess > num)
            printf("Too high! Try again.\n");

        guesses++;
    } while (guess != num);

    // Game over message
    printf("\nCongratulations! You guessed the number in %d guesses.\n", guesses);

    return 0;
}