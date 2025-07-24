//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random generator

    printf("Welcome to the number guessing game!\n");
    printf("You have 10 attempts to guess a number between 1 and 100.\n");

    int secretNumber = rand() % 100 + 1; // generate random number
    int guess;
    int attemptsLeft = 10;

    while (attemptsLeft > 0) // loop until no attempts left
    {
        printf("\nGuess the secret number: ");
        scanf("%d", &guess);

        if (guess == secretNumber) // correct guess
        {
            printf("Congratulations! You guessed the secret number in %d attempts\n", 11 - attemptsLeft);
            return 0;
        }
        else if (guess < secretNumber) // guess too low
        {
            printf("Too low! ");
        }
        else // guess too high
        {
            printf("Too high! ");
        }
        
        attemptsLeft--;
        printf("You have %d attempts left.\n", attemptsLeft);
    }

    printf("\nGame over! You failed to guess the secret number.\nThe secret number was %d.\n", secretNumber);
    return 0;
}