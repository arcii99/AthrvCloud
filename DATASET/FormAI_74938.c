//FormAI DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Happy C Game!\n\n");

    // Generate a random number
    srand(time(NULL));
    int number = rand() % 10 + 1;
    int guess;

    printf("I'm thinking of a number between 1 and 10. Can you guess it?\n\n");

    // Loop until the user guesses correctly
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < number) {
            printf("Too low! Guess again.\n\n");
        }
        else if (guess > number) {
            printf("Too high! Guess again.\n\n");
        }
        else {
            printf("Congratulations! You guessed my number. You're awesome!\n\n");
        }
    } while (guess != number);

    printf("Thanks for playing the Happy C Game!\n\n");

    return 0;
}