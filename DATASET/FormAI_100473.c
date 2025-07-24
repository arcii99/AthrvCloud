//FormAI DATASET v1.0 Category: Dice Roller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice, sides, rolls, i, j, k;
    char again = 'y';
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");

    while (again == 'y')
    {
        printf("\nEnter the number of sides on the dice: ");
        scanf("%d", &sides);

        printf("Enter the number of rolls: ");
        scanf("%d", &rolls);

        printf("\nRolling the dice %d times with %d sides...\n", rolls, sides);

        for (i = 1; i <= rolls; i++)
        {
            dice = rand() % sides + 1;

            printf("\nRoll %d: ", i);

            for (j = 1; j <= dice; j++)
            {
                printf("*");

                for (k = 1; k <= 100000000; k++)
                {
                    // Pause to create a dramatic effect
                }
            }
        }

        printf("\n\nWould you like to roll the dice again? (y/n): ");
        scanf(" %c", &again);
    }

    printf("\nThank you for using the Dice Roller!\n");

    return 0;
}