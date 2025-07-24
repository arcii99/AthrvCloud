//FormAI DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char choice;
    int rolls, sides, sum;
    srand(time(NULL));      // seed for random numbers generator

    printf("Welcome to Dice Roller!\n\n");

    do {
        printf("How many dice would you like to roll? ");
        scanf("%d", &rolls);

        printf("How many sides should each die have? ");
        scanf("%d", &sides);

        sum = 0;

        printf("\nRolling %d %d-sided dice...\n", rolls, sides);

        for(int i = 0; i < rolls; i++) {
            int r = rand() % sides + 1;
            sum += r;
            printf("Roll %d: %d\n", i+1, r);
        }

        printf("\nTotal: %d\n\n", sum);

        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("\nThanks for using Dice Roller!\n");

    return 0;
}