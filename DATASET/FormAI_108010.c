//FormAI DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, num;

    //seed for random number generation
    srand(time(0));

    //display welcome message
    printf("***Dice Roller***\n\n");

    //get number of dice rolls
    printf("How many dice rolls do you want? ");
    scanf("%d", &num);

    //roll the dice and display results
    printf("\nRolling the dice...\n\n");

    for(i=1; i<=num; i++){
        printf("Roll %d: %d\n", i, rand()%6+1);
    }

    printf("\nThanks for using Dice Roller!\n");

    return 0;
}