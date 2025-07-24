//FormAI DATASET v1.0 Category: Game ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); // seed for generating random numbers
    int randNumber = rand() % 100; // generating a random number between 0 and 99
    int userGuess, tries=0;
    
    printf("Welcome to the Guessing Game!\n");
    printf("Enter a number between 0 and 99: ");
    
    do {
        scanf("%d", &userGuess);
        tries++;
        if(userGuess > randNumber){
            printf("Too high, try again: ");
        }
        else if(userGuess < randNumber){
            printf("Too low, try again: ");
        }
        else{
            printf("Congratulations, you guessed the number in %d tries!", tries);
        }
    } while(userGuess != randNumber);
    
    return 0;
}