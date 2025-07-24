//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, tries = 0;

    srand(time(0));
    num = rand() % 100 + 1;

    printf("\nWelcome to the Number Guessing Game!\n");
    printf("Please enter a number between 1 and 100.\n");

    do
    {
        printf("Enter Guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num)
        {
            printf("Too High! Try again.\n");
        }
        else if (guess < num)
        {
            printf("Too Low! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != num);

    return 0;
}