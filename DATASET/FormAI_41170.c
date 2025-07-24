//FormAI DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number, count = 0;
    srand(time(0)); // seed for rand() function
    number = rand() % 100 + 1; // generate random number between 1 and 100
    printf("Welcome to the Guessing Game!\n");
    printf("The computer has randomly picked a number between 1 and 100.\n");
    printf("You have 10 attempts to guess the number.\n");
    
    while(count < 10)
    {
        printf("Guess #%d: ", count+1);
        scanf("%d", &guess);
        if(guess == number)
        {
            printf("Congratulations! You have guessed the number in %d attempts.\n", count+1);
            break;
        }
        else if(guess < number)
        {
            printf("Your guess is too low.\n");
        }
        else
        {
            printf("Your guess is too high.\n");
        }
        count++;
    }
    
    if(count == 10)
    {
        printf("Game Over. You couldn't guess the number. The number was %d.\n", number);
    }
    
    return 0;
}