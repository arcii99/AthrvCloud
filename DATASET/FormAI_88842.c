//FormAI DATASET v1.0 Category: Robot movement control ; Style: mind-bending
/******************************************************
 *                                                  *
 *  Mind-Bending Robot Movement Control Program      *
 *                                                  *
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed for random number generator
    int movement;
    int position_x = 0;
    int position_y = 0;
    int energy_level = 100;
    int obstacles_passed = 0;
    
    printf("Welcome to the Mind-Bending Robot Movement Control Program!\n");
    printf("You have an energy level of %d and are currently located at position (%d,%d).\n", energy_level, position_x, position_y);
    
    while (energy_level > 0) {
        // Generate random movement
        movement = rand() % 4 + 1;
        
        // Move depending on the generated movement
        switch (movement) {
            case 1: // Move up
                if (position_y < 10) {
                    position_y++;
                    printf("Moved up: (%d,%d)\n", position_x, position_y);
                } else {
                    printf("Cannot move up, obstacle detected. Energy drained 5 points.\n");
                    energy_level -= 5;
                }
                break;
            case 2: // Move down
                if (position_y > 0) {
                    position_y--;
                    printf("Moved down: (%d,%d)\n", position_x, position_y);
                } else {
                    printf("Cannot move down, obstacle detected. Energy drained 5 points.\n");
                    energy_level -= 5;
                }
                break;
            case 3: // Move left
                if (position_x > 0) {
                    position_x--;
                    printf("Moved left: (%d,%d)\n", position_x, position_y);
                } else {
                    printf("Cannot move left, obstacle detected. Energy drained 5 points.\n");
                    energy_level -= 5;
                }
                break;
            case 4: // Move right
                if (position_x < 10) {
                    position_x++;
                    printf("Moved right: (%d,%d)\n", position_x, position_y);
                } else {
                    printf("Cannot move right, obstacle detected. Energy drained 5 points.\n");
                    energy_level -= 5;
                }
                break;
        }
        
        obstacles_passed++; // Increment obstacles passed counter
        
        // Check energy level and print status message
        if (energy_level <= 0) {
            printf("You have run out of energy. Game over. Obstacles passed: %d.\n", obstacles_passed);
        } else if (position_x == 10 && position_y == 10) {
            printf("Congratulations! You have reached your destination at position (10,10). Obstacles passed: %d.\n", obstacles_passed);
            break; // Exit the while loop
        } else {
            printf("Current energy level: %d. Current position: (%d,%d). Obstacles passed: %d.\n", energy_level, position_x, position_y, obstacles_passed);
        }
        
        // Drain energy after each movement
        energy_level--;
    }
    
    return 0;
}