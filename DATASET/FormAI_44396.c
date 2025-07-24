//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the guessing game!\n");
    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n");

    srand(time(NULL)); // Seed the random number generator based on current time

    int num = rand() % 100 + 1; // Generate random number between 1 and 100
    int guess = 0;
    int num_guesses = 0;

    while (guess != num) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        int diff = abs(guess - num);

        if (diff == 0) {
            printf("Congratulations, you guessed the number correctly in %d guesses!\n", num_guesses);
        } else if (diff <= 5) {
            printf("You are very close. Keep guessing!\n");
        } else if (diff <= 10) {
            printf("You are getting warm!\n");
        } else if (diff <= 25) {
            printf("You are on the right track!\n");
        } else {
            printf("You are very far away. Try again!\n");
        }
    }

    return 0;
}