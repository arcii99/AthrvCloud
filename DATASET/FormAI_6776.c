//FormAI DATASET v1.0 Category: Dice Roller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides) {
    return (rand() % sides) + 1;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    int num_dice, num_sides;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides do the dice have? ");
    scanf("%d", &num_sides);
    printf("\n");

    printf("Rolling %d dice with %d sides...\n\n", num_dice, num_sides);

    int total = 0;
    for (int i = 0; i < num_dice; ++i) {
        int roll = roll_dice(num_sides);
        total += roll;
        printf("Die %d: %d\n", i + 1, roll);
    }

    printf("\nTotal: %d\n", total);

    return 0;
}