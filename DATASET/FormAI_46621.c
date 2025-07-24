//FormAI DATASET v1.0 Category: Random ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random_number = 0, guess = 0, tries = 0;
    srand(time(NULL)); // Seed the random number generator with the current time
    
    random_number = rand() % 100 + 1; // Generate a random number between 1 and 100
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");
    
    do {
        printf("Guess #%d: ", tries + 1); // Prompt the user for their guess
        scanf("%d", &guess); // Read their guess from the keyboard
        
        if (guess < random_number) {
            printf("Too low! Try again!\n");
            tries++;
        } else if (guess > random_number) {
            printf("Too high! Try again!\n");
            tries++;
        } else {
            printf("Congratulations! You guessed the number in %d tries!\n", tries + 1);
        }
    } while (guess != random_number);
    
    return 0;
}