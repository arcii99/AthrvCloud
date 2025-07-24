//FormAI DATASET v1.0 Category: Random ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up random number generator
    srand(time(NULL));
    int number = rand() % 100 + 1;

    // Print welcome message
    printf("Welcome to the Random Number Game!\n");
    printf("Guess a number between 1 and 100:\n");

    // Initialize variables and start loop
    int guess = 0;
    int num_guesses = 0;
    while (guess != number)
    {
        // Get user input
        scanf("%d", &guess);

        // Check if guess is correct and provide feedback
        if (guess == number)
        {
            printf("Congratulations! You guessed the number in %d tries.\n", num_guesses);
        }
        else if (guess < number)
        {
            printf("Sorry, your guess was too low. Try again:\n");
            num_guesses++;
        }
        else
        {
            printf("Sorry, your guess was too high. Try again:\n");
            num_guesses++;
        }
    }

    // Print farewell message
    printf("Thanks for playing the Random Number Game!\n");
    return 0;
}