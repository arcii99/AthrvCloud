//FormAI DATASET v1.0 Category: Game ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    // Initializing variables
    int guess, num, attempts = 0;
    srand(time(0));
    num = rand() % 100 + 1; // Generating random number between 1 to 100

    // Instructions for user
    printf("Welcome to Guess the Number Game!\n");
    printf("I am thinking of a number between 1 to 100. Guess the number!\n");

    // Looping for user's guess
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++; // Incrementing the attempts
        if(guess > num) printf("Too high! Try again.\n");
        else if(guess < num) printf("Too low! Try again.\n");
        else printf("Congratulations! You guessed it in %d attempts.\n", attempts);
    } while(guess != num);

    return 0;
}