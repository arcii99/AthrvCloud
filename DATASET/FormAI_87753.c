//FormAI DATASET v1.0 Category: Random ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, num, count = 0;
    srand(time(0));  // Generates random seed

    printf("Welcome to the C Random Guessing Game!\n");
    printf("I'm thinking of a number from 1 to 100.\n");
    printf("Can you guess the number?\n");

    num = rand() % 100 + 1;  // Generates random number between 1 and 100
    
    while (guess != num) {  // Loop until guess is equal to the random number
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;  // Increase guess count

        if (guess > num) {
            printf("Too high! Guess again.\n");
        } else if (guess < num) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", count);
        }
    }

    return 0;
}