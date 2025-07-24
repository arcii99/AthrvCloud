//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // seed the random number generator
    
    int guess, num_attempts = 0;
    int secret_num = rand() % 100 + 1;  // pick a secret number between 1 and 100
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    
    do {
        printf("Guess a number: ");
        scanf("%d", &guess);  // get the user's guess
        
        num_attempts++;  // increment the number of attempts
        
        if (guess < secret_num) {
            printf("Too low! Guess higher.\n");
        } else if (guess > secret_num) {
            printf("Too high! Guess lower.\n");
        } else {
            printf("Congratulations! You guessed my number in %d attempts!\n", num_attempts);
        }
        
    } while (guess != secret_num);
    
    return 0;
}