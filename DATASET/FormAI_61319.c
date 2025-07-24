//FormAI DATASET v1.0 Category: Dice Roller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Claude Shannon Dice Roller!\n");
    printf("Enter the number of dice you want to roll: ");
    int num_dice;
    scanf("%d", &num_dice);
    printf("Enter the number of sides each dice should have: ");
    int num_sides;
    scanf("%d", &num_sides);
    srand(time(NULL)); // Initialize random number generator
    printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);
    int total = 0;
    for (int i = 1; i <= num_dice; i++) {
        int roll = rand() % num_sides + 1; // Generate random roll between 1 and num_sides
        printf("Dice %d: %d\n", i, roll);
        total += roll; // Add roll to total
    }
    printf("Total: %d\n", total); // Print total
    return 0;
}