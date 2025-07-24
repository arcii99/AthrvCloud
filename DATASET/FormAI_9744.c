//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sides, rolls, i, total = 0;
    srand(time(NULL));
    
    printf("Welcome to the Retro Dice Roller!\n\n");
    
    // Get the number of sides on the dice
    printf("How many sides do your dice have? ");
    scanf("%d", &sides);
    
    while (sides < 2)
    {
        printf("Dice must have at least two sides. Please enter a valid number of sides: ");
        scanf("%d", &sides);
    }
    
    // Get the number of dice rolls
    printf("\nHow many rolls would you like to make? ");
    scanf("%d", &rolls);
    
    // Roll the dice and calculate the total
    printf("\nRolling %d %d-sided dice...\n", rolls, sides);
    
    for (i = 1; i <= rolls; i++)
    {
        int roll = rand() % sides + 1;
        total += roll;
        printf("Roll %d: %d\n", i, roll);
    }
    
    printf("\nTotal: %d\n", total);
    
    return 0;
}