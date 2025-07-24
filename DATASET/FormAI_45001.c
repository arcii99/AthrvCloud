//FormAI DATASET v1.0 Category: Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number, attempts = 0;
    srand(time(NULL));
    number = rand() % 100 + 1;
    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    while(1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        if(guess == number) {
            printf("Congratulations, you guessed the number in %d attempts!\n", attempts);
            break;
        }
        else if(guess < number)
            printf("Too low! Try again.\n");
        else
            printf("Too high! Try again.\n");
    }
    return 0;
}