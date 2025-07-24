//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10

int main()
{
    srand(time(0));
    
    printf("Welcome to the statistical guessing game!\n");
    printf("I'm thinking of a number between 1 and 100\n");
    
    int numToGuess = rand() % 100 + 1;
    int guessCount = 0;
    int guess = -1;
    
    while(guess != numToGuess && guessCount <= MAX_GUESSES)
    {
        printf("Guess #%d: ", guessCount+1);
        scanf("%d", &guess);
        
        if(guess < numToGuess)
        {
            printf("Too low!\n");
        }
        else if(guess > numToGuess)
        {
            printf("Too high!\n");
        }
        
        guessCount++;
    }
    
    if(guess == numToGuess)
    {
        printf("You win! You guessed the number in %d guesses\n", guessCount);
    }
    else
    {
        printf("Sorry, you lose. The number was %d\n", numToGuess);
    }
    
    return 0;
}