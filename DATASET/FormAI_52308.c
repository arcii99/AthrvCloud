//FormAI DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides) {
    return rand() % sides + 1;
}

int main() {
    srand(time(NULL));
    int sides, rolls;
    printf("Welcome to the Medieval Dice Roller!\n");
    printf("Please enter the number of sides on the dice: ");
    scanf("%d", &sides);
    printf("Please enter the number of rolls: ");
    scanf("%d", &rolls);
    printf("Rolling %d d%d...\n", rolls, sides);
    int total = 0;
    for (int i = 0; i < rolls; i++) {
        int roll = rollDice(sides);
        printf("Roll %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
    printf("Thank you for using the Medieval Dice Roller!\n");
    return 0;
}