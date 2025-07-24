//FormAI DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int diceNum, sides, result, i;
    char choice;

    printf("How many dice would you like to roll? ");
    scanf("%d", &diceNum);

    printf("How many sides does each die have? ");
    scanf("%d", &sides);

    do {
        srand(time(NULL));
        printf("\nRolling...\n\n");

        for (i = 0; i < diceNum; i++) {
            result = rand() % sides + 1;
            printf("Die #%d: %d\n", i+1, result);
        }

        printf("\nRoll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}