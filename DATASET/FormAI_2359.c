//FormAI DATASET v1.0 Category: Dice Roller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diceSides, numRolls, i, rollSum=0;
    //Ask user for number of sides on dice
    printf("Enter number of sides on dice: ");
    scanf("%d", &diceSides);
    //Ask user for number of rolls
    printf("Enter number of rolls: ");
    scanf("%d", &numRolls);
    //Seed random number generator with current time
    srand(time(NULL));
    //Roll the dice the specified number of times
    for(i=1; i<=numRolls; i++) {
        int rollResult = rand() % diceSides + 1;
        printf("Roll #%d: %d\n", i, rollResult);
        rollSum += rollResult;
    }
    //Print out the sum of all rolls
    printf("Sum: %d\n", rollSum);
    return 0;
}