//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int main() {
    int target_number = 0;
    int guess = 0;
    int num_guesses = 0;

    srand(time(NULL));
    target_number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

    printf("Welcome to the Guessing Game! You have 10 guesses to find the target number between %d and %d. Good luck!\n", MIN_NUMBER, MAX_NUMBER);

    while (num_guesses < MAX_GUESSES) {
        printf("Guess #%d: ", num_guesses + 1);
        scanf("%d", &guess);

        if (guess < target_number) {
            printf("The target number is higher.\n");
        } else if (guess > target_number) {
            printf("The target number is lower.\n");
        } else {
            printf("Congratulations! You guessed the target number in %d tries.\n", num_guesses + 1);
            return 0;
        }

        num_guesses++;
    }

    printf("Sorry, you ran out of guesses! The target number was %d.\n", target_number);
    return 0;
}