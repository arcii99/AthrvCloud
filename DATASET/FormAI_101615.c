//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int random_num, guess, tries = 0;
    srand(time(NULL)); // seed the random number generator
    
    // generate a random number between 1 and 100
    random_num = rand() % 100 + 1;
    
    // welcome message and instructions
    printf("\nWelcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");
    printf("You have 10 tries to guess correctly. Good luck!\n\n");
    
    // loop until the player guesses correctly or runs out of tries
    while (tries < 10)
    {
        printf("Guess #%d: ", tries + 1);
        scanf("%d", &guess); // get the player's guess
        
        // check if the guess is too high, too low, or correct
        if (guess > random_num)
        {
            printf("Too high! Try again.\n\n");
        }
        else if (guess < random_num)
        {
            printf("Too low! Try again.\n\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d tries.\n", tries + 1);
            return 0;
        }
        
        tries++; // increase the try count
    }
    
    // if the player reaches this point, they have run out of tries
    printf("Sorry, you have run out of tries. The number was %d. Better luck next time!\n", random_num);
    return 0;
}