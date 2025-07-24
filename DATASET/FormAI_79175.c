//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, count=0;

    srand(time(0)); //Seed for generating random numbers
    num = rand()%100 + 1; //Generating random number between 1 and 100

    printf("********Welcome to the Guessing Game!********\n");
    printf("\nInstructions: Guess the number between 1 and 100. You will have 7 attempts.\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        count++; //Counting the number of attempts

        if (guess == num) {
            printf("\nCongratulations! You guessed it right in %d attempt(s)!\n", count); //Printing the number of attempts
            break; //Exiting the loop if the user guesses correctly
        } else if (guess < num) {
            printf("That's too low. Guess again.\n");
        } else if (guess > num) {
            printf("That's too high. Guess again.\n");
        }

        if (count == 7) {
            printf("\nSorry, you ran out of attempts. The number was %d\n", num); //Printing the correct number if the user runs out of attempts
            break; //Exiting the loop if the user runs out of attempts
        }

    } while (guess != num && count < 7); //Looping until the user guesses correctly or runs out of attempts

    printf("\nThanks for playing the Guessing Game!\n");

    return 0;
}