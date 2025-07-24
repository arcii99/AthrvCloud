//FormAI DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int num_dice, int num_sides);

int main(void) {
    int num_dice, num_sides;
    srand((unsigned) time(NULL));
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides per die: ");
    scanf("%d", &num_sides);
    printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);
    printf("The total is: %d\n", roll_dice(num_dice, num_sides));
    return 0;
}

int roll_dice(int num_dice, int num_sides) {
    int total = 0;
    for (int i = 0; i < num_dice; i++) {
        total += rand() % num_sides + 1;
    }
    return total;
}