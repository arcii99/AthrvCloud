//FormAI DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice, seed, rollCount, i, total = 0;
    char choice;

    // Setting the seed for random number generation
    seed = time(NULL);
    srand(seed);

    // Asking user for number of dice rolls
    printf("How many times do you want to roll the dice?\n");
    scanf("%d", &rollCount);

    // Rolling the dice for the specified number of times
    printf("\nRolling the dice %d times...\n", rollCount);
    for (i = 1; i <= rollCount; i++)
    {
        dice = rand() % 6 + 1;
        total += dice;
        printf("Roll #%d: %d\n", i, dice);
    }

    // Displaying the total score
    printf("\nTotal: %d\n", total);

    return 0;
}