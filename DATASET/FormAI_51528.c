//FormAI DATASET v1.0 Category: Table Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number, guess, nguesses = 1;
    srand(time(0)); // seeding random number
    number = rand() % 100 + 1; // generating random number between 1 and 100

    printf("\n\t\tWelcome to Guess the Number Game\n");
    printf("\n\t\tYou have 5 chances to guess the correct number between 1-100\n");

    do
    {
        printf("Guess %d: ", nguesses);
        scanf("%d", &guess);

        if (guess > number)
        {
            printf("Too high! Try a smaller number.\n");
        }
        else if (guess < number)
        {
            printf("Too low! Try a larger number.\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the number in %d attempts.\n", nguesses);
            break;
        }

        nguesses++; // incrementing the number of guesses
    }
    while (nguesses <= 5);

    if (nguesses > 5)
    {
        printf("\nSorry! You have exceeded the number of guesses.\nThe correct number was %d.\n", number);
    }

    return 0;
}