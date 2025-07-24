//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, tries = 0;
    srand(time(0)); // seed random number generator
    num = rand() % 100 + 1; // random number between 1 and 100
    printf("\nGuess the Number Game\n");
    printf("------------------------\n");
    printf("You have to guess a number between 1 and 100\n");
    printf("You only have 10 tries\n");
    do
    {
        printf("\nEnter guess number %d: ", tries + 1);
        scanf("%d", &guess);
        tries++;
        if (guess > num)
        {
            printf("Too high! Try again.\n");
        }
        else if (guess < num)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the number in %d tries.\n", tries);
            printf("Would you like to play again? (y/n): ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y')
            {
                num = rand() % 100 + 1;
                tries = 0;
            }
            else
            {
                break;
            }
        }
    } while (tries < 10);
    if (tries == 10)
    {
        printf("\nSorry, you ran out of tries. The number was %d.\n", num);
    }
    return 0;
}