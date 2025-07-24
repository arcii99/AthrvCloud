//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialization
    srand(time(NULL));
    int num = rand() % 100 + 1;  // Generate random number from 1 to 100
    int guess = 0;
    int tries = 0;

    // Game loop
    while (guess != num) {
        printf("Guess a number from 1 to 100: ");
        scanf("%d", &guess);
        tries++;

        if (guess < num) {
            printf("Too low! Try again.\n");
        } else if (guess > num) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
        }
    }

    return 0;
}