//FormAI DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int dice) {
    /* roll the dice and return the sum of the results */
    int i, sum = 0;

    for (i = 0; i < dice; i++) {
        sum += (rand() % 6) + 1;
    }

    return sum;
}

int main() {
    int dice, times, i, sum;

    /* seed random number generator */
    srand(time(0));

    printf("Enter number of dice: ");
    scanf("%d", &dice);

    printf("Enter number of times to roll: ");
    scanf("%d", &times);

    for (i = 0; i < times; i++) {
        sum = roll_dice(dice);
        printf("Roll %d: %d\n", i + 1, sum);
    }

    return 0;
}