//FormAI DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));      //To ensure random numbers are generated
    int num, guess, tries = 0;
    num = rand() % 100 + 1;  //Generate a number from 1-100
    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess the number between 1 and 100:\n");
    
    do {
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Lower! Try again:\n");
        }
        else if (guess < num) {
            printf("Higher! Try again:\n");
        }
        else {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != num);
    
    return 0;
}