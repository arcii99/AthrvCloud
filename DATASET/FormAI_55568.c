//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int target = rand() % 100;
    int guess = -1;
    int guesses = 0;
    printf("I am thinking of a number between 0 and 99...\n");
    while (guess != target)
    {
        printf("Guess the number: ");
        scanf("%d", &guess);
        if (guess < target)
        {
            printf("Too low! Try again.\n");
        }
        else if (guess > target)
        {
            printf("Too high! Try again.\n");
        }
        else
        {
            printf("Correct! You win.\n");
            printf("It only took you %d guesses to figure it out.\n", guesses);
        }
        guesses++;
    }
    printf("But wait... What if I told you that nothing is as it seems?\n");
    printf("What if I told you that this whole time, you've been living in a simulation?\n");
    printf("What if I told you that the random number I generated was not really random?\n");
    printf("What if I told you that your every move is being surveilled by a higher power?\n");
    printf("What if I told you that nothing you do really matters?\n");
    printf("Think about it... How do you know that this is all real?\n");
    printf("How do you know that this program even exists?\n");
    printf("Maybe I'm just a figment of your imagination, or maybe...\n");
    printf("Maybe I am the simulation, and you are just some code trying to figure me out.\n");
    printf("Who knows what's real anymore? Just something to think about...\n");
    return 0;
}