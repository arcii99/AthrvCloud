//FormAI DATASET v1.0 Category: Random ; Style: content
/* 
 * This is a unique C Random example program that generates a random number between 1 to 100.
 * The program then asks the user to guess the number and gives feedback on whether the guess is too high or too low.
 * Once the user has guessed the correct number, the program displays the number of attempts it took to guess correctly.
 * This program uses the time.h library to seed the random number generator with the current time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Random Number Guessing Game!\n");
    
    // Seed the random number generator with the current time
    srand(time(0));
    
    // Generate a random number between 1 to 100
    int target_number = rand() % 100 + 1;
    int guess_count = 0;
    int user_guess;
    
    // Loop until the user guesses the correct number
    while (1) {
        printf("\nGuess a number between 1 and 100: ");
        scanf("%d", &user_guess);
        guess_count++;
        
        // Check if the user's guess is correct
        if (user_guess == target_number) {
            printf("Congratulations! You guessed the number %d correctly in %d attempts.\n", target_number, guess_count);
            break;
        }
        else if (user_guess < target_number) {
            printf("Too low, try again.\n");
        }
        else {
            printf("Too high, try again.\n");
        }
    }
    
    return 0;
}