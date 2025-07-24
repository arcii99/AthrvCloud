//FormAI DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    int c = rand() % 10 + 1;

    printf("Welcome to the math puzzle game!\n");
    printf("You need to solve the following equation to win the game:\n");
    printf("%d + %d * %d = ??\n", a, b, c);

    int answer = a + b * c;

    int guess;
    int tries = 0;

    do
    {
        printf("What is your guess?\n");
        scanf("%d", &guess);
        tries++;

        if (guess == answer)
        {
            printf("Congratulations, you won the game!\n");
            printf("You took %d tries to solve the puzzle.\n", tries);
            break;
        }
        else
        {
            printf("Sorry, that is not the correct answer.\n");
            printf("Try again!\n");
        }

    } while (guess != answer);

    return 0;
}