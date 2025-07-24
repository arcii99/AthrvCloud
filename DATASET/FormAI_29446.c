//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int number, guess, nguesses = 1;
    srand(time(0)); // Generates random seed using system time

    number = rand()%100 + 1; // Generates random number between 1 to 100

    // Game rules for guessing the number
    printf("Welcome to the Number Guessing Game!");
    printf("\nThe computer has chosen a number between 1 to 100");
    printf("\nYou have 5 chances to guess the number correctly");

    // Loop for taking guesses from the user
    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        if(guess > number)
        {
            printf("Lower number please!\n");
        }
        else if(guess < number)
        {
            printf("Higher number please!\n");
        }
        else
        {
            printf("\nYou guessed it in %d attempts!", nguesses);
            break;
        }
        nguesses++;

    } while(nguesses <= 5);

    if(nguesses > 5) // Player ran out of attempts
    {
        printf("\nSorry, the number was %d.", number);
    }
    return 0;
}