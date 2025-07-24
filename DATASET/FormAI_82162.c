//FormAI DATASET v1.0 Category: Robot movement control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set up robot variables
    int x_pos = 0;
    int y_pos = 0;
    int speed = 10;
    
    // Prompt the user for movement instructions
    printf("How far should the robot move forward? ");
    int distance;
    scanf("%d", &distance);
    printf("And how far to the left or right? ");
    int direction;
    scanf("%d", &direction);
    
    // Calculate the new position of the robot
    x_pos += distance * speed;
    y_pos += direction * speed;
    
    // Check if the robot will hit a wall
    if (x_pos > 100 || x_pos < -100 || y_pos > 100 || y_pos < -100) {
        printf("WARNING: Robot will hit a wall!\n");
    }
    
    // Print the new position of the robot
    printf("The robot has moved %d units forward and %d units to the %s.\n", distance, abs(direction), (direction < 0 ? "left" : "right"));
    printf("New position: (%d, %d)\n", x_pos, y_pos);
    
    return 0;
}