//FormAI DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("\n\tWelcome to the Guessing Game!");
    printf("\n\nGuess the number between 1 and 100\n");
    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        tries++;
        if (guess > num) {
            printf("Lower your guess!\n");
        } else if (guess < num) {
            printf("Increase your guess!\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != num);
    printf("Thanks for playing!\n");
    return 0;
}