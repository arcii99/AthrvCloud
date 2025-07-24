//FormAI DATASET v1.0 Category: Random ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUM 1
#define MAX_NUM 100

int main() {
    // Initialize random seed with current time
    srand(time(NULL));

    int target = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
    int guess, attempts = 0;

    printf("Welcome to the number guessing game!\n");
    printf("I am thinking of a number between %d and %d\n", MIN_NUM, MAX_NUM);

    do {
        printf("Please enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == target) {
            printf("Congratulations! You guessed the number in %d attempts\n", attempts);
        } else if (guess < target) {
            printf("Your guess is too low\n");
        } else {
            printf("Your guess is too high\n");
        }
    } while (guess != target);

    return 0;
}