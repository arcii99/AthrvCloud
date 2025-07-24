//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the RNG with current time
    srand(time(0));
    
    // Generate a random number between 1 and 100
    int num = rand() % 100 + 1;
    
    // Variables for user input and number of attempts
    int guess, attempts = 0;
    
    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    
    // While the user hasn't guessed the correct number
    while (1)
    {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);
        attempts++;
        
        // If the guess is too low, prompt user to guess higher
        if (guess < num)
        {
            printf("Too low! Guess higher.\n");
        }
        // If the guess is too high, prompt user to guess lower
        else if (guess > num)
        {
            printf("Too high! Guess lower.\n");
        }
        // If the guess is correct, print the number of attempts and exit
        else
        {
            printf("Congratulations, you guessed the number in %d attempts!\n", attempts);
            break;
        }
    }
    
    return 0;
}