//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));      //seeding the random number generator
    int secretNum = rand() % 101;   //generating a random number between 0 and 100
    int guess = -1;                   //initializing guess variable
    int numGuesses = 0;              //initializing number of guesses variable
    printf("Welcome to the Guessing Game!\n");
   
    while(guess != secretNum)     //loop until player correctly guesses the secret number
    {
        printf("Enter a number between 0 and 100: ");
        scanf("%d", &guess);   //reading user's guess
        numGuesses++;                  //incrementing number of guesses
        
        if(guess < secretNum)
        {
            printf("Too low, try again...\n");
        }
        else if(guess > secretNum)
        {
            printf("Too high, try again...\n");
        }
        else
        {
            printf("Congratulations, you guessed the secret number in %d tries!\n", numGuesses);
        }
    }
    return 0;
}