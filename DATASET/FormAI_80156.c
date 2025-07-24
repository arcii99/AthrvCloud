//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_guesses = 0;
    int guess = 0;
    int secret_num;
    int guess_range;

    // Generate the random number
    srand(time(NULL));
    printf("Enter the range of numbers to guess from: ");
    scanf("%d", &guess_range);
    secret_num = rand() % guess_range + 1;

    // Loop until the player guesses correctly
    while (guess != secret_num) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess < secret_num) {
            printf("Too low. Guess again.\n");
        } else if (guess > secret_num) {
            printf("Too high. Guess again.\n");
        }
    }

    printf("Congratulations, you guessed the number %d in %d guesses!\n", secret_num, num_guesses);

    return 0;
}