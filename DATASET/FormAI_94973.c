//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //seed the random number generator
    int secretNumber = rand() % 100 + 1; //generate a random number between 1-100
    int guess, numGuesses = 0; //initialize variables for the user's guess and number of guesses

    printf("Welcome to the guessing game!\n\n");
    printf("I have chosen a number between 1 and 100. Can you guess it?\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess); //get the user's guess
        numGuesses++; //increase the number of guesses taken

        if(guess < secretNumber) {
            printf("Too low. Guess again.\n");
        } else if(guess > secretNumber) {
            printf("Too high. Guess again.\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d guesses.\n", numGuesses);
            break; //exit the loop
        }
    } while(1); //infinite loop until the number is guessed correctly

    return 0; //end of program
}