//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between two given numbers
int randomNumber(int min, int max) {
    srand(time(NULL));  // set seed based on current time
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int numGuesses, guessLimit, secretNum, guess;
    
    printf("Welcome to the number guessing game!\n");
    
    // get user input for number of guesses and guess limit
    printf("How many guesses would you like?\n");
    scanf("%d", &numGuesses);
    printf("What should the guess limit be?\n");
    scanf("%d", &guessLimit);
    
    // generate a secret number between 1 and guessLimit
    secretNum = randomNumber(1, guessLimit);
    
    // loop through each guess until limit is reached or secret number is guessed
    for (int i = 1; i <= numGuesses; i++) {
        printf("Guess #%d: ", i);
        scanf("%d", &guess);
        
        if (guess < secretNum) {
            printf("Too low!\n");
        } else if (guess > secretNum) {
            printf("Too high!\n");
        } else {
            printf("Congratulations! You guessed the secret number in %d guesses.\n", i);
            return 0;
        }
    }
    
    printf("Sorry, you ran out of guesses. The secret number was %d.\n", secretNum);
    
    return 0;
}