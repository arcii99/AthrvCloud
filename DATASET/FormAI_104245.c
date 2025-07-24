//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 and 100
int generateNumber(){
    srand(time(0));
    return rand() % 100 + 1;
}

int main(){
    int numberToGuess = generateNumber();
    int userGuess;
    int numGuesses = 0;

    printf("Welcome to the Guessing Game!\n\n");
    printf("I have chosen a number between 1 and 100. Can you guess what it is?\n");

    do{
        printf("\nEnter your guess: ");
        scanf("%d", &userGuess);

        if(userGuess < 1 || userGuess > 100){
            printf("Please enter a valid guess between 1 and 100.\n");
            continue;
        }

        numGuesses++;

        if(userGuess < numberToGuess){
            printf("Too low. Guess again.\n");
        }
        else if(userGuess > numberToGuess){
            printf("Too high. Guess again.\n");
        }
        else{
            printf("\nCongratulations! You guessed the number in %d tries.\n", numGuesses);
        }

    }while(userGuess != numberToGuess);

    return 0;
}