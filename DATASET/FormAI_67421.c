//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5    // maximum number of tries
#define RANGE 100      // range of the random number generator

int attempt;

// function to generate a random number between 1 and RANGE
int generateNumber(){
    srand(time(0));
    return rand() % RANGE + 1;
}

// function to check if the guess is correct
int checkGuess(int guess, int number){
    if (guess > number)
        printf("Too high! ");
    else if (guess < number)
        printf("Too low! ");
    else
        return 1;   // the guess is correct
    return 0;
}

int main(){
    int number = generateNumber();  // generate the random number
    int guess;                      // the user's guess

    printf("Welcome to the number guessing game!\n");
    printf("I'm thinking of a number between 1 and %d. You have %d tries to guess it.\n\n", RANGE, MAX_TRIES);

    // loop until the user guesses the number or runs out of tries
    for (attempt = 0; attempt < MAX_TRIES; attempt++){
        printf("Guess #%d: ", attempt+1);
        scanf("%d", &guess);
        if (checkGuess(guess, number)){
            printf("Congratulations, you guessed the number in %d tries!\n", attempt+1);
            return 0;   // exit the program
        }
        printf("You have %d more tries.\n\n", MAX_TRIES-attempt-1);
    }

    // if the user runs out of tries
    printf("Sorry, you ran out of tries. The number was %d.\n", number);
    return 0;
}