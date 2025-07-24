//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, attempts = 0;
    srand(time(0)); // initialize the random seed

    num = rand() % 100 + 1; // generate a random number between 1 and 100

    printf("Guess the number between 1 to 100.\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++; // increment number of attempts

        if (guess > num)
        {
            printf("Lower\n");
        }
        else if (guess < num)
        {
            printf("Higher\n");
        }
        else
        {
            printf("Congratulations! You guessed it in %d attempts.\n", attempts);
        }
    } while (guess != num);

    return 0;
}