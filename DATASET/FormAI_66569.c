//FormAI DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, tries = 0;
    srand(time(NULL));
    num = rand() % 100 + 1;
    printf("\nWelcome to the Happy Guessing Game!\n");
    printf("Can you guess the random number between 1 and 100?\n");
    do
    {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        tries++;
        if (guess > num)
        {
            printf("Too high! Guess again.\n");
        }
        else if (guess < num)
        {
            printf("Too low! Guess again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != num);
    printf("\nThanks for playing the Happy Guessing Game! Have a great day!\n");

    return 0;
}