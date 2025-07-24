//FormAI DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, diceNum, rollSum, i;
    char choice;
    srand(time(0));  // Seed value for random number generator

    do {
        printf("Enter the number of dice to roll: ");
        scanf("%d", &diceNum);

        printf("Enter the number of sides for the dice: ");
        scanf("%d", &sides);

        rollSum = 0;  // Reset roll sum value for each roll

        printf("\nRolling %d dice with %d sides...\n\n", diceNum, sides);

        for(i = 0; i < diceNum; i++) {
            int roll = rand() % sides + 1;  // Random number generation for each dice roll
            printf("Dice %d rolled: %d\n", i + 1, roll);
            rollSum += roll;
        }

        printf("\nTotal roll sum: %d\n", rollSum);

        printf("\nRoll again? (y/n): ");
        scanf("%s", &choice); 
    } while(choice == 'y' || choice == 'Y');

    return 0;
}