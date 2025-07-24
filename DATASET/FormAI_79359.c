//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, attempts = 0;
    srand(time(0));  // Seed the random number generator

    num = rand() % 101;  // Generate a random number between 0 and 100

    printf("Guess the number between 0 and 100: ");

    do
    {
        scanf("%d", &guess);
        attempts++;

        if (guess > num)
        {
            printf("Too high! Guess again: ");
        }
        else if (guess < num)
        {
            printf("Too low! Guess again: ");
        }
        else
        {
            printf("You win! It took you %d attempts to guess the number.\n", attempts);
        }
    } while (guess != num);

    return 0;
}