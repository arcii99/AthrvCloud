//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer, guess, guess_count = 0;
    srand(time(NULL));
    answer = rand() % 100 + 1;
    printf("Welcome to the Guessing Game!\n");
    printf("Guess a number between 1 and 100: ");
    do {
        scanf("%d", &guess);
        guess_count++;
        if (guess > answer) {
            printf("Too high, try again: ");
        } else if (guess < answer) {
            printf("Too low, try again: ");
        }
    } while (guess != answer);
    printf("Congratulations! You guessed the answer in %d tries\n", guess_count);
    return 0;
}