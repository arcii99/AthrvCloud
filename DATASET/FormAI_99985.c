//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, number, sides, total = 0;
    char roll_again = 'y';

    srand(time(NULL)); // Initialize random seed

    printf("Welcome to the C Dice Roller program!\n");

    while (roll_again == 'y')
    {
        printf("\nEnter the number of sides on your dice:\n");
        scanf("%d", &sides);

        printf("\nEnter the number of times you want to roll the dice:\n");
        scanf("%d", &number);

        printf("\nRolling the dice %d time(s)...\n", number);

        for (i = 0; i < number; i++)
        {
            int roll = rand() % sides + 1;
            total += roll;
            printf("%d ", roll);
        }

        printf("\nTotal: %d\n", total);

        printf("\nDo you want to roll again? (y/n)\n");
        scanf(" %c", &roll_again);

        total = 0; // Reset total for next roll
    }

    printf("\nThank you for using the C Dice Roller program!\n");

    return 0; // Exit program
}