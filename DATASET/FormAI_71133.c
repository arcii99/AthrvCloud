//FormAI DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer, guess, attempts = 0;
    
    // create random number
    srand(time(NULL));
    answer = rand() % 100 + 1;
    
    // greet the user
    printf("Welcome to the Happy Guessing Game! The goal is to guess a number between 1 and 100, and you have unlimited attempts. Good luck!\n");
    
    do {
        // get user's guess
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        
        if(guess > answer) {
            printf("Too high! Guess again!\n");
        }
        else if(guess < answer) {
            printf("Too low! Guess again!\n");
        }
        else {
            printf("Congratulations! You guessed the correct number in %d attempts!", attempts);
        }
    } while(guess != answer);
    
    return 0;
}