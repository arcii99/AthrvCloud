//FormAI DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    int num_rolls = 0;
    int num_sides = 0;
    int total = 0;
    int roll = 0;
    
    printf("Welcome to the Paranoid Dice Roller!\n");
    printf("Please enter the number of sides on the die (must be a positive integer): ");
    scanf("%d", &num_sides);
    while (num_sides <= 0) {
        printf("Invalid input, please enter a positive integer: ");
        scanf("%d", &num_sides);
    }
    
    printf("Please enter the number of rolls you'd like to make (must be a positive integer): ");
    scanf("%d", &num_rolls);
    while (num_rolls <= 0) {
        printf("Invalid input, please enter a positive integer: ");
        scanf("%d", &num_rolls);
    }
    
    printf("Rolling %d %d-sided dice...\n", num_rolls, num_sides);
    
    for (int i = 0; i < num_rolls; i++) {
        roll = (rand() % num_sides) + 1; // generate a random number between 1 and num_sides
        total += roll;
        
        if (roll <= 0) {
            printf("WARNING: Critical system error. Dice roll value below 1. Shutting down...\n");
            exit(1);
        } else if (roll > num_sides) {
            printf("WARNING: Critical system error. Dice roll value exceeds number of sides. Shutting down...\n");
            exit(1);
        }
        
        printf("Roll %d: %d\n", i+1, roll);
    }
    
    printf("Total: %d\n", total);
    printf("Thank you for using the Paranoid Dice Roller!\n");
    return 0;
}