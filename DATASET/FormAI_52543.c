//FormAI DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j;
    srand(time(0));
    
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many sides do the dice have? ");
    scanf("%d", &numSides);

    printf("\nRolling %d %d-sided dice...\n\n", numDice, numSides);

    for(i = 1; i <= numDice; i++) {
        printf("Roll %d: ", i);
        int sum = 0;
        for(j = 1; j <= numSides; j++) {
            int roll = rand() % numSides + 1;
            sum += roll;
            printf("%d ", roll);
        }
        printf("(Total: %d)\n", sum);
    }

    return 0;
}