//FormAI DATASET v1.0 Category: Dice Roller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dieNum, numRolls, i, roll;
    //dieNum is the number of sides on the dice, numRolls is the number of times the dice will be rolled, and roll is the result of each roll
    srand(time(NULL)); //set the random seed based on the current time

    printf("Welcome to the Dice Roller!\n");
    printf("Enter the number of sides on the die: ");
    scanf("%d", &dieNum);
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    printf("\n\n");

    for (i = 0; i < numRolls; i++) { //for loop to roll the dice the correct number of times
        roll = rand() % dieNum + 1; //generate a random number between 1 and the number of sides on the die
        printf("Roll %d: %d\n", i+1, roll);
    }

    printf("\nThanks for rolling with us!\n");
    return 0;
}