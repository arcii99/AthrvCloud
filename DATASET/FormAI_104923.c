//FormAI DATASET v1.0 Category: Table Game ; Style: Linus Torvalds
/**
 * A C program that simulates a table game where players have to guess a number
 * that falls within a given range to win.
 * 
 * Written by [Your Name]
 * 
 * This code is licensed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rangeStart = 1;
    int rangeEnd = 100;
    
    int numberToGuess;
    srand(time(NULL));
    numberToGuess = rand() % (rangeEnd - rangeStart + 1) + rangeStart;
    
    printf("\nWelcome to the Guessing Game!\n\n");
    printf("You will have to guess a number between %d and %d to win.\n", rangeStart, rangeEnd);
    
    int numberOfTriesLeft = 10;
    int guess;
    while (numberOfTriesLeft > 0)
    {
        printf("\nEnter your guess (you have %d tries left): ", numberOfTriesLeft);
        scanf("%d", &guess);
        
        if (guess == numberToGuess)
        {
            printf("\nCongratulations! You have won!\n");
            break;
        }
        else if (guess < numberToGuess)
        {
            printf("\nYour guess is too low.\n");
        }
        else
        {
            printf("\nYour guess is too high.\n");
        }
        
        numberOfTriesLeft--;
    }
    
    if (numberOfTriesLeft == 0)
    {
        printf("\nSorry, you have run out of tries. Better luck next time!\n");
    }
    
    return 0;
}