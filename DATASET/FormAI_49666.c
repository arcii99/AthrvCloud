//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice() {

    int firstDie, secondDie, totalRoll, countRolls = 0;
    srand(time(NULL)); 

    while (totalRoll != 7) {
        firstDie = rand() % 6 + 1; 
        secondDie = rand() % 6 + 1; 
        totalRoll = firstDie + secondDie; 
        printf("You rolled a %d and a %d, for a total of %d.\n", firstDie, secondDie, totalRoll); 
        countRolls++; 
    }

    printf("It took you %d roll(s) to roll a 7!\n", countRolls); 

}

int main() {

    int userInput;

    printf("Welcome to the Dice Roller! Press 1 to roll the dice or 0 to exit.\n"); 
    scanf("%d", &userInput);

    while (userInput != 0) {

        if (userInput == 1) {
            rollDice(); 
        }
        else {
            printf("Invalid input. Please press 1 to roll the dice or 0 to exit.\n"); 
        }

        printf("Press 1 to roll the dice again or 0 to exit.\n"); 
        scanf("%d", &userInput); 
    }

    printf("Thanks for playing the Dice Roller!\n"); 

    return 0; 

}