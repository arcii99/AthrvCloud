//FormAI DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int random_num = rand() % 100 + 1; //generate random number between 1 and 100
    int guess, num_guesses = 0;

    printf("Welcome to the Guessing Game!\n\n");

    while(1)
    {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        num_guesses++;

        if(guess == random_num)
        {
            printf("\nCongratulations, you guessed the number in %d guesses!\n", num_guesses);
            break;
        }
        else if(guess > random_num)
        {
            printf("Too high! Try again.\n");
        }
        else
        {
            printf("Too low! Try again.\n");
        }
    }

    return 0;
}