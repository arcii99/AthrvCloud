//FormAI DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll dice between min and max values
int dice_roll(int min, int max) {
    int result = (rand() % (max - min + 1)) + min;
    return result;
}

int main() {

    int num_rolls, dice_min, dice_max, total = 0;

    // Prompt user for number of rolls, minimum and maximum dice values
    printf("Enter number of rolls: ");
    scanf("%d", &num_rolls);
    printf("Enter minimum dice value: ");
    scanf("%d", &dice_min);
    printf("Enter maximum dice value: ");
    scanf("%d", &dice_max);

    // Set seed for RNG using time
    srand(time(NULL));

    // Loop through number of rolls, rolling dice each time
    for(int i=1; i<=num_rolls; i++) {
        int roll = dice_roll(dice_min, dice_max);
        printf("Roll %d: %d\n", i, roll);
        total += roll;
    }

    // Print total of all rolls
    printf("Total: %d\n", total);

    return 0;
}