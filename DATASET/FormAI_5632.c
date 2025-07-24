//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ans, guess, tries = 0;
    srand(time(0)); //seed random number generator

    ans = rand() % 100 + 1; //generate random number between 1 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("You have 10 tries to guess the correct number.\n");

    do {
        printf("\nEnter guess #%d: ", tries+1);
        scanf("%d", &guess);

        if (guess < ans) {
            printf("Your guess is too low. Try again.\n");
        } else if (guess > ans) {
            printf("Your guess is too high. Try again.\n");
        }

        tries++;
    } while (guess != ans && tries < 10);

    if (guess == ans) {
        printf("\nCongratulations, you guessed the correct number!\n");
        printf("It took you %d tries.\n", tries);
    } else {
        printf("\nSorry, you have used all your tries.\n");
        printf("The correct number was %d.\n", ans);
    }

    return 0;
}