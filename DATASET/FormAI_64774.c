//FormAI DATASET v1.0 Category: Random ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0; //initialize variables
    srand(time(0)); // set the random seed to the current time
    
    num = rand() % 100 + 1; // random number between 1 and 100
    printf("\n\t---Welcome to the Guessing Game!---\n\n");
    printf("Guess the number between 1 and 100: ");

    do {
        scanf("%d", &guess); // get user input
        tries++;
        
        if (guess > num) {
            printf("Too high! Guess again: ");
        }
        else if (guess < num) {
            printf("Too low! Guess again: ");
        }
        else {
            printf("\nCongratulations, you guessed the number in %d tries!", tries);
        }

    } while (guess != num);

    return 0;
}