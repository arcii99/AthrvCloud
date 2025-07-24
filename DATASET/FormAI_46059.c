//FormAI DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number, guess, tries = 0;
    srand(time(0));
    number = rand() % 100 + 1; // generate a random number between 1 to 100
    printf("\n\n\n\t\t\tWelcome to the Guess the Number Game\n"); 
    printf("\n\n\nRules: You have to guess the number between 1 to 100\n");
    do
    {
        printf("\nEnter your guess (between 1 to 100): ");
        scanf("%d", &guess);
        tries++;

        if (guess > number)
        {
            printf("Too high! Guess again.\n");
        }
        else if (guess < number)
        {
            printf("Too low! Guess again.\n");
        }
        else
        {
            printf("\n\nCongratulations, you guessed the number in %d tries!\n\n", tries);
        }
    } while (guess != number);

    return 0;
}