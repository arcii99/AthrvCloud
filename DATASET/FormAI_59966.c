//FormAI DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int num_dice, int dice_sides) {
    int total = 0;
    for (int i = 0; i < num_dice; i++) {
        total += rand() % dice_sides + 1;
    }
    return total;
}

int main() {
    srand(time(NULL));
    int num_dice, dice_sides, total;
    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides does each die have? ");
    scanf("%d", &dice_sides);
    total = roll_dice(num_dice, dice_sides);
    printf("\nYou rolled %d %d-sided dice and got a total of %d!\n", num_dice, dice_sides, total);
    return 0;
}