//FormAI DATASET v1.0 Category: Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, tries = 0;
    srand(time(0));  // Seed random number generator
    num = rand() % 100 + 1;  // Generate random number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    
    do
    {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num)
        {
            printf("Too high! Try again.\n");
        }
        else if (guess < num)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
        }
    } while (guess != num);

    return 0;
}