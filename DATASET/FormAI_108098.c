//FormAI DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, totalRoll = 0;
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides: ");
    scanf("%d", &numSides);
    printf("\nRolling %d %d-sided dice...\n", numDice, numSides);
    srand(time(NULL));  // seed the random number generator with the current time
    for (int i = 0; i < numDice; i++) {
        int roll = rand() % numSides + 1;  // generate a random number between 1 and numSides
        printf("Dice %d: %d\n", i+1, roll);
        totalRoll += roll;  // increment the totalRoll variable
    }
    printf("Total roll: %d\n", totalRoll);
    return 0;
}