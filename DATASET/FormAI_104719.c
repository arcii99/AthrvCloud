//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number, attempts = 0;
    srand(time(0));
    number = rand() % 100 + 1; //Generate random number between 1 and 100

    printf("\n\n********** Welcome to the Number Guessing Game **********\n\n");

    do {
        printf("Guess the number between 1 and 100 (inclusive): ");
        scanf("%d", &guess);
        attempts++;

        if(guess > number)
            printf("The number is lower!\n");
        else if(guess < number)
            printf("The number is higher!\n");
        else
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);

    } while(guess != number);

    printf("\n\n********** Thank you for playing! **********\n\n");

    return 0;
}