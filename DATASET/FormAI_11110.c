//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // initialize random seed using current time
    int number = rand() % 100 + 1;  // generate random number between 1 and 100
    int guess, count = 0;
    printf("Guess a number between 1 and 100\n");
    do {
        count++;
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if (guess < number) {
            printf("Too low, try again\n");
        } else if (guess > number) {
            printf("Too high, try again\n");
        } else {
            printf("Congratulations, you guessed the number in %d tries!\n", count);
        }
    } while (guess != number);
    return 0;
}