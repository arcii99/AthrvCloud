//FormAI DATASET v1.0 Category: Dice Roller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int max = 6, min = 1, diceRoll;
    char choice;

    srand((unsigned) time(NULL));

    do {
        printf("Press Enter to roll the dice: \n");
        getchar();

        diceRoll = (rand() % (max - min + 1)) + min;
        printf("The dice shows: %d\n", diceRoll);

        printf("Do you want to roll again? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for playing!\n");

    return 0;
}