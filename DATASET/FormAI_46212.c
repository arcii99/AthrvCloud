//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("Guess the number between 1 and 100\n");

    do
    {
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
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
        }

    } while (guess != num);

    return 0;
}