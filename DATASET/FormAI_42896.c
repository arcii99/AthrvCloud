//FormAI DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diceNum, diceRolls, i, j;

    printf("Enter the number of dice: ");
    scanf("%d", &diceNum);
    printf("\nEnter the number of rolls: ");
    scanf("%d", &diceRolls);

    srand(time(NULL));
    int diceSum = 0;
    for (i = 0; i < diceRolls; i++) {
        printf("\nRoll %d: ", i+1);
        for (j = 0; j < diceNum; j++) {
            int diceRoll = (rand() % 6) + 1;
            printf("%d ", diceRoll);
            diceSum += diceRoll;
        }
        printf("\n");
    }

    printf("\nTotal score: %d\n", diceSum);

    return 0;
}