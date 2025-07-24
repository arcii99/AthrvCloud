//FormAI DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator with current time
    int guess, num, tries = 0;

    num = rand() % 100 + 1; // Generate a random number between 1 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("I have thought of a number between 1 and 100. Can you guess it?\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess); // Read user's guess from input

        if (guess > num)
        {
            printf("Too high! Try again.\n");
            tries++;
        }
        else if (guess < num)
        {
            printf("Too low! Try again.\n");
            tries++;
        }
        else
        {
            printf("Congratulations! You guessed it in %d tries.\n", tries);
        }

    } while (guess != num);

    return 0;
}