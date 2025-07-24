//FormAI DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number_of_guesses = 0;
    srand(time(0));
    int random_number = rand() % 100 + 1; // generating a random number between 1 and 100

    printf("Welcome to the Guessing Game!\n");
    printf("I have selected a number between 1 and 100, can you guess it?\n");

    do
    {
        printf("Guess #%d: ", number_of_guesses + 1);
        scanf("%d", &guess);
        number_of_guesses++; // incrementing the number of guesses taken by the player

        if (guess > random_number)
        {
            printf("Your guess is too high, try again.\n");
        }
        else if (guess < random_number)
        {
            printf("Your guess is too low, try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the correct number in %d tries.\n", number_of_guesses);
        }
    } while (guess != random_number);

    return 0;
}