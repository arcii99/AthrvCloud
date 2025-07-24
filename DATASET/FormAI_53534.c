//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Get ready to play the most exciting game of your life!\n\n");
    printf("Here's how to play:\n");
    printf("You have to guess a number between 1 and 100 in three attempts or less.\n");
    printf("Let's see if you can do it!\n\n");

    int secretNumber, guess, tries = 0;
    srand(time(NULL));
    secretNumber = rand() % 100 + 1;

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > secretNumber) {
            printf("Too high. Try again.\n\n");
        } else if (guess < secretNumber) {
            printf("Too low. Try again.\n\n");
        } else {
            printf("\nCongratulations! You guessed the number %d in %d tries!\n", secretNumber, tries);
            break;
        }
    } while (tries < 3);

    if (tries == 3) {
        printf("\nSorry, you didn't guess the number. Better luck next time.\n");
    }

    return 0;
}