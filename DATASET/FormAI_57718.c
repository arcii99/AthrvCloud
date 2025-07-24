//FormAI DATASET v1.0 Category: Random ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 1;
    srand(time(0)); // Seed for randomization
    num = rand() % 100 + 1; // Random number between 1 and 100
    printf("Guess the number between 1 and 100\n");
    do {
        printf("Enter guess #%d: ", tries);
        scanf("%d", &guess);
        if (guess > num) {
            printf("Too high!\n");
        } else if (guess < num) {
            printf("Too low!\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries\n", tries);
        }
        tries++;
    } while (guess != num);
    return 0;
}