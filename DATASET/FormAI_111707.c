//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Declare variables
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1; // Generates a random number between 1-100
    
    // Welcome message
    printf("Welcome to the Guessing Game!\n");
    printf("You have to guess a number between 1 and 100\n");
    
    // Game logic
    do {
        printf("Guess a number: ");
        scanf("%d", &guess);
        tries++; // Increase the number of tries
        if (guess > num){
            printf("Too high! Try again.\n");
        }
        else if (guess < num){
            printf("Too low! Try again.\n");
        }
        else{
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != num);
    
    return 0;
}