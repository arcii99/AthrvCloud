//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    printf("WELCOME TO THE NUMBER GUESSING GAME\n");
    printf("I am thinking of a number between 1 and 100, can you guess it?\n");
    
    int num = rand() % 100 + 1; // generate random number
    
    int guess;
    int tries = 1;
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        if (guess == num) {
            printf("Congratulations! You guessed it in %d tries!\n", tries);
            break;
        } else if (guess < num) {
            printf("Too low, try again.\n");
        } else {
            printf("Too high, try again.\n");
        }
        
        tries++;
    }
    
    printf("Thanks for playing!\n");
    return 0;
}