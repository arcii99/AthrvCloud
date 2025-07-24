//FormAI DATASET v1.0 Category: Random ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VALUE 1 //Minimum value the random number can take
#define MAX_VALUE 100 //Maximum value the random number can take

int main()
{
    srand(time(NULL)); //Initialize the random number generator with current time
    int randomNumber = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1); //Generate a random number between MIN_VALUE and MAX_VALUE
    int guess, numberOfGuesses = 0; //Initialize guess and numberOfGuesses to 0

    printf("Guess a number between %d and %d\n", MIN_VALUE, MAX_VALUE);

    //Loop until the user guesses the correct number
    while(1)
    {
        numberOfGuesses++; //Increment numberOfGuesses
        printf("Enter your guess: ");
        scanf("%d", &guess); //Read the user's guess

        if(guess == randomNumber) //If user's guess matches the random number
        {
            printf("Congratulations! You guessed the number in %d tries.\n", numberOfGuesses);
            break; //Exit the loop
        }
        else if(guess < randomNumber) //If user's guess is lower than the random number
        {
            printf("Your guess is too low. Try again.\n");
        }
        else //If user's guess is higher than the random number
        {
            printf("Your guess is too high. Try again.\n");
        }
    }

    return 0; //Terminate the program
}