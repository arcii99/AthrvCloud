//FormAI DATASET v1.0 Category: Dice Roller ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_rolls, num_sides, total = 0;
    srand(time(NULL)); // Seed random number generator with current time
    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &num_sides);

    for (int i = 0; i < num_rolls; i++) {
        int roll = rand() % num_sides + 1; // Generate random number between 1 and num_sides
        printf("Roll %d: %d\n", i+1, roll);
        total += roll;
    }

    printf("Total: %d\n", total);
    return 0;
}