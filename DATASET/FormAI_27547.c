//FormAI DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    printf("Happy Valentine's Day!\n");
    printf("Welcome to our Romantic Game!\n\n");

    int num_guesses = 0;
    int guess;
    int random_number = rand() % 100;

    printf("To win my heart, you must guess the number I am thinking of, between 0 and 100.\n");

    while (num_guesses < 10)
    {
        printf("Guess a number: ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess == random_number)
        {
            printf("You win my heart! Congratulations!");
            return 0;
        }
        else if (guess < random_number)
        {
            printf("You are too low. ");
        }
        else
        {
            printf("You are too high. ");
        }

        printf("You have %d guesses left.\n", 10 - num_guesses);
    }

    printf("Sorry, you have run out of guesses. My heart remains unclaimed.");
    return 0;
}