//FormAI DATASET v1.0 Category: Dice Roller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sides, rolls, i, j, total;
    char again;

    printf("Welcome to Ephemeral Dice Roller!\n");

    do {
        total = 0;
        printf("\nHow many sides does your die have? ");
        scanf("%d", &sides);

        printf("How many times do you want to roll the die? ");
        scanf("%d", &rolls);

        printf("\n");
        
        srand(time(NULL));
        for (i = 1; i <= rolls; i++) {
            printf("Roll %d: ", i);
            j = rand() % sides + 1;
            printf("%d\n", j);
            total += j;
        }

        printf("\nTotal: %d\n", total);
        
        printf("\nDo you want to roll again? (y/n) ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("\nThanks for rolling with Ephemeral Dice Roller!\n");

    return 0;
}