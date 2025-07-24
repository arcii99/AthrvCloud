//FormAI DATASET v1.0 Category: Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // seeding random number generator

    printf("Welcome to the Guessing Game!\n\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have 10 tries to guess it.\n\n");

    int correct_number = rand() % 100 + 1;
    int guess, num_guesses = 0;

    do {
        num_guesses++;
        printf("Guess #%d: ", num_guesses);
        scanf("%d", &guess);

        if (guess < correct_number)
            printf("Too low! Try again.\n\n");
        else if (guess > correct_number)
            printf("Too high! Try again.\n\n");
        else
            printf("Congratulations! You guessed the correct number in %d tries.\n", num_guesses);
    } while (guess != correct_number && num_guesses < 10);

    if (num_guesses == 10)
        printf("Sorry, you ran out of tries. The correct number was %d.\n", correct_number);

    return 0;
}