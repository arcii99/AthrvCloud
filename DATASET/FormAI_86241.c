//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void rollDice(void); //Function prototype for rolling dice

int main(void) {
    printf("Welcome to the Dice Roller!\n");
    printf("Press 'r' to roll the dice and 'q' to quit.\n");

    srand(time(NULL)); //Seed the random number generator

    char input;
    do {
        input = getchar(); //Get user input

        if(input == 'r') {
            rollDice();
        }
        else if(input != 'q') {
            printf("Invalid input. Please try again.\n");
        }

    } while(input != 'q'); //Keep rolling until user quits

    return 0;
}

void rollDice(void) {
    int dice1 = rand() % 6 + 1; //Generate random number between 1-6
    int dice2 = rand() % 6 + 1;

    printf("You rolled a %d and a %d.\n", dice1, dice2);

    if(dice1 == dice2) { //If user rolls same number on both dice, it's a double
        printf("Congratulations! You rolled a double!\n");
    }
}