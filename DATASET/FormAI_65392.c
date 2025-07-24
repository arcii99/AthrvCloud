//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    int randomNumber = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess, tries = 0; // set the initial number of tries to 0
    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess a number between 1 and 100: ");
    do {
        scanf("%d", &guess);
        tries++; // increment the number of tries each time the user enters a guess
        if (guess < randomNumber) {
            printf("Too low, try again: ");
        } else if (guess > randomNumber) {
            printf("Too high, try again: ");
        } else {
            printf("Congratulations, you guessed the number in %d tries!\n", tries);
        }
    } while (guess != randomNumber);
    return 0;
}