//FormAI DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, numguesses = 0;
    time_t t;
    srand((unsigned) time(&t));
    num = rand() % 100 + 1;
    printf("\nWelcome to the Guessing Game!\n");
    printf("Guess a number between 1 and 100\n");
    
    do {
        scanf("%d", &guess);
        numguesses++;
        
        if(guess > num) 
        {
            printf("Too high! Guess again: ");
        }
        else if(guess < num)
        {
            printf("Too low! Guess again: ");
        }
        else 
        {
            printf("Congratulations! You guessed the number in %d guesses.\n", numguesses);
        }
    } while(guess != num);

    return 0;
}