//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5
#define MAX_NUMBER 100

int main(void) {
    int answer, guess, num_guesses = 0;
    srand(time(NULL));
    answer = rand() % MAX_NUMBER + 1; // generate a random number from 1 to 100
    printf("I'm thinking of a number between 1 and 100. You have %d guesses to get it right.\n", MAX_GUESSES);

    while (num_guesses < MAX_GUESSES) {
        printf("Guess %d: ", num_guesses + 1);
        scanf("%d", &guess);
        if (guess == answer) {
            printf("Congratulations! You guessed the number in %d guess(es).\n", num_guesses + 1);
            return 0;
        } else if (guess < answer) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Too high! Guess again.\n");
        }
        num_guesses++;
    }
    printf("Sorry, you didn't guess the number. It was %d.\n", answer);
    return 0;
}