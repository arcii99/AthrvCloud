//FormAI DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);

int main(void)
{
    srand(time(NULL));
    int numRolls = 0;
    int numSides;
    int total = 0;
    printf("Welcome to the Dice Roller!\n");
    printf("How many sides does your dice have? ");
    scanf("%d", &numSides);
    while(numSides<=0){
        printf("Please enter a valid number of sides: ");
        scanf("%d",&numSides);
    }
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);
    while(numRolls<=0){
        printf("Please enter a valid number of rolls: ");
        scanf("%d",&numRolls);
    }
    printf("Rolling the dice %d times...\n\n", numRolls);
    for(int i=0; i<numRolls; i++){
        int roll = rollDice();
        total += roll;
        printf("Roll %d: %d\n", i+1, roll);
    }
    printf("\nTotal: %d\n", total);
    return 0;
}

int rollDice(void){
    int numSides;
    while(numSides<=0){
        printf("Please enter a valid number of sides: ");
        scanf("%d",&numSides);
    }
    int result = rand() % numSides + 1;
    return result;
}