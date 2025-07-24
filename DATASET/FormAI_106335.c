//FormAI DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //used to initialize the random number generator
    int num = rand() % 101; //generates a random number between 0-100
    int guess, numGuesses = 0;

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 0 and 100, can you guess what it is?\n");

    do{
        printf("Enter your guess (0-100): ");
        scanf("%d", &guess);
        numGuesses++;

        if(guess < num){
            printf("Too low, try again!\n");
        } else if(guess > num){
            printf("Too high, try again!\n");
        } else{
            printf("Congratulations, you guessed the number in %d guesses!\n", numGuesses);
        }
    } while(guess != num);

    return 0;
}