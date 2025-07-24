//FormAI DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess;
    int secret_number;
    int attempts = 0;

    srand(time(NULL));
    secret_number = rand() % 100 + 1;

    printf("Welcome to the guessing game! Guess the number between 1 and 100.\n");

    while (guess != secret_number) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess == secret_number) {
            printf("Congratulations, you guessed the number in %d attempts!\n", attempts);
        } else if (guess < secret_number) {
            printf("Too low, try again.\n");
            attempts++;
        } else if (guess > secret_number) {
            printf("Too high, try again.\n");
            attempts++;
        }
    }
    return 0;
}