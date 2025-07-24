//FormAI DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_dice, num_sides, i, j, sum;
    char choice;
    srand(time(NULL));
    printf("Welcome to Dice Roller!\n");
    do
    {
        sum = 0;
        printf("How many dice do you want to roll? ");
        scanf("%d", &num_dice);
        printf("How many sides do these dice have? ");
        scanf("%d", &num_sides);
        printf("Rolling...\n");
        for (i = 0; i < num_dice; i++)
        {
            int roll = rand() % num_sides + 1;
            printf("Dice %d: %d\n", i + 1, roll);
            sum += roll;
        }
        printf("Sum: %d\n", sum);
        printf("Roll again? (Y/N) ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    printf("Thanks for playing!\n");
    return 0;
}