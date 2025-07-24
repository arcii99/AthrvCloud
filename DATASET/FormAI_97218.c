//FormAI DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diceRolls;
    int sides;
    int total = 0;
    int roll;
    int i, j;

    printf("Enter the number of dice rolls: ");
    scanf("%d", &diceRolls);

    printf("Enter the number of sides per die: ");
    scanf("%d", &sides);

    srand(time(NULL));

    printf("Rolling %d %d-sided dice...\n", diceRolls, sides);

    for (i = 0; i < diceRolls; i++) {
        roll = rand() % sides + 1;

        printf("Roll %d: %d\n", i+1, roll);
        total += roll;
    }

    printf("Total: %d\n", total);

    return 0;
}