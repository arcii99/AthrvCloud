//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, tries = 0;
    srand(time(0)); //seeding the random number generator
    num = rand() % 100 + 1; //generating random number between 1 and 100
    printf("Welcome to the guessing game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    do
    {
        printf("Take a guess: ");
        scanf("%d", &guess);
        tries++;
        if (guess > num)
        {
            printf("Too high!\n");
        }
        else if (guess < num)
        {
            printf("Too low!\n");
        }
        else
        {
            printf("Congratulations! You guessed it in %d tries.\n", tries);
        }
    } while (guess != num);

    return 0;
}