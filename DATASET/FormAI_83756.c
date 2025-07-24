//FormAI DATASET v1.0 Category: Dice Roller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice, num, min = 1, max = 6;
    srand(time(NULL)); // Initialize random number generator

    printf("How many dice do you want to roll? ");
    scanf("%d", &dice);

    // Make sure user enters a positive integer
    while (dice <= 0) {
        printf("Invalid input. Enter a positive integer: ");
        scanf("%d", &dice);
    }

    // Roll the dice!
    printf("\nRolling %d dice...\n\n", dice);
    for (int i = 1; i <= dice; i++) {
        num = (rand() % (max - min + 1)) + min; // Generate a random number between 1 and 6
        printf("Dice #%d: %d\n", i, num);
    }

    return 0;
}