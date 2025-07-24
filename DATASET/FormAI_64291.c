//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, guess, counter = 0;
    srand(time(NULL)); //to get a different random number each time program runs
    randomNumber = rand() % 100 + 1; //generates a random number between 1 and 100
    
    printf("Welcome to the guessing game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess); //takes user input for guess
        
        if (guess < 1 || guess > 100) { //check if input is within range
            printf("Invalid input, please enter a number between 1 and 100.\n"); 
            continue; //continues with the while loop
        }
        
        counter++; //increments counter for number of tries
        
        if (guess == randomNumber) { //check if guess is correct
            printf("Congratulations! You guessed the number in %d tries!\n", counter);
            break; //terminates loop and program ends
        }
        else if (guess < randomNumber) { //check if guess is too low
            printf("Too low!\n");
        }
        else { //if guess is not correct or too low, it must be too high
            printf("Too high!\n");
        }
    }
    return 0;
}