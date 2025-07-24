//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, answer, guesses = 0;
    srand(time(0));
    answer = rand() % 100 + 1;
    printf("Welcome to Guess the Number game!\n");
    printf("Guess a number between 1 and 100:\n");
    do {
        scanf("%d", &guess);
        guesses++;
        if (guess > answer) {
            printf("Lower!\n");
        }
        if (guess < answer) {
            printf("Higher!\n");
        }
    } while (guess != answer);
    printf("Congratulations! You guessed the number in %d tries.\n", guesses);

    return 0;
}