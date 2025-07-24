//FormAI DATASET v1.0 Category: Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // introduction
    printf("Welcome to a peaceful game!\n\n");
    printf("The goal of this game is to guess a random number between 1 and 100.\n\n");
    
    // variables
    int randomNumber, guess;
    srand(time(0));
    randomNumber = rand() % 100 + 1;
    int tries = 0;
    
    // game loop
    do {
        // get user input
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        // check if guess is correct
        if (guess == randomNumber) {
            printf("\nCongratulations! You guessed the correct number in %d tries.\n", tries);
            break;
        }
        else {
            // give feedback and try again
            tries++;
            if (guess < randomNumber) {
                printf("Too low! Try again.\n\n");
            }
            if (guess > randomNumber) {
                printf("Too high! Try again.\n\n");
            }
        }
    } while (guess != randomNumber);
    
    return 0;
}