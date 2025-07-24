//FormAI DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int guess, num;
    int count = 1;
    srand(time(NULL));
    num = rand() % 10 + 1;

    printf("Welcome to the Number Guessing Game!\nGuess a number between 1 and 10:\n");
    scanf("%d", &guess);

    while (guess != num) {
        if (guess < num) {
            printf("Too low! Guess again:\n");
            scanf("%d", &guess);
        }
        else {
            printf("Too high! Guess again:\n");
            scanf("%d", &guess);
        }
        count++;
    }

    printf("Congratulations! You guessed the number in %d attempts!\n", count);

    return 0;
}