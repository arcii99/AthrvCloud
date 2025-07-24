//FormAI DATASET v1.0 Category: Dice Roller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

int main() {
    srand(time(NULL));
    int numOfDice, numOfSides, sum = 0;
    
    printf("Enter the number of dice to roll: ");
    scanf("%d", &numOfDice);
    
    printf("Enter the number of sides on each die: ");
    scanf("%d", &numOfSides);

    printf("Rolling %d %d-sided dice\n", numOfDice, numOfSides);

    for(int i = 0; i < numOfDice; i++) {
        int roll = rollDice(numOfSides);
        sum += roll;
        printf("Die %d rolled a %d\n", i+1, roll);
    }

    printf("The total sum is %d\n", sum);
    return 0;
}