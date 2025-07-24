//FormAI DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, rolls, i;
    char choice;

    srand(time(NULL)); // seed random number generator with current time

    printf("Welcome to the Dice Roller!\n");
    printf("Enter the number of sides on the die you want to roll: ");
    scanf("%d", &sides);

    printf("Enter the number of rolls: ");
    scanf("%d", &rolls);

    printf("\nRolling the %dd%d dice...\n", rolls, sides);

    for (i = 1; i <= rolls; i++) {
        printf("Roll %d: %d\n", i, (rand() % sides) + 1);
    }

    do {
        printf("\nWant to roll again? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("\nEnter the number of sides on the die you want to roll: ");
            scanf("%d", &sides);

            printf("Enter the number of rolls: ");
            scanf("%d", &rolls);

            printf("\nRolling the %dd%d dice...\n", rolls, sides);

            for (i = 1; i <= rolls; i++) {
                printf("Roll %d: %d\n", i, (rand() % sides) + 1);
            }
        }
    } while (choice == 'y' || choice == 'Y');

    printf("\nThanks for using the Dice Roller!\n");

    return 0;
}