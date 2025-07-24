//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomNumber, userNumber, attempts = 0;
    char playAgain;

    do
    {
        // Generating a random number between 1 and 100
        srand(time(NULL));
        randomNumber = rand() % 100 + 1;

        printf("Guess the number between 1 and 100\n");

        do
        {
            printf("Enter your guess: ");
            scanf("%d", &userNumber);

            if (userNumber < randomNumber)
            {
                printf("Too low. Try again.\n");
            }
            else if (userNumber > randomNumber)
            {
                printf("Too high. Try again.\n");
            }

            attempts++;

        } while (userNumber != randomNumber);

        printf("Congratulations! You guessed the number in %d attempts.\n", attempts);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

        attempts = 0;

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing!\n");

    return 0;
}