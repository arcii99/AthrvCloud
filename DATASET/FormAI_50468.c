//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number, attempts = 0;
    srand(time(0));  // Initializes random number seed based on current time
    number = rand() % 100 + 1;  // Generates random number between 1 and 100
    printf("Guess the number between 1 and 100!\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;  // Increments attempt count
        if(guess > number) {
            printf("Too high!\n");
        } else if(guess < number) {
            printf("Too low!\n");
        }
    } while(guess != number);
    
    // Game over. Player guessed correctly.
    printf("Congratulations! You guessed it in %d attempts.\n", attempts);
    return 0;
}