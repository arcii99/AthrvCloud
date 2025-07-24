//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to randomly generate a number between 1 and 100
int generateRandomNumber(){
    srand(time(NULL));     // seed the random number generator
    int randomNumber = rand() % 100 + 1;     // generate a random number between 1 and 100
    return randomNumber;
}

int main(){
    int randomNumber = generateRandomNumber();
    int guess, numOfTries = 0;
    printf("Welcome to the guessing game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    do {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &guess);
        numOfTries++;

        if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries!\n", numOfTries);
        }
    } while (guess != randomNumber);

    return 0;
}