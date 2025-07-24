//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // to generate random numbers
    int guess, number_of_guesses = 1;
    int number = rand() % 100 + 1; // generates random number between 1 and 100
    
    printf("\nWelcome to the Number Guessing Game!");
    printf("\n**********************************");
    printf("\nGuess the number between 1 and 100: ");
    
    scanf("%d", &guess);
    
    while (guess != number)
    {
        if (guess > number)
        {
            printf("\nLower!");
        }
        else
        {
            printf("\nHigher!");
        }
        
        printf("\nGuess again: ");
        scanf("%d", &guess);
        number_of_guesses++; // incrementing number of guesses
    }
    
    printf("\nCongratulations! You got it in %d guesses.\n", number_of_guesses);
    
    return 0;
}