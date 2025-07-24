//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int guess;
    srand(time(NULL)); // Seed the random number generator with the current time
    int target = rand() % 100; // Generate a random number between 0 and 99
    printf("Welcome to Guess the Number!\n");
    printf("I'm thinking of a number between 0 and 99. Can you guess it?\n");
    while (1) {
        printf("Enter your guess (or -1 to quit): ");
        scanf("%d", &guess);
        if (guess == -1) {
            break; // User wants to quit
        }
        if (guess < target) {
            printf("Too low! Try again.\n");
        } else if (guess > target) {
            printf("Too high! Try again.\n");
        } else {
            // User guessed the number!
            printf("Congratulations! You guessed the number in %d tries.\n", score);
            break;
        }
        score++;
    }
    printf("Thanks for playing!\n");
    return 0;
}