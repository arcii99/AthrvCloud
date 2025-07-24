//FormAI DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, number, count=0;
    srand(time(0));
    number = rand()%50+1;   // Generate random number between 1 and 50

    printf("Welcome to the Number Guessing Game!\n");
    printf("You have to guess a number between 1 and 50.\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess); 
        count++;   // increase guess count

        if (guess > number)
            printf("Too high! Try again.\n");

        else if (guess < number)
            printf("Too low! Try again.\n");

        else
            printf("Congratulations! You guessed the number in %d tries.\n", count);

    } while (guess != number);

    return 0;
}