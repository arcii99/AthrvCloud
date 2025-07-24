//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_guesses = 0;
    int guess;
    int random_num;
    
    // Seed the random number generator
    srand(time(NULL));
    random_num = rand() % 100 + 1; // Generate random number between 1 and 100
    
    printf("Welcome to the Number Guessing Game!\n");
    
    // Main game loop
    while (1)
    {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        
        num_guesses++; // Increment number of guesses
        
        if (guess == random_num)
        {
            printf("Congratulations! You guessed the number in %d tries!\n", num_guesses);
            break; // Exit loop
        }
        else if (guess < random_num)
        {
            printf("Too low! Guess again.\n");
        }
        else
        {
            printf("Too high! Guess again.\n");
        }
    }
    
    return 0;
}