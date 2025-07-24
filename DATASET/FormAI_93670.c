//FormAI DATASET v1.0 Category: Funny ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator
    
    printf("Hello there! Let's play a guessing game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    
    int randomNum = rand() % 100 + 1; // generate random number
    int guessCounter = 0; // initialize guess counter
    
    while (1) {
        int guess; // initialize guess variable
        printf("Take a guess: ");
        scanf("%d", &guess);
        
        if (guess < 1 || guess > 100) {
            printf("That's not a valid guess! Please choose a number between 1 and 100.\n");
        } else if (guess < randomNum) {
            printf("Too low! Try again.\n");
        } else if (guess > randomNum) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts!\n", guessCounter);
            break;
        }
        
        guessCounter++; // increment guess counter
    }
    
    printf("Thanks for playing! Come back soon!\n");
    
    return 0;
}