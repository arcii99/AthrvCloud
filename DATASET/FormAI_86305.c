//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int num_guesses = 0;
    int max_guesses = 10;
    int guess;
    int secret_num;
    int range_min = 1;
    int range_max = 50;

    srand(time(0));
    secret_num = (rand() % (range_max - range_min + 1)) + range_min;

    printf("*** Welcome to Guess the Number Game ***\n");
    printf("You have %d guesses to guess the number between %d and %d\n", max_guesses, range_min, range_max);

    while (num_guesses < max_guesses) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < range_min || guess > range_max) {
            printf("Your guess is not between %d and %d, try again.\n", range_min, range_max);
            continue;
        }

        num_guesses++;

        if (guess < secret_num) {
            printf("Too low!\n");
        } else if (guess > secret_num) {
            printf("Too high!\n");
        } else {
            printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses);
            return 0;
        }
    }

    printf("Sorry, you did not guess the number. It was %d.\n", secret_num);
    return 0;
}