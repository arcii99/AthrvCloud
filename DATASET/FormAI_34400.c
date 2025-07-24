//FormAI DATASET v1.0 Category: Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Generate a random number
    srand(time(NULL));
    int target = rand() % 100 + 1;
    
    // Initialize variables
    int guess = 0;
    int num_guesses = 0;
    char response[10];
    
    // Start the game loop
    while (1) {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        num_guesses++;
        
        // Check if the guess is correct
        if (guess == target) {
            printf("Congratulations, you guessed the number in %d tries!\n", num_guesses);
            break;
        }
        
        // If guess is incorrect, give a hint
        if (guess < target) {
            printf("Too low.\n");
        } else {
            printf("Too high.\n");
        }
        
        // Ask if user wants to play again
        printf("Would you like to play again? (y/n)");
        scanf("%s", response);
        if (response[0] == 'n') {
            break;
        } else {
            // Generate new random number for the next round
            target = rand() % 100 + 1;
            num_guesses = 0;
        }
    }
    
    return 0;
}