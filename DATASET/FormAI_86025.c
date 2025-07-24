//FormAI DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int num = rand() % 100; // generates a random number between 0 and 99
    printf("Guess a number between 0 and 99: ");
    
    int guess;
    if (scanf("%d", &guess) != 1) { // checks if input is valid
        fprintf(stderr, "Error: Invalid input\n");
        exit(1);
    }
    
    int i = 0;
    while (guess != num) {
        if (i >= 3) { // limits the number of guesses to 3
            fprintf(stderr, "Error: No more guesses allowed\n");
            exit(1);
        }
        
        if (guess < 0 || guess > 99) { // checks if guess is within range
            fprintf(stderr, "Error: Guess is out of range\n");
            exit(1);
        }
        
        if (guess < num) {
            printf("Too low, guess again: ");
        } else {
            printf("Too high, guess again: ");
        }
        
        if (scanf("%d", &guess) != 1) { // checks if input is valid
            fprintf(stderr, "Error: Invalid input\n");
            exit(1);
        }
        
        i++;
    }
    
    printf("Congratulations, you guessed correctly!\n");
    
    return 0;
}