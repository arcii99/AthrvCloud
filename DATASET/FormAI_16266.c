//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function that generates random number between 1 and 100
int generateRandomNumber() {
    srand(time(NULL));  // seed random number generator
    int num = rand() % 100 + 1;  // generate random number between 1 and 100
    return num;
}

int main() {
    int randomNumber = generateRandomNumber();  // generate random number
    int guessCount = 0;  // initialize guess count to 0
    int guess;  // declare variable to store user's guess
    
    printf("*** Welcome to the Guessing Game! ***\n\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("See if you can guess what it is!\n\n");
    
    // loop to allow user to make multiple guesses
    while (1) {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);  // read user's guess from input
        
        guessCount++;  // increment guess count
        
        // check if user's guess is correct
        if (guess == randomNumber) {
            printf("\nCongratulations! You guessed the number in %d tries.\n", guessCount);
            break;  // exit the loop
        }
        else if (guess < randomNumber) {
            printf("Too low! ");
        }
        else {
            printf("Too high! ");
        }
        
        printf("Try again.\n\n");
    }
    
    return 0;
}