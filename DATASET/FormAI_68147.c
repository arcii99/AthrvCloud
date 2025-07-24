//FormAI DATASET v1.0 Category: Funny ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int diceRoll1, diceRoll2, totalRoll, i;
    int rollCount = 0;
    srand(time(0));
    printf("Welcome to the Jester's Dice Game!\n\n");
    printf("The game starts now, press enter to roll the dice!\n");
    getchar();

    do {
        ++rollCount;
        diceRoll1 = rand() % 6 + 1;
        diceRoll2 = rand() % 6 + 1;
        totalRoll = diceRoll1 + diceRoll2;

        printf("\nYou rolled %d and %d, total of %d\n", diceRoll1, diceRoll2, totalRoll);
        
        if (totalRoll == 7) {
            printf("Congratulations, you won the game!\n");
        } else {
            printf("Sorry, try again!\n");
        }

        printf("Press enter to roll the dice again!\n");
        getchar();
    } while (totalRoll != 7);

    printf("\nYou won the game in %d rolls!\n", rollCount);

    return 0;
}