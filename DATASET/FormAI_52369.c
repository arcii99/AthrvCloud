//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the guessing game! Guess a number between 1 and 100.\n");

    // Setting up random number generation
    srand(time(NULL));
    int targetNumber = rand() % 100 + 1;
    int attempts = 0;

    while (1) {
        int guess;
        printf("Enter your guess (attempt %d): ", attempts+1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Your guess is out of range. Please enter a number between 1 and 100.\n");
        } else if (guess < targetNumber) {
            printf("Your guess is too low!\n");
            attempts++;
        } else if (guess > targetNumber) {
            printf("Your guess is too high!\n");
            attempts++;
        } else {
            printf("Congratulations! You've guessed the number in %d attempts.\n", attempts+1);
            break;
        }
    }

    return 0;
}