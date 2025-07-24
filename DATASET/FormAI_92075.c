//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random_number, guess;
    int num_attempts = 0;

    srand(time(NULL)); // Seed the random number generator

    random_number = rand() % 100 + 1; // Random number between 1 and 100

    printf("I am thinking of a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_attempts++;

        if (guess > random_number) {
            printf("Your guess is too high! Try again.\n");
        } else if (guess < random_number) {
            printf("Your guess is too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", num_attempts);
        }
    } while (guess != random_number);

    return 0;
}