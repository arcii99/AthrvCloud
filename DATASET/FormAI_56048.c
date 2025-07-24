//FormAI DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides;
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &numSides);

    time_t t;
    srand((unsigned) time(&t));
  
    int total = 0;
    printf("Rolling...\n");
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % numSides) + 1;
        printf("Die %d: %d\n", i+1, roll);
        total += roll;
    }

    printf("Total: %d\n", total);
    return 0;
}