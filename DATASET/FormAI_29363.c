//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;

    printf("\n");
    printf("*****************************************************\n");
    printf("*************** C Table Number Guess Game ************\n");
    printf("*****************************************************\n");
    printf("\n");

    printf("Guess a number between 1 and 100:\n");

    do
    {
        scanf("%d", &guess);
        tries++;

        if (guess > num)
            printf("Too high! Guess again:\n");

        else if (guess < num)
            printf("Too low! Guess again:\n");

        else
        {
            printf("\n");
            printf("*****************************************\n");
            printf("****** Congratulations! You won! ********\n");
            printf("***** It only took you %d tries! ******\n", tries);
            printf("*****************************************\n");
            printf("\n");
        }
    }
    while (guess != num);

    return 0;
}