//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number, attempts = 0;
    srand(time(0)); // Seed the random number generator
    
    // Generate a random number between 1 and 100
    number = rand() % 100 + 1;
    
    printf("Welcome to the guessing game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    
    do {
        printf("Guess the number: ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess > number) {
            printf("Too high! Try guessing a lower number.\n");
        } else if (guess < number) {
            printf("Too low! Try guessing a higher number.\n");
        } else {
            printf("Congratulations, you guessed the number in %d attempts!\n", attempts);
        }
    } while (guess != number);
    
    return 0;
}