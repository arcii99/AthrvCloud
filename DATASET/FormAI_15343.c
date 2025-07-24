//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, num, tries = 0;
    srand(time(NULL));
    num = rand() % 100 + 1;  // generate a random number between 1 and 100
    
    printf("Welcome to the Number Guessing game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Can you guess it?\n");
    
    do {
        printf("Guess a number: ");
        scanf("%d", &guess);
        tries++;
        
        if (guess > num) {
            printf("Too high! Try again.\n\n");
        } else if (guess < num) {
            printf("Too low! Try again.\n\n");
        }
    } while (guess != num);
    
    printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
    return 0;
}