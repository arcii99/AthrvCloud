//FormAI DATASET v1.0 Category: Random ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random_number;
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to the Random Number Game!\n");
    printf("I am thinking of a number between 1 and 1000.\n");
    printf("Can you guess what it is?\n\n");
    
    random_number = rand() % 1000 + 1; // Generate a random number between 1 and 1000
    
    int guess;
    int attempts = 0;
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess < random_number) {
            printf("Too low, try again.\n\n");
        } else if (guess > random_number) {
            printf("Too high, try again.\n\n");
        } else {
            printf("Congratulations, you guessed the number in %d attempts!\n", attempts);
        }
    } while (guess != random_number);
    
    return 0;
}