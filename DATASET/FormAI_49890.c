//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number, tries = 0;
    srand(time(0));
    number = rand() % 50 + 1; //generating random number between 1 and 50
    
    printf("\nWelcome to the number guessing game!\n");
    printf("I have chosen a number between 1 and 50.\n");
    printf("You have to guess the number in maximum 10 tries.\n");
    
    do
    {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        
        if(guess < number)
        {
            printf("Your guess is too low. Try again.\n");
        }
        else if(guess > number)
        {
            printf("Your guess is too high. Try again.\n");
        }
        tries++;
    } while(guess != number && tries < 10);
    
    if(guess == number)
    {
        printf("\nCongratulations! You guessed it right in %d tries.", tries);
    }
    else
    {
        printf("\nOops! You ran out of tries. The number was %d.", number);
    }
    
    return 0;
}