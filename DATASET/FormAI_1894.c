//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between 1 and 100
int generateRandomNumber() {
    srand(time(NULL));   // initialize the random number generator
    int number = (rand() % 100) + 1;    // generate the random number between 1 and 100
    return number;
}

int main() {
    int randomNumber = generateRandomNumber();   // generate a random number between 1 and 100
    int attempts = 5;   // number of attempts the player has to guess the correct number
    int guess;  // variable to hold the player's guess
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have 5 attempts to guess the correct number between 1 and 100\n");
    
    while (attempts > 0) {
        printf("Guess #%d: ", 6-attempts);    // prompt the player to guess the number
        scanf("%d", &guess);    // store the player's guess
        
        if (guess < 1 || guess > 100) {
            printf("Invalid input. Please enter a number between 1 and 100.\n");
            continue;   // skip to the next iteration of the loop
        }
        
        if (guess == randomNumber) {
            printf("Congratulations! You guessed the correct number!\n");
            break;  // exit the loop as the player has guessed the correct number
        } else if (guess < randomNumber) {
            printf("Sorry, that's too low.\n");
        } else {
            printf("Sorry, that's too high.\n");
        }
        
        attempts--; // decrement the number of attempts
    }
    
    if (attempts == 0) {
        printf("Sorry, you ran out of attempts. The correct number was %d.\n", randomNumber);
    }
    
    return 0;
}