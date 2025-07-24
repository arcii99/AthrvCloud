//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess;
    int secretNumber;
    int attempts = 1;
    int maxAttempts = 10;
    srand(time(0));
    secretNumber = rand() % 100 + 1;

    printf("Welcome to the C Table Game! You have 10 attempts to guess the secret number between 1 and 100. Good luck!\n");

    while (attempts <= maxAttempts)
    {
        printf("Attempt %d: ", attempts);
        scanf("%d", &guess);

        if (guess == secretNumber)
        {
            printf("You guessed it! Congratulations, you win!\n");
            break;
        }
        else if (guess > secretNumber)
        {
            printf("Too high! Try again.\n");
        }
        else
        {
            printf("Too low! Try again.\n");
        }

        attempts++;
    }

    if (attempts > maxAttempts)
    {
        printf("Sorry, you are out of attempts. The secret number was %d.\n", secretNumber);
    }

    return 0;
}