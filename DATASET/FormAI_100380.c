//FormAI DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int numDice, numSides, i;
    char choice;

    printf("Welcome to the Dice Roller Program!\n");
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &numSides);

    do {

        printf("\nRolling %d dice with %d sides...\n", numDice, numSides);
        srand(time(NULL));

        for (i = 1; i <= numDice; i++) {
            printf("Die %d: %d\n", i, rand() % numSides + 1);
        }

        printf("\nWould you like to roll again? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("\nThank you for using the Dice Roller Program!\n");

    return 0;
}