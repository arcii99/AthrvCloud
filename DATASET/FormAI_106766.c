//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Generate random number
    srand(time(NULL));
    int number = rand() % 100 + 1;

    // Display welcome message
    printf("Welcome to the Cryptic Game!\n");
    printf("I have randomly generated a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    int guess, tries = 0;

    // Start guessing loop
    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > number)
        {
            printf("Your guess is too high.\n");
        }
        else if (guess < number)
        {
            printf("Your guess is too low.\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the number in %d tries.", tries);
        }

    } while (guess != number);

    return 0;
}