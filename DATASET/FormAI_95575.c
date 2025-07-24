//FormAI DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess;
    int randomNum;
    int attempts = 0;
    srand(time(0));
    randomNum = rand() % 100 + 1; // Generate a random number between 1 and 100
    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");
    do
    {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        attempts++; // Increment number of attempts
        if (guess > randomNum)
        {
            printf("Too high! Guess again!\n");
        }
        else if (guess < randomNum)
        {
            printf("Too low! Guess again!\n");
        }
        else
        {
            printf("Congratulations, you guessed it in %d attempts!\n", attempts);
        }
    } while (guess != randomNum);
    return 0;
}