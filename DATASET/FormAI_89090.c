//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* This program generates a random number in a given range and allows the user to guess it.
     * It measures the performance of the user's guess and gives feedback based on that.
     * This is a performance-critical component as it involves a lot of calls to the random number generator.
     * However, it is written using efficient algorithms and modern best practices for top-notch performance. */

    srand(time(NULL)); // Seed the random number generator with current time
    const int MIN = 1; // Minimum number in the range
    const int MAX = 100; // Maximum number in the range
    int secret_number = rand() % MAX + MIN; // Generate a secret number within the range

    int guess; // User's guess
    int attempts = 0; // Number of attempts made by the user

    printf("\nWelcome to the guessing game!\n");
    printf("Guess a number between %d and %d: ", MIN, MAX);

    clock_t start_time = clock(); // Measure the start time

    while (1) {
        scanf("%d", &guess); // Read the user's input

        attempts++; // Increase the number of attempts made by the user

        if (guess < MIN || guess > MAX) {
            printf("Invalid input. Guess a number between %d and %d: ", MIN, MAX);
        } else if (guess < secret_number) {
            printf("Too low. Guess again: ");
        } else if (guess > secret_number) {
            printf("Too high. Guess again: ");
        } else {
            clock_t end_time = clock(); // Measure the end time
            double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC; // Calculate the time taken
            printf("Congratulations! You guessed it in %d attempts and %.2f seconds.\n", attempts, time_taken);
            break;
        }
    }

    return 0;
}