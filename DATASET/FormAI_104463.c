//FormAI DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int roll, sides, numDice;

    //Set up random number generator
    srand(time(NULL));

    printf("Welcome to the Dice Roller 3000\n");
    printf("Please enter the number of sides on the dice: ");
    scanf("%d", &sides);

    printf("Please enter the number of dice: ");
    scanf("%d", &numDice);

    if(sides < 2 || numDice < 1) {
        printf("Invalid input. Exiting program.\n");
        return 0;
    }

    printf("You will be rolling %d %d-sided dice\n", numDice, sides);

    int total = 0;

    for(int i = 0; i < numDice; i++) {
        roll = rand() % sides + 1;
        printf("Dice #%d rolled: %d\n", i+1, roll);
        total += roll;
    }

    printf("Total result: %d\n", total);

    return 0;
}