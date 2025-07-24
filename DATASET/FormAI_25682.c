//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number, guess, attempts = 0;
    srand(time(0)); // random seed initialization
    number = rand() % 100 + 1; // generating a random number between 1 and 100
    printf("\n\nWelcome to the Guessing Game!\n\n");
    printf("I have a number between 1 and 100, guess it.\n\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++; // increasing the attempts count
        if (guess > number)
        {
            printf("Your guess is higher than the number, try again.\n\n");
        }
        else if (guess < number)
        {
            printf("Your guess is lower than the number, try again.\n\n");
        }
        else
        {
            printf("\nCongratulations, you guessed the number in %d attempts.\n\n", attempts);
        }
    } while (guess != number);
    return 0;
}