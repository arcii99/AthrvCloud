//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initializing variables
    int num, guess, attempts = 0;
    
    // Setting the random number generator seed
    srand(time(0));
    
    // Generating the random number between 1 to 100
    num = rand() % 100 + 1;
    
    // Presenting the user with the game title and rules
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have generated a random number between 1 to 100. You have to guess this number.\n");
    
    do {
        // Taking user input
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        // Checking the guess with the generated number
        if (guess > num) {
            printf("Too high! Try again.\n");
        } else if (guess < num) {
            printf("Too low! Try again.\n");
        }
        attempts++;
    } while (guess != num);
    
    // Presenting the user with the output and the number of attempts
    printf("Congratulation! You have guessed the number correctly in %d attempts.\n", attempts);

    return 0;
}