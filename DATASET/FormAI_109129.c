//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, tries = 0;
    srand(time(0)); 
    num = rand() % 100 + 1; 

    printf("\n\nWelcome to the Number-Guessing Game!");
    printf("\n\nI am thinking of a number between 1 and 100");
    printf("\nYou have 7 tries to guess it correctly!");

    do {
        printf("\n\nGuess #%d: ", tries+1);
        scanf("%d", &guess);

        if (guess > num) {
            printf("\nToo high! Try again.");
        }
        else if (guess < num) {
            printf("\nToo low! Try again.");
        }
        else {
            printf("\nCongratulations! You guessed it in %d tries!", tries+1);
            break;
        }
        tries++;
    } while (tries < 7);

    if (tries == 7) {
        printf("\n\nSorry, you were not able to guess the number.");
        printf("\nThe correct number was %d. Try again next time!", num);
    }

    return 0;
}