//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, count = 0;
    srand(time(0)); // Set seed for random number generator
    num = rand() % 100 + 1; // Generate random number between 1 to 100
    
    printf("Welcome to the Guessing Game!\n");
    printf("I have selected a number between 1 and 100. Can you guess it?\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++; // Increment count of guesses
        
        if (guess > num) {
            printf("Too high!\n");
        } else if (guess < num) {
            printf("Too low!\n");
        } else {
            printf("Congratulations, you guessed it in %d attempts!\n", count);
        }
    } while (guess != num);
    
    return 0;
}