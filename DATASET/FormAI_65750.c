//FormAI DATASET v1.0 Category: Funny ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int magic_number, guess, num_attempts = 0;
    srand(time(0)); // Seed the random number generator
    magic_number = rand() % 100 + 1; // Generate a random number between 1 and 100
    
    printf("Welcome to the Magic Number game!\n\n");
    
    do {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        
        if(guess < 1 || guess > 100) {
            printf("Invalid guess. Please enter a number between 1 and 100.\n");
            continue;
        }
        
        num_attempts++;
        
        if(guess < magic_number) {
            printf("Too low! Try again.\n");
        } else if(guess > magic_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You won in %d attempts.\n", num_attempts);
        }
    } while(guess != magic_number);
    
    return 0;
}