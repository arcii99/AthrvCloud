//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a specific range
int generateRandom(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    srand(time(NULL)); // Initialize random number generator

    // Initialize variables for the game
    int min = 1;
    int max = 100;
    int target = generateRandom(min, max);
    int guess = 0;
    int tries = 0;

    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between %d and %d. Can you guess it?\n", min, max);

    // Start the game
    while (guess != target)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess < target)
        {
            printf("Too low! Try again.\n");
        }
        else if (guess > target)
        {
            printf("Too high! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
        }
    }

    return 0;
}