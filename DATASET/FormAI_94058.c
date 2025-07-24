//FormAI DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, attempts = 0;
    srand(time(0));
    num = rand() % 100 + 1; // Generate random number between 1 and 100

    printf("Guess the number between 1 and 100\n");

    do {
        scanf("%d", &guess);
        attempts++;

        if (guess > num)
        {
            printf("Lower\n");
        }

        if (guess < num)
        {
            printf("Higher\n");
        }

        if (guess == num)
        {
            printf("\nCongratulations! You guessed the number in %d attempts\n", attempts);
        }

    } while (guess != num);

    return 0;
}