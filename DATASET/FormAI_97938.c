//FormAI DATASET v1.0 Category: Dice Roller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int numRolls;
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &numRolls);

    srand(time(NULL));

    printf("\nRolling the dice %d times...\n\n", numRolls);

    int i;
    for (i = 0; i < numRolls; i++) {
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;

        printf("You have rolled a %d and a %d for a total of %d!\n", dice1, dice2, (dice1 + dice2));

        if (dice1 == dice2) {
            printf("Congratulations! You have rolled a double of %d!\n", dice1);
        }

        printf("----------------------------\n");
    }

    printf("Thank you for rolling with us!\n");
    return 0;
}