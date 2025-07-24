//FormAI DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES_OF_DICE 6
#define NUM_OF_DICE 2

int main() {
    int i = 0;
    int roll = 0;
    int sum = 0;
    
    /* Set the random seed to the current time */
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n\n");

    /* Roll the dice NUM_OF_DICE times and sum up the total */
    for (i = 0; i < NUM_OF_DICE; i++) {
        roll = rand() % SIDES_OF_DICE + 1;
        printf("Dice %d: %d\n", i + 1, roll);
        sum += roll;
    }

    printf("\nTotal: %d\n", sum);

    return 0;
}