//FormAI DATASET v1.0 Category: Random ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main() {
    int num, guess, tries = 0;
    
    srand(time(0)); // seed random number generator
    
    num = rand() % 100 + 1; // random number between 1 and 100
    
    printf("\nWelcome to the Random Number Generator!\n");
    printf("Can you guess the randomly generated number between 1 and 100?\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;
        
        if (guess > num) {
            printf("Sorry! That's too high.\n");
        } else if (guess < num) {
            printf("Sorry! That's too low.\n");
        }
    } while (guess != num);
    
    printf("\nCongratulations! You guessed the number in %d tries.\n", tries);
    
    return 0;
}