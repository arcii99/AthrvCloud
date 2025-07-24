//FormAI DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j;
    int total = 0;
    srand(time(NULL)); //Seed generator with current time

    printf("Welcome to the Dice Roller program!\n");
    printf("Enter the number of dice you want to roll: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides each dice has: ");
    scanf("%d", &numSides);

    if(numDice <= 0 || numSides <= 0) { //Check for invalid inputs
        printf("Sorry, the number of dice and sides must be positive integers.\n");
        return 0;
    }

    printf("Rolling %d d%d...\n\n", numDice, numSides);

    for(i = 1; i <= numDice; i++) { //Roll each dice
        int roll = rand() % numSides + 1;
        printf("Dice %d: %d\n", i, roll);
        total += roll;
    }

    printf("\nTotal roll: %d\n", total); //Print the total

    //Print a histogram of the rolls
    printf("\nDistribution of rolls:\n");
    for(i = 1; i <= numSides; i++) {
        printf("%2d: ", i);
        for(j = 1; j <= numDice; j++) {
            if(rand() % numSides + 1 == i) {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}