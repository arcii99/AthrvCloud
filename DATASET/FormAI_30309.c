//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5   // Maximum number of tries
#define MAX_NUMBER 50 // Maximum number to guess

int main()
{
    int secretNumber, guess, tries = 0;
    srand(time(0));
    secretNumber = rand() % MAX_NUMBER + 1; // Generate random number between 1 and MAX_NUMBER

    printf("\nWelcome to the Guessing Game!\n");
    printf("Please enter a number between 1 and %d\n", MAX_NUMBER);

    while (tries < MAX_TRIES)
    {
        scanf("%d", &guess);

        if (guess < 1 || guess > MAX_NUMBER)
        {
            printf("Invalid input! Please enter a number between 1 and %d\n", MAX_NUMBER);
            continue;
        }

        tries++; // Increment number of tries

        if (guess == secretNumber)
        {
            printf("Congratulations! You guessed the number in %d tries\n", tries);
            return 0; // Exit program
        }
        else if (guess < secretNumber)
        {
            printf("Your guess is too low! You have %d tries left\n", MAX_TRIES - tries);
        }
        else
        {
            printf("Your guess is too high! You have %d tries left\n", MAX_TRIES - tries);
        }
    }

    printf("Sorry, you ran out of tries. The secret number was %d\n", secretNumber);
    return 0;
}