//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int count = 0, guess, number;
    srand(time(NULL));
    number = rand() % 100;

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100! Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;
        if (guess < number) {
            printf("Too Low! Try Again!\n");
        } else if (guess > number) {
            printf("Too High! Try Again!\n");
        } else {
            printf("You Win! Congrats! You guessed the number in %d tries!\n", count);
        }
    } while (guess != number);

    return 0;
}