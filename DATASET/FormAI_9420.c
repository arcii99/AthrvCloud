//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // declare variables
    int guess, randomNum, tries = 0;
    char playAgain = 'Y';
    
    while (playAgain == 'Y') {
        // generate a random number between 1 and 100
        randomNum = rand() % 100 + 1;
        
        printf("\nWelcome to the Guessing Game!\n");
        printf("I am thinking of a number between 1 and 100.\n\n");
        
        // loop until the user guesses the correct number
        do {
            printf("Guess a number: ");
            scanf("%d", &guess);
            tries++;
            
            if (guess < randomNum) {
                printf("Too low. Guess again.\n");
            } else if (guess > randomNum) {
                printf("Too high. Guess again.\n");
            }
        } while (guess != randomNum);
        
        printf("\nCongratulations! You guessed the number "
               "in %d tries.\n", tries);
        
        printf("Would you like to play again? (Y/N)");
        scanf(" %c", &playAgain);
        
        if (playAgain == 'Y') {
            // reset variables for a new game
            tries = 0;
        }
    }
    
    printf("\nThanks for playing! Goodbye.\n");
    
    return 0;
}