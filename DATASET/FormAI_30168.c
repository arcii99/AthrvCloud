//FormAI DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int numRolls, numDice, dieSize, i, j, total;
    char choice;

    printf("Welcome to the Dice Roller!\n\n");

    do {
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);

        printf("What size of dice? ");
        scanf("%d", &dieSize);

        printf("How many rolls? ");
        scanf("%d", &numRolls);

        printf("\n\nRolling %d %dd%d's...\n\n", numRolls, numDice, dieSize);

        srand(time(NULL));

        for (i = 0; i < numRolls; i++) {
            total = 0;

            printf("Roll %d: ", i+1);

            for (j = 0; j < numDice; j++) {
                int roll = (rand() % dieSize) + 1;
                printf("%d ", roll);
                total += roll;
            }

            printf("- Total: %d\n", total);
        }

        printf("\n\nWould you like to roll again? (Y/N) ");
        scanf(" %c", &choice);
        printf("\n");
    } while (choice == 'Y' || choice == 'y');

    printf("Thank you for using the Dice Roller!\n");

    return 0;
}