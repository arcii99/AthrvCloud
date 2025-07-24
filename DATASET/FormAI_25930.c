//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    
    int secret_num = rand() % 100 + 1; // Generate a random integer between 1 and 100
    int guess;
    int num_guesses = 0;
    
    printf("\nGuess the secret number between 1 and 100!\n");
    
    // Loop until the player guesses the correct number
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        num_guesses++; // Increase the number of guesses
        
        if (guess == secret_num) {
            printf("\nCongratulations, you guessed the secret number in %d tries!\n", num_guesses);
            break; // Exit the loop when the player guesses correctly
        }
        else if (guess < secret_num) {
            printf("Too low, try again.\n");
        }
        else {
            printf("Too high, try again.\n");
        }
    }
    
    return 0;
}