//FormAI DATASET v1.0 Category: Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number, tries = 0;
    srand(time(0)); // Seed random number generator
    number = rand() % 100 + 1; // Generate random number between 1 and 100
    printf("\n\nWelcome to the Guessing Game!\n\n");

    do
    {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        tries++;

        if (guess > number)
        {
            printf("Lower!\n\n");
        }

        else if (guess < number)
        {
            printf("Higher!\n\n");
        }

        else
        {
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
        }

    } while (guess != number);

    return 0;
}