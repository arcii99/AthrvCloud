//FormAI DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int roll_dice(int num_sides) {
    int roll = rand() % num_sides + 1;
    return roll;
}

// Function to simulate rolling the dice
int simulate_roll(int num_dice, int num_sides) {
    int total_roll = 0;
    for (int i = 0; i < num_dice; i++) {
        total_roll += roll_dice(num_sides);
    }
    return total_roll;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    
    int num_dice, num_sides;
    
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);
    
    printf("How many sides does each die have? ");
    scanf("%d", &num_sides);
    
    int total_roll = simulate_roll(num_dice, num_sides);

    printf("You rolled %d dice, each with %d sides, for a total of %d.\n", num_dice, num_sides, total_roll);
    
    return 0;
}