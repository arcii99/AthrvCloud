//FormAI DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, rolls, i;
    int total = 0;

    printf("Enter number of sides for your dice: ");
    scanf("%d", &sides);
    printf("Enter number of rolls: ");
    scanf("%d", &rolls);

    srand(time(NULL)); // Seed random number generator with current time

    printf("\nRolling %d %d-sided dice:\n", rolls, sides);

    for (i = 0; i < rolls; i++) {
        int result = (rand() % sides) + 1;
        total += result;

        printf("Roll %d: %d\n", i+1, result);
    }

    printf("\nTotal: %d\n", total);

    return 0;
}