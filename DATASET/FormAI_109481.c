//FormAI DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int num_dice, int num_sides) {
    int result = 0;
    for (int i = 0; i < num_dice; i++) {
        int roll = (rand() % num_sides) + 1;
        printf("Die %d: %d\n", i+1, roll);
        result += roll;
    }
    printf("Total: %d\n", result);
    return result;
}

int main() {
    srand(time(NULL));
    int num_dice, num_sides;
    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides does each die have? ");
    scanf("%d", &num_sides);
    printf("Rolling %d d%d...\n", num_dice, num_sides);
    int result = roll_dice(num_dice, num_sides);
    printf("You rolled a total of %d.\n", result);
    return 0;
}