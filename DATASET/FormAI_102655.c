//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int limit, guess, tries = 0;
    srand(time(0));
    limit = rand() % 100;

    printf("==================\n");
    printf("Welcome to Guessing Game\n");
    printf("==================\n");

    while (tries < 5) {
        printf("Guess the number between 0 and 100: ");
        scanf("%d", &guess);

        if (guess < limit) {
            tries++;
            printf("Try again! The number is higher than %d\n", guess);
            printf("Number of Tries Left: %d\n\n", 5 - tries);
        } else if (guess > limit) {
            tries++;
            printf("Try again! The number is lower than %d\n", guess);
            printf("Number of Tries Left: %d\n\n", 5 - tries);
        } else {
            printf("\n\nYou won!\n");
            printf("The number was: %d\n", limit);
            printf("You took %d tries.\n", tries+1);
            return 0;
        }
    }
    printf("\n\nYou lost!\n");
    printf("The number was: %d\n", limit);
    printf("Better luck next time.\n");
    return 0;
}