//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Initializing random seed with time

    int i, j;
    int n = rand() % 4 + 1; // Generating a random number between 1 and 4

    printf("Guess the number between 1 and 4!\n");

    for (i = 0; i < 5; i++) {
        int guess;
        printf("Enter your guess : ");
        scanf("%d", &guess);

        if (guess == n) {
            printf("Congratulations! You have won the game in %d tries.\n", i + 1);
            break;
        } else {
            printf("Wrong guess. You have %d tries left.\n", 4 - i);
        }
    }

    if (i == 5) {
        printf("Sorry, you have lost the game. The correct number was %d.\n", n);
    }

    return 0;
}