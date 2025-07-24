//FormAI DATASET v1.0 Category: Educational ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int secret = rand() % 100;
    int guess;
    int count = 0;

    printf("Welcome to the guessing game!\nI'm thinking of a number between 1-100, can you guess what it is?\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess > secret) {
            printf("Too high! Try again.\n");
        } else if (guess < secret) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You got it right in %d tries.\n", count);
            break;
        }

        if (count == 4) {
            printf("I'm sorry, you've reached the maximum number of tries!\n");
            break;
        }

        count++;
    }

    printf("The secret number was %d\n", secret);

    return 0;
}