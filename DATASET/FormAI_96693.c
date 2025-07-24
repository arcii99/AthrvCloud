//FormAI DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate random number
int generateRandomNumber(int lower, int upper){
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main(){
    int guessCount = 0; //count of total guesses
    int lowerLimit = 1; //lower limit for random number
    int upperLimit = 100; //upper limit for random number
    int randomNumber = generateRandomNumber(lowerLimit, upperLimit); //generate random number between upper and lower limit
    
    printf("Welcome to the number guessing game!\n");
    printf("Guess a number between %d and %d\n", lowerLimit, upperLimit);
    
    while(1){
        int userGuess = 0;
        printf("Enter your guess: ");
        scanf("%d", &userGuess);
        
        guessCount++;
        
        if(userGuess == randomNumber){ //if user guesses the number correctly
            printf("Congratulations! You guessed the number in %d tries\n", guessCount);
            break;
        }
        
        else if(userGuess < randomNumber){ //if user's guess is smaller than the random number
            printf("Too low! Guess higher\n");
        }
        
        else{ //if user's guess is larger than the random number
            printf("Too high! Guess lower\n");
        }
    }
    
    return 0;
}