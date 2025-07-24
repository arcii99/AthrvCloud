//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed rand() function with current time
    int answer = rand() % 10 + 1; // Generate random answer between 1 and 10
    int guess, numTries = 0;

    printf("Welcome to the guessing game!\n");
    printf("I'm thinking of a number between 1 and 10. Can you guess it?\n");

    do {
        printf("Enter your guess (1-10): ");
        scanf("%d", &guess);
        numTries++;

        if (guess == answer) {
            printf("Congratulations! You guessed my number in %d tries.\n", numTries);
        } else if (guess < answer) {
            printf("Sorry, your guess is too low. Try again.\n");
        } else {
            printf("Sorry, your guess is too high. Try again.\n");
        }
    } while (guess != answer);

    return 0;
}