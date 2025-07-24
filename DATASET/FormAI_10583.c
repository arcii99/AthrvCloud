//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    int num, guess, tries = 0;
    srand(time(0)); 
    num = rand() % 100 + 1; 
    printf("Welcome to the Guess the Number Game!\n");
    printf("Guess a number between 1 and 100.\n");
    do {
        scanf("%d", &guess);
        tries++;
        if (guess > num) {
            printf("Too high! Guess again.\n");
        } else if (guess < num) {
            printf("Too low! Guess again.\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != num);
    
    return 0;
}