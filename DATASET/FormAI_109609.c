//FormAI DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(){
    return (rand() % 6) + 1;
}

int main(){
    int numDice, dieValue, diceSum;
  
    //Seed random number generator with current time
    srand(time(0));
  
    printf("How many dice would you like to roll?\n");
    scanf("%d", &numDice);

    printf("What type of dice would you like to roll (enter number of faces)?\n");
    scanf("%d", &dieValue);

    printf("\nRolling %d d%d dice...\n", numDice, dieValue);
    printf("----------------------\n");

    diceSum = 0;

    //Roll each die and print the result
    for(int i=0;i<numDice;i++){
        int roll = rollDice();
        diceSum += roll;
        printf("Die #%d: %d\n",i+1,roll);
    }

    printf("\nSum of rolls: %d\n",diceSum);

    return 0;
}