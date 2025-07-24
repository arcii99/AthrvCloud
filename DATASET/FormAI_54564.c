//FormAI DATASET v1.0 Category: Game ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate a random number
int generateRandomNumber(int lower, int upper){
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main(){
    int numToGuess, guess, numTries=1;
    srand(time(0)); //seeding the random number generator
    
    //intro message
    printf("Welcome to guess the number game!\n");
    printf("I am thinking of a number between 1 and 100, can you guess it?\n\n");

    //generate a random number to guess
    numToGuess = generateRandomNumber(1, 100);

    //loop until the number is guessed correctly
    do{
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess < numToGuess){
            printf("Too low! Guess higher.\n");
        }
        else if(guess > numToGuess){
            printf("Too high! Guess lower.\n");
        }
        else{
            printf("Congratulations! You guessed it in %d tries!\n", numTries);
        }

        numTries++;
    } while(guess != numToGuess);

    //exit message
    printf("\nThank you for playing the game!");

    return 0;
}