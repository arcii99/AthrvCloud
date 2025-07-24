//FormAI DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
/*
 * This program is a simple dice roller.
 * Written by: [Your name]
 * Email: [Your email]
 * Date: [Current date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, numRolls, i, result;

    srand(time(NULL)); // initialize the random number generator

    printf("Welcome to the dice roller!\n");
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &sides);

    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &numRolls);

    printf("Rolling %d %d-sided dice...\n\n", numRolls, sides);

    for (i = 0; i < numRolls; i++) {
        result = rand() % sides + 1;
        printf("Roll %d: %d\n", i + 1, result);
    }

    printf("\nThanks for using the dice roller!\n");
    return 0;
}