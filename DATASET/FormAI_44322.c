//FormAI DATASET v1.0 Category: Table Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, attempt = 1;

    srand(time(0));
    num = rand() % 100 + 1; // generates random number between 1 to 100

    printf("\nGuess the number between 1 to 100\n");

    // loop until the number is guessed correctly or the number of attempts is less than or equal to 10
    do
    {
        printf("Attempt %d: Enter your guess: ", attempt);
        scanf("%d", &guess);

        if (guess > num)
        {
            printf("\nYour guess is too high\n");
        }
        else if (guess < num)
        {
            printf("\nYour guess is too low\n");
        }
        attempt++;

    } while (guess != num && attempt <= 10);

    // displays the result
    if (guess == num)
    {
        printf("\nCongratulations, you guessed the number %d correctly in %d attempt(s)!\n", num, attempt-1);
    }
    else
    {
        printf("\nSorry, you couldn't guess the number %d. The correct number was %d.\n", guess, num);
    }

    return 0;
}