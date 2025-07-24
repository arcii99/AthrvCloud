//FormAI DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to generate a random number between min and max
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int numGuesses = 0;
    int guess;
    bool gameWon = false;
    int minNumber, maxNumber;
    
    // set the random seed based on the current time
    srand(time(0));
    
    printf("Welcome to the Guessing Game!\n");
    printf("Enter the range of numbers you want to guess between:\n");
    printf("Minimum number: ");
    scanf("%d", &minNumber);
    printf("Maximum number: ");
    scanf("%d", &maxNumber);
    
    // generate a random number between minNumber and maxNumber
    int randomNumber = getRandomNumber(minNumber, maxNumber);
    
    printf("I am thinking of a number between %d and %d\n", minNumber, maxNumber);
    
    // loop until the user has guessed the correct number
    while (!gameWon) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numGuesses++;
        
        if (guess == randomNumber) {
            gameWon = true;
            printf("Congratulations! You guessed the number in %d guesses!\n", numGuesses);
        } else if (guess < randomNumber) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Too high! Guess again.\n");
        }
    }
    
    return 0;
}