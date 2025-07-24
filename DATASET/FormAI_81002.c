//FormAI DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5
#define MAX_NUM 100
#define MIN_NUM 1

int main() {
    int secret_number, guess, num_guesses = 0;
    srand(time(NULL));
    secret_number = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;

    printf("Welcome to Paranoid Guessing Game!\n");
    printf("You have only %d tries to guess the number.\n", MAX_GUESSES);

    while(num_guesses < MAX_GUESSES) {
        printf("Guess a number between %d and %d: ", MIN_NUM, MAX_NUM);
        scanf("%d", &guess);
        num_guesses++;

        if(guess == secret_number) {
            printf("Congratulations! You have guessed the secret number in %d tries.\n", num_guesses);
            exit(0);
        } else {
            printf("Wrong guess. ");
            if(num_guesses == MAX_GUESSES) {
                printf("You have reached the maximum number of guesses.\n");
            } else {
                printf("You have %d more tries left.\n", MAX_GUESSES - num_guesses);
            }
        }
    }

    printf("The secret number was %d.\nBetter luck next time!\n", secret_number);
    return 0;
}