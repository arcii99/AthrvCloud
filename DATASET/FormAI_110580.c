//FormAI DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice_number, dice_sides, i;

    //seed the random number generator
    srand((unsigned) time(NULL));

    printf("Welcome to the dice roller program!\n");
    printf("How many dice would you like to roll?\n");
    scanf("%d", &dice_number);

    printf("How many sides does each dice have?\n");
    scanf("%d", &dice_sides);

    printf("\nRolling...\n\n");

    for (i = 1; i <= dice_number; i++) 
    {
        int roll = rand() % dice_sides + 1;
        printf("Dice %d: %d\n", i, roll);
    }

    printf("\nThanks for rolling with us! Play again soon.\n");

    return 0;
}