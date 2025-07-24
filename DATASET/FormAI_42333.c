//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));     //seed for random number generator
    int randomNumber = rand() % 100 + 1;  //random number between 1-100
    int guess, numberOfGuesses = 0;
    
    printf("Welcome to the Guessing Game!\n");
    printf("I have a number between 1 and 100. Can you guess it?\n\n");

    while (1) {     //infinite loop until correct guess
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numberOfGuesses++;    //keep track of number of guesses
        
        if (guess == randomNumber) {    //correct guess
            printf("\nCongratulations! You guessed the correct number in %d guesses.\n", numberOfGuesses);
            break;  //exit loop
        }
        else if (guess < randomNumber) {    //guess is too low
            printf("Sorry, your guess is too low. Please try again.\n");
        }
        else {    //guess is too high
            printf("Sorry, your guess is too high. Please try again.\n");
        }
    }

    printf("\nThank you for playing!\n");
    return 0;
}