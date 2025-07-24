//FormAI DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, total = 0;
    srand(time(NULL));
    
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides: ");
    scanf("%d", &numSides);
    
    printf("\nRolling %d d%d...\n\n", numDice, numSides);
    
    for(int i = 1; i <= numDice; i++) {
        int roll = rand() % numSides + 1;
        printf("Dice %d: %d\n", i, roll);
        total += roll;
    }
    
    printf("\nTotal: %d\n", total);
    
    return 0;
}