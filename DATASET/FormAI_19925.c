//FormAI DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize game variables
    int guess, num, tries = 0;
    srand(time(0)); // seed random number generator
    num = rand() % 100 + 1; // generate random number between 1-100
    
    printf("--- Welcome to the Guessing Game! ---\n");
    printf("You have 10 tries to guess the secret number.\n");
    
    // loop for 10 tries
    while (tries < 10) {
        printf("\nEnter your guess (between 1-100): ");
        scanf("%d", &guess);
        tries++;
        
        // check if guess is correct
        if (guess == num) {
            printf("\n=== Congratulations, you guessed the secret number in %d tries! ===\n", tries);
            break; // exit loop if guess is correct
        }
        
        // provide feedback on guess
        if (guess < num) {
            printf("Too low. ");
        } else {
            printf("Too high. ");
        }
        printf("You have %d tries left.\n", 10-tries);
    }
    
    // if all 10 tries are used and the secret number is not guessed, the player loses
    if (tries == 10 && guess != num) {
        printf("\n=== Game over! You didn't guess the secret number. The number was %d. ===\n", num);
    }
    
    return 0;
}