//FormAI DATASET v1.0 Category: Dice Roller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides) {
    int result = rand() % sides + 1;
    return result;
}

int main() {
    int sides, rolls, i, j, total;
    srand(time(NULL)); // Initialize random number generator with seed

    printf("Welcome to the Dice Roller program!\n");
    printf("Please enter the number of sides on the dice: ");
    scanf("%d", &sides);
    printf("Please enter the number of rolls: ");
    scanf("%d", &rolls);

    // Roll dice and print results
    printf("Rolling %d %d-sided dice...\n", rolls, sides);
    for (i = 0; i < rolls; i++) {
        printf("Roll %d: ", i+1);
        total = 0;
        for (j = 0; j < sides; j++) {
            int result = roll_dice(sides);
            total += result;
            printf("%d ", result);
        }
        printf("(Total: %d)\n", total);
    }

    printf("Thanks for using the Dice Roller program!\n");
    return 0;
}