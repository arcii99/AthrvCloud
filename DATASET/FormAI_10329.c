//FormAI DATASET v1.0 Category: Dice Roller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, rolls, total = 0, roll;
    srand(time(NULL));

    printf("Enter the number of sides on the dice: ");
    scanf("%d", &sides);

    printf("Enter the number of rolls: ");
    scanf("%d", &rolls);

    printf("Rolling %d %d-sided dice...\n", rolls, sides);
    for (int i = 0; i < rolls; i++) {
        roll = (rand() % sides) + 1;
        printf("Roll %d: %d\n", i+1, roll);
        total += roll;
    }

    printf("The total is %d\n", total);
    printf("The average is %.2f\n", (float) total / rolls);

    return 0;
}