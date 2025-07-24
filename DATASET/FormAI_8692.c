//FormAI DATASET v1.0 Category: Random ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int random = rand() % 100 + 1;
    printf("Hello! I am a cheerful C program that generates random numbers.\n");
    printf("I am thinking of a number between 1 and 100.\n");
    int guess = 0;
    int numOfGuesses = 0;
    while(guess != random) {
        numOfGuesses++;
        printf("Guess #%d, what number am I thinking of?\n", numOfGuesses);
        scanf("%d", &guess);
        if(guess < random) {
            printf("Too low, try again.\n");
        } else if(guess > random) {
            printf("Too high, try again.\n");
        } else {
            printf("Congratulations, you guessed it in %d tries!\n", numOfGuesses);
        }
    }
    return 0;
}