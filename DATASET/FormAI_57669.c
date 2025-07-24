//FormAI DATASET v1.0 Category: Dice Roller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);

int main(void) {

    int sum,firstRoll,dice1,dice2;
    srand(time(NULL));

    //Get first roll and sum
    dice1 = rollDice();
    dice2 = rollDice();
    firstRoll = sum = dice1 + dice2;

    printf("You rolled %d + %d = %d\n", dice1,dice2,sum);

    //Roll again if first roll was not a win or loss
    while(sum != 7 && sum != 11 && sum != 2 && sum != 3 && sum != 12) {
        dice1 = rollDice();
        dice2 = rollDice();
        sum = dice1 + dice2;
        printf("You rolled %d + %d = %d\n", dice1, dice2, sum);
    }

    //Determine win or loss
    if(sum == 7 || sum == 11) {
        printf("Congratulations! You win!\n\n");
    } else if(sum == 2 || sum == 3 || sum == 12) {
        printf("Craps! You lose!\n\n");
    } else {
        printf("Your point is %d\n\n", sum);

        //Roll until point is matched or 7 is rolled
        do {
            dice1 = rollDice();
            dice2 = rollDice();
            sum = dice1 + dice2;
            printf("You rolled %d + %d = %d\n", dice1, dice2, sum);
        } while(sum != firstRoll && sum != 7);

        //Determine win or loss
        if(sum == firstRoll) {
            printf("Congratulations! You win!\n\n");
        } else if(sum == 7) {
            printf("Sorry! You lose!\n\n");
        }
    }

    return 0;
}

int rollDice(void) {
    return (rand() % 6) + 1;
}