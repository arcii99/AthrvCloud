//FormAI DATASET v1.0 Category: Table Game ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, guess, attempts = 0;
    srand(time(NULL));
    randomNumber = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game! You have 10 attempts to guess a number between 1 and 100.\n");

    while (attempts < 10) {
        printf("Guess #%d: ", attempts + 1);
        scanf("%d", &guess);
        if (guess < 1 || guess > 100) {
            printf("Invalid guess. Please enter a number between 1 and 100.\n");
            continue;
        }
        if (guess == randomNumber) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts + 1);
            break;
        } else if (guess < randomNumber) {
            printf("The number is higher than your guess. Try again.\n");
        } else {
            printf("The number is lower than your guess. Try again.\n");
        }
        attempts++;
    }

    if (attempts == 10) {
        printf("Game over. You have run out of attempts. The number was %d.\n", randomNumber);
    }

    return 0;
}