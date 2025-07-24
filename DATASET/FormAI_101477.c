//FormAI DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char choice;
    int diceSize, diceNum, numRolls, rollCount;
    int i, j, roll;
    srand(time(0));     //seed for random number
    do {
        printf("Welcome to the Dice Roller\n----------------------------\n");
        printf("Enter the size of the dice to roll: ");
        scanf("%d", &diceSize);
        printf("Enter the number of dice to roll: ");
        scanf("%d", &diceNum);
        printf("Enter the number of rolls: ");
        scanf("%d", &numRolls);
        
        printf("\nRolling %d %d-sided dice %d times:\n", diceNum, diceSize, numRolls);
        printf("-------------------------------------\n");
        rollCount = 0;
        for (i = 0; i < numRolls; i++) {
            roll = 0;
            for (j = 0; j < diceNum; j++) {
                roll += rand() % diceSize + 1;  //rolling dice
            }
            printf("Roll %d: %d\n", i+1, roll);
            rollCount += roll;
        }
        printf("-------------------------------------\n");
        printf("Total score for %d rolls: %d\n", numRolls, rollCount);
        
        printf("\nDo you want to roll again? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    return 0;
}