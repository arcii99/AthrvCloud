//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int num_rolls, dice_sides, i;
    int sum = 0;

    printf("Welcome to the Cryptic Dice Roller!\n");
    printf("Enter the number of dice rolls:\n");
    scanf("%d", &num_rolls);

    printf("Enter the number of sides for each dice:\n");
    scanf("%d", &dice_sides);

    srand(time(NULL));  // Seed the random number generator

    printf("Rolling %d %dsided dice...\n", num_rolls, dice_sides);

    for(i = 0; i < num_rolls; i++)
    {
        int roll = rand() % dice_sides + 1;
        sum += roll;

        printf("Roll %d: %d\n", i + 1, roll);
    }

    printf("Total sum of all rolls: %d\n", sum);

    return 0;
}