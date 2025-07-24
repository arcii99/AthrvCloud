//FormAI DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random number generator

    int guessCount = 0; //initialize guess count to 0
    int randomNumber = rand() % 100 + 1; //generate random number between 1 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("Guess a number between 1 and 100.\n");

    int guess;

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guessCount++; //increment guess count

        if (guess > randomNumber) {
            printf("Too high! Guess again.\n");
        }
        else if (guess < randomNumber) {
            printf("Too low! Guess again.\n");
        }
        else {
            printf("Congratulations! You guessed the number in %d attempts.\n", guessCount);
        }
    } while (guess != randomNumber);

    return 0;
}