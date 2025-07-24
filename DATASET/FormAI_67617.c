//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess_number, random_number;
    int attempts = 0;

    srand(time(0));
    random_number = rand() % 100 + 1;

    printf("\nWelcome to the Guessing Game!\n");
    printf("Try to guess the number between 1-100 in less than 10 attempts..\n");

    do
    {
        printf("\nEnter your guess: ");
        scanf("%d", &guess_number);
        attempts++;

        if (guess_number > random_number)
        {
            printf("\nSorry, your guess is too high. Try a lower number.");
        }
        else if (guess_number < random_number)
        {
            printf("\nSorry, your guess is too low. Try a higher number.");
        }
        else
        {
            printf("\nCongratulations! You have guessed the number in %d attempts.", attempts);
        }

    } while (guess_number != random_number && attempts < 10);

    if (attempts >= 10)
    {
        printf("\nSorry, you have used all your attempts. The number was %d. Try again later.\n", random_number);
    }

    return 0;
}