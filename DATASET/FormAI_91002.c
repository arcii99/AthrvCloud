//FormAI DATASET v1.0 Category: Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator with time
    
    int number = rand() % 100 + 1; // generate random number between 1 and 100
    int guess = 0; // initialize guess variable
    int num_guesses = 0; // initialize guess counter
    
    printf("Welcome to the guessing game!\n");
    printf("Guess a number between 1 and 100.\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess); // read input guess from user
        num_guesses++; // increment guess counter
        
        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        }
    } while (guess != number); // repeat until correct guess is made
    
    printf("Congratulations, you guessed the number in %d tries!\n", num_guesses);
    
    return 0;
}