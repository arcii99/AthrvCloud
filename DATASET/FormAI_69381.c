//FormAI DATASET v1.0 Category: Dice Roller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int numOfDice, numOfSides, i, j;

    printf("How many dice do you want to roll? ");
    scanf("%d", &numOfDice);
    printf("How many sides do the dice have? ");
    scanf("%d", &numOfSides);

    srand(time(NULL));
    for (i = 0; i < numOfDice; i++) {
        printf("Dice %d: ", i+1);
        int sum = 0;
        for (j = 0; j < numOfSides; j++) {
            int roll = rand() % numOfSides + 1;
            printf("%d ", roll);
            sum += roll;
        }
        printf("= %d\n", sum);
    }
    return 0;
}