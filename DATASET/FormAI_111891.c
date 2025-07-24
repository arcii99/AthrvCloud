//FormAI DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
/*
 * Dice Roller program in C
 *
 * Author: Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 10

int main(void) {
    int dice[6] = {0};
    srand(time(NULL)); /* Seed the random number generator */

    printf("Rolling the dice %d times:\n", ROLLS);

    for (int i = 0; i < ROLLS; i++) {
        int roll = rand() % 6 + 1;
        dice[roll-1]++;
        printf("Roll %d: %d\n", i+1, roll);
    }

    printf("\n---Dice Statistics---\n");

    for (int i = 0; i < 6; i++) {
        printf("Dice %d: %d\n", i+1, dice[i]);
    }

    return 0;
}