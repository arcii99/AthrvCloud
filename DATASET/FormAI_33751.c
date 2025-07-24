//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int magicNumber = 42;
    int userGuess = 0;
    int attemptCount = 0;
    printf("Welcome to the Magic Number guessing game!\n");
    printf("You have three attempts to guess the magic number between 1 and 100.\n");

    while(attemptCount < 3)
    {
        printf("Guess #%d: ", attemptCount+1);
        scanf("%d", &userGuess);
        if(userGuess == magicNumber)
        {
            printf("You have guessed the magic number! Congratulations :)\n");
            return EXIT_SUCCESS;
        }
        else if(userGuess < magicNumber)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Too high! Try again.\n");
        }
        attemptCount++;
    }
    printf("Sorry, you have run out of attempts. The magic number was %d. Better luck next time!\n", magicNumber);

    return EXIT_SUCCESS;
}