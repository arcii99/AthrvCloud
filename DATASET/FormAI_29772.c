//FormAI DATASET v1.0 Category: Dice Roller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RollDice()
{
    int roll = rand() % 6 + 1;
    return roll;
}

int main()
{
    srand(time(NULL));
    printf("Welcome to the Dice Roller Program\n");
    printf("----------------------------------\n");

    int numRolls = 0;
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    printf("\nRolling the dice %d times...\n", numRolls);

    int i;
    int sum = 0;
    for (i = 0; i < numRolls; i++)
    {
        int roll = RollDice();
        printf("Roll %d: %d\n", i+1, roll);
        sum += roll;
    }

    printf("\nTotal score: %d\n", sum);

    return 0;
}