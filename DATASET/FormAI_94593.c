//FormAI DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, attempts = 0;
    srand(time(0));
    num = rand() % 100 + 1; // generate a random number between 1 and 100

    printf("Welcome to the guessing game!\n");
    printf("I have a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > num) {
            printf("Too high! Try again.\n");
        } else if (guess < num) {
            printf("Too low! Try again.\n");
        }
    } while (guess != num);

    printf("Congratulations, you guessed the number in %d attempts!\n", attempts);

    return 0;
}