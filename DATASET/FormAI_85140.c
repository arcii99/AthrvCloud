//FormAI DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int diceRoller(int maxRange, int numDice){
    int i, total = 0, currentRoll;
    for(i = 1; i <= numDice; i++){
        currentRoll = (rand() % maxRange) + 1;
        printf("Roll %d: %d\n", i, currentRoll);
        total += currentRoll;
    }
    printf("Total: %d\n", total);
    return total;
}

int main(){
    int diceMaxRange, diceNumDice;

    //Seed random number generator based on current time
    srand(time(NULL));

    //Get custom max range for dice
    printf("Enter max range for dice: ");
    scanf("%d", &diceMaxRange);
    if(diceMaxRange < 1){
        printf("*** Invalid Max Range. System exiting. ***\n");
        return 1;
    }

    //Get number of dice to roll
    printf("Enter number of dice to roll: ");
    scanf("%d", &diceNumDice);
    if(diceNumDice < 1){
        printf("*** Invalid Number of Dice to Roll. System exiting. ***\n");
        return 1;
    }

    //Roll the dice
    printf("Rolling %d D%d...\n", diceNumDice, diceMaxRange);
    diceRoller(diceMaxRange, diceNumDice);

    printf("Congratulations, you've rolled dice from a custom range! Please play again soon.\n");
    return 0;
}