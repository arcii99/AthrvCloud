//FormAI DATASET v1.0 Category: Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, guess, tries = 0;
    srand(time(0));
    n = rand() % 100 + 1; // generates random number between 1 to 100
    printf("Welcome to the guessing game!\n");
    printf("Guess a number between 1 to 100\n");
    do {
        scanf("%d", &guess);
        tries++;
        if(guess > n) {
            printf("Too high! Guess again.\n");
        } else if(guess < n) {
            printf("Too low! Guess again.\n");
        } else {
            printf("\nCongratulations, you guessed the number in %d tries!", tries);
        }
    } while(guess != n);
    return 0;
}