//FormAI DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_dice = 1;
    int num_sides = 6;
    int roll_total = 0;

    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");

    while (1) {
        printf("Enter the number of dice to roll (or 0 to quit): ");
        scanf("%d", &num_dice);

        if (num_dice == 0) {
            break;
        }

        printf("Enter the number of sides each die should have: ");
        scanf("%d", &num_sides);

        roll_total = 0;

        printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);

        for (int i = 0; i < num_dice; i++) {
            int roll = rand() % num_sides + 1;
            printf("Die %d: %d\n", i+1, roll);
            roll_total += roll;
        }

        printf("Total roll: %d\n\n", roll_total);
    }

    printf("Thanks for using the Dice Roller!\n");
    return 0;
}