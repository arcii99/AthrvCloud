//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, num, count = 0;
    srand(time(0));
    num = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("Guess a number between 1 and 100\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;
        if (guess > num) {
            printf("Too high!\n");
        } else if (guess < num) {
            printf("Too low!\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts!\n", count);
            break;
        }
    } while (guess != num);

    return 0;
}