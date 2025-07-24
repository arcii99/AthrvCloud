//FormAI DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int guess, num, try = 10;
    num = rand() % 100;

    printf("==========================\n");
    printf("   Welcome to Guess Game\n");
    printf("==========================\n");

    while (try > 0) {
        printf("You have %d attempts left\n", try);
        printf("Guess a number between 0 and 99: ");
        scanf("%d", &guess);

        if (guess == num) {
            printf("\nCongratulations! You guessed it right.\n");
            break;
        } else if (guess < num) {
            printf("Too low! Guess higher.\n\n");
        } else if (guess > num) {
            printf("Too high! Guess lower.\n\n");
        }

        try--;
    }

    if (try == 0) {
        printf("\nSorry, you couldn't guess it right. The number was %d.\n", num);
    }

    printf("\nThank you for playing Guess Game!\n");

    return 0;
}