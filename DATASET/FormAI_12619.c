//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, guess, numGuesses;
    int lower = 1, upper = 100, randNum;

    //seed random number generator
    srand(time(0));

    //generate random number between lower and upper bounds
    randNum = (rand() % (upper - lower + 1)) + lower;

    printf("I have a number between %d and %d. Can you guess it?\n", lower, upper);

    //loop until user guesses the correct number
    while(1)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        //update number of guesses
        numGuesses++;

        if(guess == randNum)
        {
            printf("Congratulations! You have guessed the number in %d tries.\n", numGuesses);
            break;
        }
        else if(guess < randNum)
        {
            printf("Try higher.\n");
        }
        else
        {
            printf("Try lower.\n");
        }
    }

    return 0;
}