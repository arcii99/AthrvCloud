//FormAI DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice;
    int sides;
    int roll_again = 1;
    srand(time(0));

    printf("\nWelcome to the post-apocalyptic Dice Roller.\n");

    while (roll_again == 1)
    {
        printf("\nEnter the number of sides on your dice: ");
        scanf("%d", &sides);

        if (sides < 2)
        {
            printf("Invalid number of sides. Minimum 2 required.");
            continue;
        }

        printf("\nRolling the dice...\n");

        dice = rand() % sides + 1;

        printf("\nYou rolled a %d!\n", dice);

        printf("Roll again? (1 for yes / 0 for no): ");
        scanf("%d", &roll_again);
    }

    printf("\nThanks for playing!\n");

    return 0;
}