//FormAI DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>

int main() {
    int paranoid_number = 5;
    int secret_number = 10;
    int paranoid_guess;
    int tries = 0;

    printf("I'm thinking of a secret number. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &paranoid_guess);

        if (paranoid_guess > secret_number) {
            printf("No, that's too high. Try again.\n");
        } else if (paranoid_guess < secret_number) {
            printf("No, that's too low. Try again.\n");
        }

        tries++;

        if (tries > paranoid_number) {
            printf("You've tried too many times. I can't trust you anymore.\n");
            return 0;
        }

    } while (paranoid_guess != secret_number);

    printf("Well done, you guessed my secret number in %d tries!\n", tries);

    return 0;
}