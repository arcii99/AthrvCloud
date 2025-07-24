//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // ensures that each run of the program will have a different sequence of random numbers
    int num_guesses = 0; // counter to keep track of the number of guesses the user makes
    int max_guesses = 10; // the maximum number of guesses the user is allowed
    
    int secret_num = rand() % 100; // generate a random number between 0 and 99
    
    printf("Welcome to Guess the Number!\n");
    printf("You have %d guesses to guess the number between 0 and 99.\n", max_guesses);
    
    int guess = -1; // initialize guess to something that is not the secret number
    
    // repeat until the user guesses the number or runs out of guesses
    while (guess != secret_num && num_guesses < max_guesses)
    {
        printf("Guess #%d: ", num_guesses+1);
        scanf("%d", &guess);
        
        if (guess < secret_num)
        {
            printf("Too low! Guess higher.\n");
        }
        else if (guess > secret_num)
        {
            printf("Too high! Guess lower.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses+1);
        }
        
        num_guesses++;
    }
    
    if (num_guesses == max_guesses)
    {
        printf("Sorry, you ran out of guesses. The number was %d.\n", secret_num);
    }
    
    return 0;
}