//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_of_dice, num_of_sides, sum = 0;
    printf("Enter the number of dice: ");
    scanf("%d", &num_of_dice);
    printf("Enter the number of sides per die: ");
    scanf("%d", &num_of_sides);

    // Set the random seed
    srand(time(0));

    printf("\nRolling %d %d-sided dice...\n\n", num_of_dice, num_of_sides);

    for (int i = 0; i < num_of_dice; i++) {
        int roll = (rand() % num_of_sides) + 1;
        sum += roll;
        printf("Die %d rolls: %d\n", i+1, roll);
    }

    printf("\nSum of all rolls: %d\n", sum);
    return 0;
}