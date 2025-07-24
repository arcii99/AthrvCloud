//FormAI DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, answer, attempts = 0;
    srand(time(NULL));
    answer = rand() % 100 + 1;

    printf("\nWelcome to the Number Guessing Game!\n");
    printf("\nI am thinking of a number between 1 and 100. Can you guess it?\n");

    do {
        printf("\nEnter your guess (1-100): ");
        scanf("%d", &guess);
        attempts++;

        if (guess < answer) {
            printf("Too low, try again.\n");
        } else if (guess > answer) {
            printf("Too high, try again.\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d attempts!\n\n", attempts);
            break;
        }
    } while (guess != answer);

    return 0;
}