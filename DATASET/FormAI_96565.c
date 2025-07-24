//FormAI DATASET v1.0 Category: Game ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));          //seed the random number generator with the current time
    int answer = rand()%101;    //generate a random number between 0 and 100
    int guess = -1;             //initialize guess with an invalid value
    int attempts = 0;           //initialize attempts counter
    printf("Welcome to Guess The Number game!\n");
    while(guess!=answer){       //keep looping until the player guesses the correct number
        printf("Please enter your guess (a number between 0 and 100): ");
        scanf("%d", &guess);    //read the player's guess from the input
        attempts++;             //increment the attempts counter
        if(guess<answer){
            printf("Too low, try again.\n");
        }else if(guess>answer){
            printf("Too high, try again.\n");
        }
    }
    printf("Congratulations, you guessed the number %d in %d attempts!\n", answer, attempts);
    return 0;
}