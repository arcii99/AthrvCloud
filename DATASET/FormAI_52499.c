//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secret_num, guess;
    int max_attempts = 5;
    int num_attempts = 0;

    // generate secret number between 1-50
    srand(time(NULL)); // set seed for random number generator
    secret_num = rand() % 50 + 1;

    // loop until max attempts are reached or user guesses correctly
    while (num_attempts < max_attempts) {
        printf("Guess the secret number (between 1-50): ");
        scanf("%d", &guess);

        if (guess == secret_num) {
            printf("Congratulations, you guessed the secret number!\n");
            break;
        } else {
            num_attempts++;
            printf("Incorrect guess. You have %d attempts left.\n", max_attempts - num_attempts);
        }
    }

    if (num_attempts >= max_attempts) {
        printf("You did not guess the secret number. The secret number was %d.\n", secret_num);
    }

    return 0;
}