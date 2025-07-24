//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number, tries = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    printf("Hello there! I'm thinking of a number between 1 and 100...\n");
    printf("Can you guess what it is?\n\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > number)
        {
            printf("Ha! Too high! Try again, sucker!\n");
        }
        else if (guess < number)
        {
            printf("Ha ha! Too low! Try again, loser!\n");
        }
        else
        {
            printf("\nCongratulations, you guessed it! It only took you %d tries!\n", tries);
        }

    } while (guess != number);

    return 0;
}