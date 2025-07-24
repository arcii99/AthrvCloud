//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    int num, guess, tries = 0;
    srand(time(0)); // generates random seed for each run
 
    num = rand() % 100 + 1; // generates a random number between 1 and 100
 
    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have to guess what it is in 10 tries or less.\n\n");
 
    do
    {
        printf("Guess a number: ");
        scanf("%d", &guess);
        tries++;
 
        if (guess > num)
        {
            printf("Too high! Try again.\n\n");
        }
        else if (guess < num)
        {
            printf("Too low! Try again.\n\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
        }
 
    } while (guess != num && tries < 10);
 
    if (tries == 10)
    {
        printf("Sorry! You have used up all your tries. The number was %d.\n", num);
    }
 
    return 0;
}