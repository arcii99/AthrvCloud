//FormAI DATASET v1.0 Category: Dice Roller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //initialize random seed
    char input; //input variable for user's choice

    printf("Welcome to the Dice Roller program!\n");

    do {
        printf("Press 'r' to roll the dice or 'q' to quit: ");
        scanf(" %c", &input); //get user's choice
        if (input == 'r') {
            int roll = (rand() % 6) + 1; //roll the dice and get a number between 1 and 6
            printf("You rolled a %d!\n", roll);
        } else if (input != 'q') {
            printf("Invalid input!\n");
        }
    } while (input != 'q'); //keep rolling until user quits

    printf("Thanks for using the Dice Roller program!\n");

    return 0;
}