//FormAI DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y, guess, count = 0, flag = 0;
    srand(time(NULL));
    x = rand() % 101;

    printf("Welcome to the Guessing Game!\n");
    printf("-----------------------------\n");
    printf("I have a number between 0 and 100, can you guess what it is?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;

        if (guess < 0 || guess > 100) {
            printf("Invalid input. Please enter a number between 0 and 100.\n");
            continue;
        }

        if (guess < x) {
            printf("Too low. Guess again.\n");
        } else if (guess > x) {
            printf("Too high. Guess again.\n");
        } else {
            printf("Congratulations! You guessed the correct number in %d tries.\n", count);
            flag = 1;
        }
    } while (flag == 0);

    printf("Thank you for playing the Guessing Game!\n");

    return 0;
}