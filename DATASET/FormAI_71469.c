//FormAI DATASET v1.0 Category: Dice Roller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototype
int roll_dice(int num_dice, int num_sides);

int main(void) {
    int dice, sides;

    // get input from user
    printf("Enter the number of dice and sides each dice has (separated by a space): ");
    scanf("%d %d", &dice, &sides);

    // seed the random number generator
    srand((unsigned int) time(NULL));

    // generate the random numbers and print the result
    printf("You rolled: %d\n", roll_dice(dice, sides));

    return 0;
}

// function definition
int roll_dice(int num_dice, int num_sides) {
    int total = 0;

    // roll the dice and calculate the total
    for (int i = 0; i < num_dice; i++) {
        total += rand() % num_sides + 1;
    }

    return total;
}