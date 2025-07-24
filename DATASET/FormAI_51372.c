//FormAI DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

void treasureHunt(int steps, int x, int y) {
    if (steps == 0) {
        return;
    }
    
    // Move north
    printf("Moving north for %d steps\n", steps);
    treasureHunt(steps - 1, x, y + 1);
    
    // Move west
    printf("Moving west for %d steps\n", steps);
    treasureHunt(steps - 1, x - 1, y);
    
    // Move south
    printf("Moving south for %d steps\n", steps);
    treasureHunt(steps - 1, x, y - 1);
    
    // Move east
    printf("Moving east for %d steps\n", steps);
    treasureHunt(steps - 1, x + 1, y);
}

int main() {
    // Welcome the player
    printf("Welcome, adventurer! Your mission is to find the treasure. But beware, the path is long and twisted...\n");
    
    // Ask for number of steps
    int steps;
    printf("How many steps will you take?\n");
    scanf("%d", &steps);
    
    // Start the treasure hunt
    printf("\nLet the treasure hunt begin!\n");
    treasureHunt(steps, 0, 0);
    
    // Congratulate the player
    printf("\nCongratulations! You have found the treasure. Your journey may have been long and difficult, but you persevered and succeeded.\n");
    
    return 0;
}