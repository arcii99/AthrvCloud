//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice();

int main() {
    srand(time(NULL));
    int num_rolls;
    printf("How many dice rolls would you like to make? ");
    scanf("%d", &num_rolls);
    printf("Rolling %d dice...\n", num_rolls);
    int total_roll = 0;
    for (int i = 0; i < num_rolls; i++) {
        int roll = roll_dice();
        printf("Roll %d: %d\n", i+1, roll);
        total_roll += roll;
    }
    printf("Total roll: %d\n", total_roll);
    return 0;
}

int roll_dice() {
    int roll = (rand() % 6) + 1;
    return roll;
}