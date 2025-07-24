//FormAI DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    int result = rand() % 6 + 1;
    return result;
}

int main() {
    srand(time(NULL));
    int diceOne = 0, diceTwo = 0, result = 0;
    char choice;
    do {
        printf("Roll the dice? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            diceOne = rollDice();
            diceTwo = rollDice();
            result = diceOne + diceTwo;
            printf("\nDie 1: %d\nDie 2: %d\nTotal: %d\n", diceOne, diceTwo, result);
        }
    } while(choice != 'n');
    return 0;
}