//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, count = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("Guess the number between 1-100.\n");
    
    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;
        
        // If guess is less than the number
        if(guess < num)
        {
            printf("You guessed too low. Try again.\n");
        }
        
        // If guess is more than the number
        else if(guess > num)
        {
            printf("You guessed too high. Try again.\n");
        }
        
        // If guess is correct
        else
        {
            printf("You guessed it in %d attempts!\n", count);
        }
        
    } while(guess != num);
    
    return 0;
}