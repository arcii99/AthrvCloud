//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, tries = 0;
    srand(time(NULL)); // Seed for random number generation
    secret_number = rand() % 100 + 1; // Choose a random number between 1 and 100
    
    printf("*** Guess the Number ***\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");
    
    do {
        tries++;
        printf("Guess #%d: ", tries);
        scanf("%d", &guess);
        
        if (guess == secret_number) {
            printf("Congratulations! You guessed my number in %d tries.\n", tries);
            break;
        } else if (guess < secret_number) {
            printf("Too low! Guess higher.\n");
        } else {
            printf("Too high! Guess lower.\n");
        }
        
        if (tries == 10) {
            printf("Sorry, you've reached the maximum number of guesses. The secret number was %d.\n", secret_number);
            break;
        }
    } while (1);
    
    return 0;
}