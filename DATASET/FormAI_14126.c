//FormAI DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int piles[3] = {3, 4, 5};
    int player = 1;

    printf("Welcome to Nim! Here are the starting piles:\n");
    printf("Pile 1: %d\n", piles[0]);
    printf("Pile 2: %d\n", piles[1]);
    printf("Pile 3: %d\n\n", piles[2]);

    while (piles[0] > 0 || piles[1] > 0 || piles[2] > 0)
    {
        int pile_num, num_remove;

        printf("Player %d, choose a pile (1-3): ", player);
        scanf("%d", &pile_num);
        printf("How many would you like to remove? ");
        scanf("%d", &num_remove);

        if (pile_num < 1 || pile_num > 3 || num_remove < 1 || num_remove > piles[pile_num-1])
        {
            printf("Invalid move. Please try again.\n\n");
            continue;
        }

        piles[pile_num-1] -= num_remove;

        printf("\nPile 1: %d\n", piles[0]);
        printf("Pile 2: %d\n", piles[1]);
        printf("Pile 3: %d\n\n", piles[2]);

        if (piles[0] == 0 && piles[1] == 0 && piles[2] == 0)
        {
            printf("Player %d wins!\n", player);
            break;
        }

        player = player == 1 ? 2 : 1;
    }

    return 0;
}