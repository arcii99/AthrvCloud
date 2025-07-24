//FormAI DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides){
    return rand() % sides + 1;
}

int main(){
    int sides, numDice, total = 0;

    printf("Welcome to the Dice Roller!\n");

    printf("\nEnter the number of dice you want to roll: ");
    scanf("%d", &numDice);

    printf("\nEnter the number of sides on the dice: ");
    scanf("%d", &sides);

    srand(time(NULL));

    printf("\nYou rolled: ");

    for(int i = 0; i < numDice; i++){
        int roll = rollDice(sides);
        printf("%d ", roll);
        total += roll;
    }

    printf("\nTotal: %d\n", total);

    return 0;
}