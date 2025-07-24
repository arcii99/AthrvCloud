//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seeding the random number generator
    
    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    
    int num_to_guess = rand() % 100 + 1; // generate random number between 1 and 100
    int guess = 0; // initialize guess variable
    
    while (guess != num_to_guess)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess); // get user's guess
        
        // compare guess to number and provide feedback
        if (guess < num_to_guess)
        {
            printf("Too low, try again!\n");
        }
        else if (guess > num_to_guess)
        {
            printf("Too high, try again!\n");
        }
        else
        {
            printf("Congratulations, you guessed the number!\n");
        }
    }
    
    return 0;
}