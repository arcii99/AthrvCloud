//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    int random_number = rand() % 10 + 1; // generate random number between 1 and 10
    int guess;
    int tries = 0;

    printf("Welcome to the Guessing Game!\n");
    printf("Try to guess the number between 1 and 10.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;
        
        if (guess == random_number) {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
            break;
        } else if (guess < random_number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    } while (1);

    printf("Thanks for playing!\n");

    return 0;
}