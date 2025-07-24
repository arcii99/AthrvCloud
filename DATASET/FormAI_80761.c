//FormAI DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_num, guess, num_guesses = 0;
    srand(time(NULL)); // initialize random seed
    secret_num = rand() % 101; // generate random number between 0 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("I have a number between 0 and 100, can you guess it?\n");

    while (num_guesses < 10) { // limit to 10 guesses
        printf("Guess #%d: ", num_guesses+1);
        scanf("%d", &guess);

        if (guess > secret_num) {
            printf("Too high!\n");
        } else if (guess < secret_num) {
            printf("Too low!\n");
        } else { // guess is correct!
            printf("Congratulations! You guessed the number in %d tries.\n", num_guesses+1);
            return 0;
        }
        num_guesses++;
    }

    printf("Sorry, you did not guess the number. It was %d.\n", secret_num);
    return 0;
}