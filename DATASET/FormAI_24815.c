//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0, guess, num, num_range;
    srand(time(0));
    
    printf("---Welcome to Guessing Game---\n");

    // Selecting a range for random number
    printf("Select a range for the number (preferably below 100): ");
    scanf("%d", &num_range);
    // Generating a random number from 1 to num_range
    num = rand() % num_range + 1;

    // Prompting the user to guess the number
    printf("Guess the number between 1 and %d: ", num_range);
    scanf("%d", &guess);

    // Loop to check if the guessed number is correct or not
    while (guess != num) {
        if (guess > num) {
            printf("Your guess is too high. Guess again: ");
        } else {
            printf("Your guess is too low. Guess again: ");
        }
        scanf("%d", &guess);
    }

    // If guessed number is correct
    printf("Congratulations, you guessed the number!\n");
    // Calculating score based on range selected and number of attempts
    score = (num_range - 1) * 10 + (num_range - guess);
    printf("Your score is: %d\n", score);

    return 0;
}