//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int num, guess, tries = 0;
    srand(time(NULL));
    num = rand() % 100 + 1; //generates a random number between 1 and 100
    
    printf("\n*********************************************************");
    printf("\n***\t\tWelcome to the Guessing Game!\t\t***");
    printf("\n*********************************************************\n\n");
    
    printf("I have a number between 1 and 100. Can you guess it?\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;
        
        if (guess > num) {
            printf("Too high! Try again.\n");
        } else if (guess < num) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed it in %d tries!\n", tries);
        }
        
    } while (guess != num);
    
    return 0;
}