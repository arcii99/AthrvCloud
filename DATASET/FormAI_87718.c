//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // Seed random function with current time
    int ghost = rand() % 10; // Generate a random number from 0 to 9
    int attempts = 3; // Set the number of attempts to 3
    
    printf("Welcome to the Haunted House Simulator!\n\n"); // Program start message
    
    while (attempts > 0) { // While the player still has attempts left
        int guess; // Declare guess variable
        printf("Can you guess where the ghost is hiding? Enter a number from 0 to 9: ");
        scanf("%d", &guess); // Get player's guess from user input
        
        if (guess == ghost) { // If player guesses correctly
            printf("Congratulations! You found the ghost!\n");
            return 0; // End program
        } else { // If player guesses incorrectly
            attempts--; // Decrement attempts
            printf("Sorry, you didn't find the ghost. You have %d attempts left.\n", attempts);
            if (attempts == 0) { // If player runs out of attempts
                printf("Game over! Better luck next time.\n");
            }
        }
    }
    
    return 0;
}