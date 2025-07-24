//FormAI DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate a random number from 1 to 100
int generateRandomNumber() {
    srand(time(NULL));
    int randomNum = rand() % 100 + 1; //generate a random number from 1-100
    return randomNum;
}

int main() {
    int randomNumber = generateRandomNumber(); //get the random number
    int guess = 0; //initialize the guess to 0
    int attempts = 0; //initialize the attempts to 0
    
    printf("Welcome to the number guessing game!\n"); //welcome message
    
    //loop until the user gets the correct answer or uses all the attempts
    while(guess != randomNumber && attempts != 10) {
        printf("Guess a number from 1 to 100: ");
        scanf("%d", &guess); //get the user's guess
        
        if(guess < randomNumber) {
            printf("Too low! Try again.\n"); //user's guess is too low
        }
        else if(guess > randomNumber) {
            printf("Too high! Try again.\n"); //user's guess is too high
        }
        attempts++; //increment the number of attempts
    }
    
    if(guess == randomNumber) {
        printf("Congratulations! You guessed the correct number in %d attempts.\n", attempts); //user guessed the right number
    }
    else {
        printf("Sorry, you ran out of attempts. The correct number was %d.\n", randomNumber); //user ran out of attempts
    }
    
    return 0;
}