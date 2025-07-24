//FormAI DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int diceRoller(int numRolls, int numSides);

int main(){
    int numRolls, numSides;

    printf("*** Welcome to the Energized Dice Roller! ***\n");
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &numSides);

    printf("\nRolling the dice %d times with %d sides...\n\n", numRolls, numSides);

    srand(time(NULL)); // Seed the random number generator

    int result = diceRoller(numRolls, numSides);

    printf("*** The total result is %d ***\n", result);

    return 0;
}

int diceRoller(int numRolls, int numSides){
    int total = 0;

    for(int i = 0; i < numRolls; i++){
        int roll = (rand() % numSides) + 1;
        printf("Roll #%d: %d\n", i+1, roll);
        total += roll;
    }

    return total;
}