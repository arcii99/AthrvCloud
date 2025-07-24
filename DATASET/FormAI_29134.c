//FormAI DATASET v1.0 Category: Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("Guess My Number Game\n\n");
    do
    {
        printf("Enter a guess between 1 and 100 : ");
        scanf("%d", &guess);
        tries++;

        if (guess > num)
        {
            printf("Too high!\n\n");
        }
        else if (guess < num)
        {
            printf("Too low!\n\n");
        }
        else
        {
            printf("\nCongratulations! You guessed it in %d attempts!\n", tries);
        }
    } while (guess != num);

    return 0;
}