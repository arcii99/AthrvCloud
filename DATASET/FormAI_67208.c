//FormAI DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sides, numDice, i, j, total;
    char choice;

    printf("Welcome to the dice rolling program!\n");

    do
    {
        printf("\nEnter the number of sides on the dice: ");
        scanf("%d", &sides);

        printf("Enter the number of dice to roll: ");
        scanf("%d", &numDice);

        total = 0;
        srand(time(NULL));

        printf("\nRolling %d %d-sided dice...\n", numDice, sides);

        for (i = 0; i < numDice; i++)
        {
            int roll = rand() % sides + 1;
            printf("Dice %d rolled %d\n", i+1, roll);
            total += roll;
        }

        printf("\nTotal value: %d\n", total);

        printf("\nWould you like to roll again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThanks for using the dice roller! Goodbye!\n");

    return 0;
}