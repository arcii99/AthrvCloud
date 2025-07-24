//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL)); // Initializing the random number generator
    int targetNumber = rand() % 100; // Generating a random number between 0 to 100
    int attempts = 0; // variable to keep track of the number of attempts taken
    int guessedNumber = -1; 

    printf("Welcome to the Number Guessing Game!\n");
    printf("You have to guess the target number between 0 to 100.\n");

    while(guessedNumber != targetNumber){
        
        printf("Guess the number: ");
        scanf("%d", &guessedNumber);
        attempts++; // Increasing the number of attempts

        if(guessedNumber > targetNumber){
            printf("OOPS! The target number is smaller than %d\n", guessedNumber);
        }
        else if(guessedNumber < targetNumber){
            printf("OOPS! The target number is greater than %d\n", guessedNumber);
        }
        else{
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }

    }
    return 0;
}