//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("\n\tWelcome to the Number Guessing Game!\n");
    printf("\n\tInstructions: You have 10 tries to guess the number between 1 and 100.\n\tIf you guess within 10 tries, you win!\n");
    do {
        printf("\n\tEnter your guess: ");
        scanf("%d", &guess);
        tries++;
        if (guess > num) {
            printf("\tToo high! Try again.\n");
        } else if (guess < num) {
            printf("\tToo low! Try again.\n");
        } else {
            printf("\n\tYou win! You guessed the number in %d tries!", tries);
            break;
        }
    } while (tries < 10);
    if (tries == 10) {
        printf("\n\tSorry, you lose! The number was %d.\n", num);
    }
    return 0;
}