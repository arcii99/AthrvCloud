//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1; // generate a random number between 1 and 100

    printf("\nWelcome to the Number Guessing Game!\n\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("Try to guess the number in less than 10 tries!\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        // check if the guess is higher, lower or equal to the number
        if (guess > num)
            printf("Too high! Try again.\n\n");
        else if (guess < num)
            printf("Too low! Try again.\n\n");
        else
            printf("Congratulations! You guessed the number in %d tries.\n\n", tries);

    } while (guess != num && tries < 10);

    if (tries == 10)
        printf("Sorry, you exceeded the maximum number of tries. Game over!\n");

    return 0;
}