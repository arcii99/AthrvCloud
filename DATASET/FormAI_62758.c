//FormAI DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int num, guess, num_guesses = 0;
    char choice;
    
    // Set the seed for the random number generator
    srand(time(0));
    
    // Choose a random number between 1 and 100
    num = rand() % 100 + 1;
    
    do {
        printf("\n\nGuess a number between 1 and 100: ");
        scanf("%d", &guess);
        
        if (guess < num) {
            printf("Too low. Try again.");
        } else if (guess > num) {
            printf("Too high. Try again.");
        } else {
            printf("Congratulations! You guessed the number in %d tries.", num_guesses);
        }
        
        num_guesses++;
        
        printf("\n\nDo you want to continue playing? (Y/N): ");
        scanf(" %c", &choice);
        
    } while (choice == 'Y' || choice == 'y');
    
    printf("Thanks for playing! Goodbye.");
    
    return 0;
}