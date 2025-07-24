//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int num_dice, num_sides;
    srand(time(NULL)); // initializing random number generator

    printf("Welcome to the Dice Roller program!\n");
    printf("Enter number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter number of sides on each die: ");
    scanf("%d", &num_sides);

    int rolls[num_dice]; // array to store roll results
    printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = rand() % num_sides + 1; // generating random roll for each die
        printf("Die %d: %d\n", i+1, rolls[i]); // displaying roll result
    }

    // calculating and displaying sum of all rolls
    int sum = 0;
    for (int i = 0; i < num_dice; i++) {
        sum += rolls[i];
    }
    printf("Total sum: %d\n", sum);

    return 0;
}