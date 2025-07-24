//FormAI DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int randomNumber, guess, count = 0; 
    srand(time(0)); 
    randomNumber = rand() % 100 + 1; 

    printf("\nWelcome to the Guessing Game!\n");
    printf("I'm thinking of a number from 1 to 100.\n");

    do {
        printf("Guess the number: "); 
        scanf("%d", &guess); 
        count++; 

        if (guess > randomNumber) {
            printf("Too high. Try again.\n"); 
        } else if (guess < randomNumber) {
            printf("Too low. Try again.\n"); 
        } else {
            printf("\nCongratulations! You guessed the number in %d tries.\n", count); 
        }
    } while (guess != randomNumber); 

    return 0; 
}