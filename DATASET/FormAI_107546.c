//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number, guess, count = 0;
    srand(time(0));
    number = rand() % 100 + 1;

    printf("Guess the number between 1 to 100\n\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;

        if (guess > number)
        {
            printf("Lower number please!\n");
        }
        else if (guess < number)
        {
            printf("Higher number please!\n");
        }
        else
        {
            printf("\nCongratulations! You guessed it in %d attempts!\n", count);
        }
    } while (guess != number);

    return 0;
}