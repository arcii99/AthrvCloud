//FormAI DATASET v1.0 Category: Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5

int main()
{
    int guess, num, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    
    printf("\nWelcome to the Number Guessing Game!\n");
    printf("You have %d attempts to guess the number between 1 and 100.\n", MAX_TRIES);
    
    do
    {
        printf("\nGuess #%d: ", tries+1);
        scanf("%d", &guess);
        tries++;
        
        if(guess < num)
        {
            printf("Too low! Try again.\n");
        }
        else if(guess > num)
        {
            printf("Too high! Try again.\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the number in %d attempts.\n", tries);
            break;
        }
        
    } while(tries < MAX_TRIES);
    
    if(tries == MAX_TRIES)
    {
        printf("\nGame Over! You could not guess the number in %d attempts.\n", MAX_TRIES);
        printf("The number was %d.\n", num);
    }
    
    return 0;
}