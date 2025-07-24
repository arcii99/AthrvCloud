//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int guess, number = rand() % 100 + 1; // generate a random number between 1 to 100
    int tries = 0; // initialize the number of tries taken to 0

    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 1 to 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > number) {
            printf("Your number is too high. Try a smaller number.\n");
        } else if (guess < number) {
            printf("Your number is too low. Try a bigger number.\n");
        } else {
            printf("Congratulations! You have guessed the number in %d tries.\n", tries);
        }
    } while (guess != number);

    return 0;
}