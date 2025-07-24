//FormAI DATASET v1.0 Category: Table Game ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random number from 1 to 100
int randomNum(){
    srand(time(NULL));
    return rand()%100 + 1;
}

int main(){
    int secretNum = randomNum(); // Generate secret number
    int guess, tries = 0; // Initialize guess and tries
    
    printf("Welcome to the C Table Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");
    
    // Loop until the user guesses the number or runs out of tries
    while(tries < 10){
        printf("Enter your guess: ");
        scanf("%d", &guess); // Take input guess from user
        tries++; // Increment the number of tries
        
        // If the guess is correct
        if(guess == secretNum){
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
            return 0;
        }
        // If the guess is too low
        else if(guess < secretNum){
            printf("Too low! Try again.\n");
        }
        // If the guess is too high
        else{
            printf("Too high! Try again.\n");
        }
    }
    
    // If the user runs out of tries
    printf("Sorry, you ran out of tries. The number was %d.\n", secretNum);
    return 0;
}