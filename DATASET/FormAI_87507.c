//FormAI DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numSides, numRolls, sum = 0;
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &numSides);

    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    srand(time(NULL));
    printf("Rolling %d %d-sided dice...\n", numRolls, numSides);
    for (int i = 0; i < numRolls; i++) {
        int roll = rand() % numSides + 1;
        printf("Roll %d: %d\n", i+1, roll);
        sum += roll;
    }

    printf("Total: %d\n", sum);
    return 0;
}