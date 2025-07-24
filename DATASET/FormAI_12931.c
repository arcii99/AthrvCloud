//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Generate random number between 1 and 100
    srand(time(NULL));
    const int answer = rand() % 100 + 1;
    
    // Player gets 10 attempts to guess the random number
    int attempts = 10;
    int guess;
    
    printf("Welcome to the Number Guessing Game! You have 10 attempts to guess the secret number between 1 and 100.\n");
    while (attempts > 0) {
        printf("You have %d attempts left.\n", attempts);
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        if (guess == answer) {
            printf("Congratulations! You guessed the secret number %d!\n", answer);
            break;
        } else if (guess < answer) {
            printf("Your guess is too low.\n");
        } else {
            printf("Your guess is too high.\n");
        }
        
        attempts--;
    }
    
    if (attempts == 0) {
        printf("Sorry, you have run out of guesses. The secret number was %d. Better luck next time!\n", answer);
    }
    
    return 0;
}