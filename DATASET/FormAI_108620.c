//FormAI DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, tries = 0;
    srand(time(0)); //seeds the random number generator
    num = rand() % 100 + 1; //generates a random number between 1 and 100

    printf("\nWelcome to the Number Guessing Game!\n");
    printf("You have to guess the number between 1 and 100.\n");

    do
    {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);

        if (guess < num)
        {
            printf("Your guess is too low. Try again.\n");
            ++tries;
        }else if(guess > num) 
        {
            printf("Your guess is too high. Try again.\n");
            ++tries;
        }else
        {
            printf("\n*****Congratulations! You guessed the number %d in %d attempts.*****\n", num, ++tries);
        }

    } while (guess != num);

    return 0;
}