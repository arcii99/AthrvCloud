//FormAI DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int randomNumber = rand() % 100 + 1;
    int guess, numberOfGuesses = 0;
    printf("Welcome to the Guessing Game!\n");
    printf("Try to guess a random number between 1 and 100.\n");
    do
    {
        numberOfGuesses++;
        printf("Guess #%d: ", numberOfGuesses);
        scanf("%d", &guess);
        if (guess > randomNumber)
        {
            printf("Too high! Guess again.\n");
        }
        else if (guess < randomNumber)
        {
            printf("Too low! Guess again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d guesses.\n", numberOfGuesses);
        }
    }
    while (guess != randomNumber);
    return 0;
}