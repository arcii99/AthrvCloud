//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int number_of_dice, int max_dice_value){
    int result;
    if(number_of_dice == 1){ // base case
        result = (rand() % max_dice_value) + 1;
        return result;
    }else{ // recursive case
        return roll_dice(1, max_dice_value) + roll_dice(number_of_dice-1, max_dice_value);
    }
}

int main(){
    srand(time(0));
    printf("Welcome to the recursive dice roller!\n");
    printf("How many dice would you like to roll? ");
    int num_dice;
    scanf("%d", &num_dice);
    printf("What is the maximum value for each die? ");
    int max_val;
    scanf("%d", &max_val);
    printf("\n");
    printf("Rolling %d dice with a maximum value of %d...\n", num_dice, max_val);
    int result = roll_dice(num_dice, max_val);
    printf("Result: %d\n", result);
    return 0;
}