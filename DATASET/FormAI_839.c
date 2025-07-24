//FormAI DATASET v1.0 Category: Dice Roller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, numberOfDice, numberOfSides, sum = 0, totalRolls=1, num;
    printf("How many dice do you want to roll?\n");
    scanf("%d", &numberOfDice);
    printf("How many sides does each die have?\n");
    scanf("%d", &numberOfSides);
    printf("How many times do you want to roll the dice?\n");
    scanf("%d", &num);
    srand(time(NULL));
    printf("\nRolling %d dice with %d sides %d times:\n", numberOfDice, numberOfSides, num);
    printf("Rolls\tSum\n");
    while(totalRolls<=num){
        printf("%d:\t", totalRolls);
        i=1; 
        sum=0;
        while(i<=numberOfDice){
            int roll = 1 + (rand() % numberOfSides);
            printf("%d ", roll);
            sum += roll;
            i++;
        }
        printf("\t%d", sum);
        printf("\n");
        totalRolls++;
    }
    return 0;
}