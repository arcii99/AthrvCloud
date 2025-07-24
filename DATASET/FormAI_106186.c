//FormAI DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, answer, tries = 0;
    srand(time(0)); // seeds random number generator with current time
    answer = rand() % 100 + 1; // generates random number between 1 and 100
    
    printf("Guess the number between 1 and 100!\n\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;
        
        if (guess > answer)
        {
            printf("Too high!\n\n");
        }
        else if (guess < answer)
        {
            printf("Too low!\n\n");
        }
        else
        {
            printf("\nCongratulations, you guessed the number in %d tries!\n", tries);
        }
    } while (guess != answer);

    return 0;
}