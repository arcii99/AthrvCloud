//FormAI DATASET v1.0 Category: Dice Roller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

int main() {
    int sides, rolls;
    
    printf("Welcome to the Dice Roller!\n");
    
    // Get user input
    printf("How many sides does your die have? ");
    scanf("%d", &sides);
    printf("How many times would you like to roll? ");
    scanf("%d", &rolls);
    
    // Seed random number generator
    srand(time(0));
    
    // Perform rolls and print results
    for (int i = 1; i <= rolls; i++) {
        int result = rollDice(sides);
        printf("Roll %d: %d\n", i, result);
    }
    
    printf("Thanks for using the Dice Roller!\n");
    return 0;
}