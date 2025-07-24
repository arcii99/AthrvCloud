//FormAI DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int num_sides, num_rolls;

    printf("Welcome to the Dice Roller!\n");
    printf("How many sides does your dice have?\n");
    scanf("%d", &num_sides);

    printf("How many times would you like to roll the dice?\n");
    scanf("%d", &num_rolls);

    if (num_sides <= 1) {
        printf("Invalid number of sides! Must be greater than 1.\n");
        return 1;
    }

    if (num_rolls <= 0) {
        printf("Invalid number of rolls! Must be greater than 0.\n");
        return 1;
    }

    printf("Rolling the dice %d times with %d sides...\n", num_rolls, num_sides);

    srand(time(NULL));

    for (int i = 0; i < num_rolls; i++) {
        int roll = rand() % num_sides + 1;
        printf("Roll %d: %d\n", i+1, roll);
    }

    printf("Thanks for using the Dice Roller!\n");

    return 0;
}