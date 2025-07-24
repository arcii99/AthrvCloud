//FormAI DATASET v1.0 Category: Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator with the current time

    int guessingNumber = rand() % 100; // generate a random number between 0 and 99
    int guessedNumber;
    int attempts = 0;

    printf("\nBrave Warrior! Can you guess the hidden number? You have 10 attempts to succeed. Good luck!\n\n");

    while (attempts < 10)
    {
        printf("Enter your guess (0-99): ");
        scanf("%d", &guessedNumber);

        if (guessedNumber == guessingNumber)
        {
            printf("\nCongratulations! You have guessed the number in %d attempts!\n", attempts + 1);
            break;
        }
        else if (guessedNumber < guessingNumber)
        {
            printf("The secret number is higher... Try again!\n");
        }
        else
        {
            printf("The secret number is lower... Try again!\n");
        }

        attempts++;
    }

    if (attempts == 10)
    {
        printf("\nSorry! You have failed to guess the number. Better luck next time!\n");
    }

    return 0;
}