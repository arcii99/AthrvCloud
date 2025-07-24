//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, count = 0;
    char play;
    
    srand(time(NULL));  // Generate a random number using the system clock
    
    do {
        num = rand() % 100 + 1;  // Generate a random number between 1 and 100
        printf("\nGuess a number between 1 and 100: ");
        
        do {
            scanf("%d", &guess);   
            count++; // Increment the number of guesses
            
            if (guess > num) {
                printf("Too high, try again!\n");
            } else if (guess < num) {
                printf("Too low, try again!\n");
            } else {
                printf("Congratulations! You guessed the number in %d tries.\n", count);
            }
            
        } while (guess != num);  // Keep looping until the player guesses the correct number
        
        printf("Do you want to play again? [y/n]: ");
        scanf(" %c", &play);
        count = 0;  // Reset the number of guesses for the next game
        
    } while (play == 'y' || play == 'Y');  // Keep looping until the player decides to quit
    
    printf("Thanks for playing! Goodbye.\n");
    
    return 0;
}