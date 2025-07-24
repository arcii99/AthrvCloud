//FormAI DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void callback(int count);

int main()
{
    srand(time(NULL));
    int target = rand() % 100 + 1;
    int guess = 0;
    int count = 0;

    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");

    while(guess != target)
    {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        count++;

        if(guess < target)
        {
            printf("Too low. Try again.\n");
        }
        else if(guess > target)
        {
            printf("Too high. Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed it in %d tries.\n", count);
        }

        callback(count);
    }

    return 0;
}

void callback(int count)
{
    printf("\nI'm still thinking...\n");
    printf("It's been %d tries so far!\n", count);
}