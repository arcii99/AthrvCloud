//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int dice, roll, total = 0;
    char ans;

    srand(time(NULL));

    printf("***************************************\n");
    printf("******** Retro Dice Roller ************\n");
    printf("***************************************\n");

    do {
        printf("How many dice do you want to roll? (1-5) ");
        scanf("%d", &dice);

        if (dice < 1 || dice > 5) {
            printf("Invalid input. Please enter a value from 1 to 5.\n");
            continue;
        }

        printf("\nRolling dice...\n\n");

        for (int i = 1; i <= dice; i++) {
            roll = rand() % 6 + 1;
            total += roll;
            printf("Dice %d: %d\n", i, roll);
        }

        printf("Total: %d\n\n", total);
        printf("Want to roll again? (Y/N) ");
        scanf(" %c", &ans);

        total = 0;

    } while (ans == 'Y' || ans == 'y');

    printf("Thanks for playing!\n");

    return 0;
}