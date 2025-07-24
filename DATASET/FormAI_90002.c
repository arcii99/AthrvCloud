//FormAI DATASET v1.0 Category: Random ; Style: funny
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    srand(time(0)); // Seed the rand function
    int random_number = rand() % 100; // Get a random number from 0 to 99
    
    printf("I'm thinking of a random number between 0 and 99. Can you guess it?\n"); 
    
    int guess; // Create guess variable
    
    while(1) { // Keep asking for guesses until right one is guessed
        printf("Enter your guess: "); 
        scanf("%d", &guess); 

        if(guess == random_number) { // If the guess is correct, break out of loop
            printf("Great job! You guessed my number in %d tries.\n", guess / 10);
            break; 
        }
        else if(guess < random_number) {
            printf("Too low. Try again.\n"); 
        }
        else {
            printf("Too high. Try again.\n"); 
        }
    } 

    return 0; 
}