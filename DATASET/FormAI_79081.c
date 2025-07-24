//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>

int main() {
    printf("Welcome to my Grateful C Game Example Program!\n");
    printf("Let's play a game where you have to guess a number.\n");

    int randomNumber = 5;
    int guess;
    int numGuesses = 0;

    while(1) {
        printf("Enter your guess (between 1 and 10): ");
        scanf("%d", &guess);
        
        numGuesses++;

        if(guess == randomNumber) {
            printf("You guessed it! You took %d guesses.\n", numGuesses);
            break;
        } else if(guess < randomNumber) {
            printf("Too low, try again.\n");
        } else {
            printf("Too high, try again.\n");
        }
    }

    printf("\nThanks for playing my game! I hope you had fun!\n");

    return 0;
}