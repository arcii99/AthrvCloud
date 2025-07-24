//FormAI DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer, guess, count = 0;
    srand(time(0));
    // Generate a random number between 1 and 100
    answer = rand() % 100 + 1;

    while (1)
    {
        printf("Enter your guess between 1 and 100: ");
        scanf("%d", &guess);
        count++;

        if (guess == answer)
        {
            printf("Congratulations! You guessed correctly in %d tries.\n", count);
            break;
        }
        else if (guess < answer)
        {
            printf("Your guess is too low. Try again.\n");
        }
        else
        {
            printf("Your guess is too high. Try again.\n");
        }
    }

    return 0;
}