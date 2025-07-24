//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    //randomizing the secret number
    int secret_number = rand() % 100 + 1;
    
    //setting the number of attempts
    int attempts = 5;
    int guess;
    
    printf("Welcome to Guess the Number game! You have 5 attempts to guess the number between 1 and 100.\n");
    
    //main game loop
    while(attempts > 0)
    {
        printf("Attempts left: %d\n", attempts);
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        if(guess == secret_number)
        {
            printf("Congratulations! You guessed the secret number %d in %d attempts!\n", secret_number, 5 - attempts + 1);
            break;
        }
        else if(guess < secret_number)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Too high! Try again.\n");
        }
        
        attempts--;
    }
    
    if(attempts == 0)
    {
        printf("Game over! You failed to guess the secret number %d. Better luck next time!\n", secret_number);
    }
    
    return 0;
}