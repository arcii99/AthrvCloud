//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num, guess, attempts = 0;
    srand(time(0));
    num = rand() % 100 + 1;

    printf("Welcome to the Guess the Number Game!\n");
    printf("Guess a number between 1 and 100\n\n");

    while(1) {

        printf("Enter your guess: ");
        if(scanf("%d", &guess) != 1) {
            printf("\nInvalid input. Enter only numbers.\n\n");
            fflush(stdin);
            continue;
        } 

        attempts++;
        if(guess < num) {
            printf("Too low! Try again.\n\n");
        } else if(guess > num) {
            printf("Too high! Try again.\n\n");
        } else {
            printf("\nCongratulations, you guessed the number in %d attempts!\n", attempts);
            break;
        }
    }

    return 0;
}