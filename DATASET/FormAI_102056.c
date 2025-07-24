//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
// C Table Game Program
// This program simulates a game of chance where the player tries to guess a randomly generated number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5

int main() {
    srand(time(NULL)); // seed random number generator
    
    int number = rand() % 101; // generate random number between 0 and 100
    int guess, num_guesses = 0;
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("You have %d guesses to guess the number between 0 and 100.\n", MAX_GUESSES);
    
    do {
        printf("Guess #%d: ", num_guesses + 1);
        scanf("%d", &guess);
        num_guesses++;
        
        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations, you guessed the number!\n");
            return 0;
        }
    } while (num_guesses < MAX_GUESSES);
    
    printf("Sorry, you ran out of guesses. The number was %d.\n", number);
    
    return 0;
}