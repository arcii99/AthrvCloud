//FormAI DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const int SIDES = 6;
    const int ROLLS = 2;
    int roll1, roll2, sum = 0;

    srand(time(NULL));

    for (int i = 0; i < ROLLS; i++) {
        roll1 = rand() % SIDES + 1;
        roll2 = rand() % SIDES + 1;
        sum += roll1 + roll2;
        printf("Roll %d: %d + %d = %d\n", i + 1, roll1, roll2, roll1 + roll2);
    }

    printf("Total: %d\n", sum);

    return 0;
}