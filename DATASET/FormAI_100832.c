//FormAI DATASET v1.0 Category: Random ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // Generate random seed
    srand(time(NULL));

    int roll1 = rand() % 6 + 1; // Random number between 1-6
    int roll2 = rand() % 6 + 1; // Random number between 1-6

    int total = roll1 + roll2; // Calculate total of two rolls

    printf("Welcome to Random Dice Game!\n");
    printf("Rolling the dice...\n");

    printf("You rolled a %d and a %d.\n", roll1, roll2);

    if(total == 7)
    {
        printf("Congratulations! You got a lucky 7! Let's party!\n");
    }
    else if(total % 2 == 0)
    {
        printf("You got an even number! Nice one!\n");
    }
    else
    {
        printf("You got an odd number. But don't worry, you're still awesome!\n");
    }

    return 0;
}