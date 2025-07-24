//FormAI DATASET v1.0 Category: Table Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // seed random number generator
    int num, guess, tries = 0;
    num = rand() % 100 + 1; // random number between 1 and 100

    printf("\n\n\n\t\tWelcome to the Sherlock Holmes Number Guessing Game!\n\n");
    printf("In this game, you will have to guess a number between 1 and 100.\n");
    printf("You will be given clues after each guess to help you find the secret number.\n");

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
            printf("\n\nBingo! You guessed the number in %d tries!\n", tries);
            printf("You are a true detective!\n");
        }

    } while (guess != num);

    return 0;
}