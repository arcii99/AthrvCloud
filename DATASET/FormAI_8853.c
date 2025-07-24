//FormAI DATASET v1.0 Category: Random ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int count = 0;
    printf("Let's play a game of chance!\n");
    while (count < 3) { // Three rounds of guessing
        int secret_number = rand() % 10 + 1; // Generate a random number between 1 and 10
        int guess;
        int tries = 0;
        printf("Guess a number between 1 and 10:\n");
        while (tries < 3) { // Three chances to guess correctly
            scanf("%d", &guess);
            if (guess == secret_number) {
                printf("Congrats, you guessed correctly!\n");
                break;
            }
            else {
                printf("Sorry, that's not it. Guess again:\n");
                tries++;
            }
        }
        if (tries == 3) { // Player ran out of guesses
            printf("Sorry, you didn't guess the number. The secret number was %d.\n", secret_number);
        }
        count++;
        printf("Round %d is over!\n", count);
    }
    printf("Thanks for playing!\n");
    return 0;
}