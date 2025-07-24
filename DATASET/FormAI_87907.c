//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0;
    // Generate random number between 1 and 100
    srand(time(0)); 
    num = rand() % 100 + 1; 

    printf("\n\nWelcome to Guess the Number!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("You have 10 chances to guess the number.\n");

    // Loop until user guesses the correct number or runs out of tries
    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("\nToo high! Try again.\n");
        } else if (guess < num) {
            printf("\nToo low! Try again.\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d tries.\n", tries);
        }
    } while (guess != num && tries < 10);
    // If user runs out of tries
    if (tries == 10) {
        printf("\nGame over. You ran out of tries. The number was %d.\n", num);
    }

    return 0;
}