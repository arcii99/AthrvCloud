//FormAI DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("You have 10 tries to guess the number.\n");
    do
    {
        printf("Guess #%d: ", tries + 1);
        scanf("%d", &guess);
        tries++;
        if (guess > num)
            printf("Too high. Guess lower.\n");
        else if (guess < num)
            printf("Too low. Guess higher.\n");
        else
        {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
            return 0;
        }
    } while (tries < 10);
    printf("Sorry, you ran out of tries. The number was %d.\n", num);
    return 0;
}