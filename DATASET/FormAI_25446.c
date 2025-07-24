//FormAI DATASET v1.0 Category: Game ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int randomNumber = rand() % 100;
    int guess;
    int attempts = 0;

    printf("Welcome to Guess the Number Game!\n");
    printf("You have 10 attempts to guess the number between 0 and 99.\n");

    while(attempts < 10)
    {
        printf("Guess #%d:", attempts + 1);
        scanf("%d", &guess);

        if(guess == randomNumber)
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts + 1);
            return 0;
        }
        else if(guess < randomNumber)
        {
            printf("The number is higher than your guess.\n");
        }
        else
        {
            printf("The number is lower than your guess.\n");
        }

        attempts++;
    }

    printf("Sorry! You ran out of attempts. The number was %d.\n", randomNumber);
    return 0;
}