//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate a random number between 1 and 100
int generateRandomNumber() {
    srand(time(NULL)); //Set seed for random number generator
    int randomNumber = rand() % 100 + 1; //Generate random number between 1 and 100
    return randomNumber;
}

int main() {
    int randomNumber = generateRandomNumber(); //Get the random number
    int guess, attempts = 0; //Initialize variables
    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100...\n");
    
    //Loop until user correctly guesses the number
    while(1) {
        printf("Guess the number: ");
        scanf("%d", &guess);
        attempts++; //Increment attempts
        if(guess == randomNumber) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        } else if(guess < randomNumber) {
            printf("Too low. Guess higher.\n");
        } else {
            printf("Too high. Guess lower.\n");
        }
    }
    return 0; //End program
}