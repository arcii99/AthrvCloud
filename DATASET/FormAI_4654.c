//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between 1 and 100
int generateRandomNumber() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

int main() {
    int randomNumber = generateRandomNumber();
    int userInput, numOfAttempts = 0;

    printf("Welcome to the Guess the Number Game!\n");
    printf("You have 10 attempts to guess a number between 1 and 100.\n");
    printf("Good luck!\n");

    // loop to receive user input and check if it is correct
    while(numOfAttempts < 10) {
        printf("Attempt %d: ", numOfAttempts+1);
        scanf("%d", &userInput);

        if(userInput == randomNumber) {
            printf("Congratulations! You guessed the number in %d attempts!\n", numOfAttempts+1);
            return 0;
        } else if(userInput < randomNumber) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }

        numOfAttempts++;
    }

    printf("Sorry, you ran out of attempts. The number was %d.\n", randomNumber);

    return 0;
}