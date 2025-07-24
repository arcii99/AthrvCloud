//FormAI DATASET v1.0 Category: Dice Roller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int roll, i;
    char choice;

    printf("Welcome to the Happy Dice Roller!\n");
    printf("=================================\n\n");

    do {
        printf("How many times would you like to roll the dice? ");
        scanf("%d", &roll);

        printf("\nRolling the dice %d time(s):\n", roll);

        srand(time(NULL));

        for(i = 1; i <= roll; i++) {
            printf("%d ", rand() % 6 + 1);
        }

        printf("\n\n");

        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &choice);

        while(choice != 'y' && choice != 'n') {
            printf("Invalid input! Please enter 'y' or 'n': ");
            scanf(" %c", &choice);
        }

        printf("\n");

    } while(choice == 'y');

    printf("Thanks for using the Happy Dice Roller!\n");
    printf("======================================\n");

    return 0;
}