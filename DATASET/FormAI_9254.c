//FormAI DATASET v1.0 Category: Random ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize the random seed
    int max_num = 100; // the maximum number to generate
    int min_num = 1; // the minimum number to generate
    int range = max_num - min_num + 1; // the range of numbers to generate
    int num_guesses = 0; // keep track of the number of guesses
    int guess = 0; // the user's guess
    int random_num = rand() % range + min_num; // generate a random number between min_num and max_num

    printf("Welcome to the Random Number Guessing Game!\n");
    printf("I will generate a random number between %d and %d.\n", min_num, max_num);
    printf("Try to guess the number!\n");

    do {
        printf("Guess a number between %d and %d: ", min_num, max_num);
        scanf("%d", &guess);
        num_guesses++;

        if (guess < random_num) {
            printf("Too low! Guess again.\n");
        } else if (guess > random_num) {
            printf("Too high! Guess again.\n");
        }
    } while (guess != random_num);

    printf("Congratulations! You guessed the number in %d tries.\n", num_guesses);

    return 0;
}