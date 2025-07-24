//FormAI DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secretNumber, guess;
    int attempts = 0;
    srand(time(0));  //seed the random number generator
    secretNumber = rand() % 100 + 1;  //generate random number between 1 and 100

    printf("\n\nWelcome to Guess the Number!\n\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        ++attempts;  //increment attempts

        if (guess > secretNumber) {
            printf("Too high! Guess again.\n\n");
        }
        else if (guess < secretNumber) {
            printf("Too low! Guess again.\n\n");
        }
        else {
            printf("\nCongratulations, you guessed the number in %d attempts!\n\n", attempts);
        }

    } while (guess != secretNumber);

    return 0;
}