//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, guess, num;
    int gameOn = 1;
    srand(time(NULL));
    
    while (gameOn) {
        num = rand() % 100 + 1; // generate random number between 1 and 100 (inclusive)
        printf("\nI'm thinking of a number between 1 and 100. Can you guess what it is?\n");
        choice = 1;
        while (choice) {
            printf("Enter your guess (or enter 0 to quit): ");
            scanf("%d", &guess);
            
            if (guess == 0) { // user chooses to quit
                printf("Thanks for playing! Goodbye!\n");
                choice = 0;
                gameOn = 0;
            } else if (guess == num) { // user guesses correctly
                printf("Congratulations! You guessed the number!\n");
                choice = 0;
            } else if (guess < num) { // user's guess is too low
                printf("Oops! Your guess is too low! Try again!\n");
            } else if (guess > num) { // user's guess is too high
                printf("Oops! Your guess is too high! Try again!\n");
            }
        }
    }
    return 0;
}