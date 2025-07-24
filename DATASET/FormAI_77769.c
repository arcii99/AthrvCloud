//FormAI DATASET v1.0 Category: Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // to generate random numbers
    
    int answer, guess, tries = 0;
    answer = rand() % 101; // generate a random number between 0 and 100
    printf("Welcome to the Number Guessing Game!\n");
    
    do {
        printf("Enter your guess (0-100): ");
        scanf("%d", &guess);
        tries++;
        
        if (guess > answer)
            printf("Too high! Try again.\n");
        else if (guess < answer)
            printf("Too low! Try again.\n");
        else
            printf("Congratulations! You guessed it in %d tries!\n", tries);
            
    } while (guess != answer);
    
    return 0;
}