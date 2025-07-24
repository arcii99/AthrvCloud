//FormAI DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10

int main() {
    srand(time(0)); // Initialize time seed for random guesses
    
    int random_number = rand() % 100 + 1; // Generate random number between 1 and 100
    int guess_count = 0;
    int guess;
    
    printf("Welcome to the number guessing game!\n");
    printf("Guess a number between 1 and 100 (inclusive).\n");
    
    while (guess_count < MAX_GUESSES) {
        printf("Guess %d: ", guess_count + 1);
        scanf("%d", &guess);
        
        if (guess == random_number) {
            printf("Congratulations! You guessed the number!\n");
            return 0;
        } else if (guess < random_number) {
            printf("Too low. Guess again.\n");
        } else {
            printf("Too high. Guess again.\n");
        }
        
        guess_count++;
    }
    
    printf("Sorry, you ran out of guesses. The number was %d.\n", random_number);
    return 0;
}