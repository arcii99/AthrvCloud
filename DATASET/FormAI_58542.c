//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_GUESSES 5

int main() {
    int num, guess, tries = 0;
    
    srand(time(0));
    num = rand() % 100 + 1; // Generate a random number between 1 and 100
    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    
    while (tries < MAX_GUESSES) {
        printf("Guess #%d: ", tries + 1);
        scanf("%d", &guess);
        
        if (guess == num) {
            printf("Congratulations! You guessed my number in %d tries.", tries + 1);
            break;
        } else if (guess < num) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }
        tries++;
    }
    
    if (tries == MAX_GUESSES) {
        printf("Sorry, you ran out of guesses. The number was %d.\n", num);
    }

    return 0;
}