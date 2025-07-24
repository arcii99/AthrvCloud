//FormAI DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int guess, num, attempts = 0;

    // generate random number between 1-100
    srand(time(NULL));
    num = rand() % 100 + 1;

    // ask user to guess number
    printf("Guess a number between 1-100: ");

    while (1) {
        scanf("%d", &guess);
        attempts++;

        // check if guess is correct
        if (guess == num) {
            printf("Congratulations! You guessed the number in %d attempt(s)!\n", attempts);
            break;
        // check if guess is too low
        } else if (guess < num) {
            printf("Too low, try again: ");
        // check if guess is too high
        } else if (guess > num) {
            printf("Too high, try again: ");
        }
    }

    return 0;
}