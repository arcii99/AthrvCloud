//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, secretNumber, numOfGuesses = 0;
    srand(time(0));
    secretNumber = rand() % 100 + 1; 

    printf("\nWelcome to the Guessing Game!\n\n");
    printf("A secret number has been generated between 1 and 100.\n");
    printf("You have 10 guesses to find the secret number.\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numOfGuesses++;

        if (guess < secretNumber)
            printf("Too low! Try again.\n\n");
        else if (guess > secretNumber)
            printf("Too high! Try again.\n\n");
        else
            printf("\nCongratulations! You found the secret number in %d guesses!\n\n", numOfGuesses);

    } while (guess != secretNumber && numOfGuesses < 10);

    if(numOfGuesses == 10)
        printf("\nSorry, you have reached the maximum number of tries. The secret number was %d.\n\n", secretNumber);

    return 0;
}