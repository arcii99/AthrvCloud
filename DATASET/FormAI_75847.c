//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize the random seed
    int numToGuess = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guessCount = 0; // Initialize guess count to 0
    int guess; // Declare guess variable
    printf("Welcome to the guessing game!\n");
    do {
        printf("Enter a number between 1 and 100: ");
        scanf("%d", &guess);
        guessCount++;
        if(guess > numToGuess) {
            printf("Too high!\n");
        } else if (guess < numToGuess) {
            printf("Too low!\n");
        } else {
            printf("Congratulations, you guessed the number in %d tries!\n", guessCount);
        }
    } while(guess != numToGuess); // Keep looping until the guess is correct
    return 0;
}