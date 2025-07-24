//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initializing variables
    int number, guess, attempts = 1;
    srand(time(0));
    number = rand() % 100 + 1; // Generating random number between 1 to 100

    // Welcome message
    printf("\n\nWelcome to the Cryptic Guessing Game!\n");
    printf("The game in which you try to guess a number between 1 to 100.\n");
    printf("But beware, you only have 10 attempts!\n");

    // Loop for guessing attempts
    do
    {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        // Comparing user guess with generated number
        if (guess > number)
        {
            printf("The correct number is smaller\n");
        }
        else if (guess < number)
        {
            printf("The correct number is bigger\n");
        }
        else
        {
            printf("\nYou won in %d attempts!\n", attempts);
        }
        attempts++;     // Incrementing attempt counter
    } while (guess != number && attempts <= 10); // Loop till correct guess or 10 attempts

    // Displaying losing message
    if (attempts > 10)
    {
        printf("\nYou have no more attempts left. You lose!\n");
        printf("The correct number was %d. Better luck next time!\n", number);
    }

    return 0;
}