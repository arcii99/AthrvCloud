//FormAI DATASET v1.0 Category: Random ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("Let's play a guessing game!\n");

    srand(time(0)); // initialize random number generator

    int correct_number = rand() % 100 + 1; // generate a random number between 1 and 100

    int guess, num_guesses = 0;

    do {

        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        num_guesses++;

        if (guess > correct_number) {
            printf("Too high, guess lower.\n");
        } else if (guess < correct_number) {
            printf("Too low, guess higher.\n");
        } else {
            printf("Congratulations, you guessed the correct number in %d guesses!\n", num_guesses);
        }

    } while (guess != correct_number);

    return 0;
}