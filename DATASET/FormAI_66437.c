//FormAI DATASET v1.0 Category: Random ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, tries = 0;
    srand(time(0)); // Seed random number generator

    num = rand() % 100 + 1; // Generate a random number between 1 and 100

    printf("\nWelcome to my Random Number Game!\n");
    printf("I'm thinking of a number between 1 and 100... can you guess it?\n\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if(guess > num)
            printf("Too high! Try again.\n\n");
        else if(guess < num)
            printf("Too low! Try again.\n\n");
        else
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
    } while(guess != num);

    return 0;
}