//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0));  // Seed random number generator
    
    int guess, num, tries = 0;
    num = rand() % 100 + 1;  // Generate random number between 1 and 100
    
    printf("\nWelcome to the Guess the Number game! I am thinking of a number between 1 and 100. Try to guess it.\n");
    
    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        tries++;
        
        if (guess > num)
            printf("Too high! Try again.\n");
        else if (guess < num)
            printf("Too low! Try again.\n");
        else
            printf("\nCongratulations! You guessed the number in %d tries.\n", tries);
        
    } while (guess != num);
    
    return 0;
}