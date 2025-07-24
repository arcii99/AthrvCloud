//FormAI DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to simulate rolling of a dice
int roll_dice() {
    return (rand() % 6) + 1;
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // prompt user for number of rolls
    int num_rolls;
    printf("How many times do you want to roll the dice?: ");
    scanf("%d", &num_rolls);
    printf("\n");

    // roll the dice and print the results
    printf("Rolling the dice %d times...\n\n", num_rolls);
    for (int i = 0; i < num_rolls; i++) {
        int result = roll_dice();
        printf("Roll %d: %d\n", i + 1, result);
    }

    return 0;
}