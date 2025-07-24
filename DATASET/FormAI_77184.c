//FormAI DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number, tries = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    printf("Welcome to Guess the Number Game!\n");
    printf("I am thinking of a number between 1 and 100. You have to guess it in 7 tries.\n");

    do {
        printf("Guess the number: ");
        scanf("%d", &guess);
        tries++;
        
        if(guess > number)
        {
            printf("Too high! Try again.\n");
        }
        else if(guess < number)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed it in %d tries.", tries);
        }
        
    } while(guess != number && tries != 7);

    if(guess != number)
    {
        printf("Sorry, you ran out of tries. The number was %d.", number);
    }
    return 0;
}