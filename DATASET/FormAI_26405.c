//FormAI DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int recursive_robot_movement(int x, int y, int dest_x, int dest_y) {
    // Base cases: robot reaches destination or goes out of bounds
    if (x == dest_x && y == dest_y)
        return 1;
    if (x > dest_x || y > dest_y)
        return 0;
    
    // Recursive cases: robot moves right or down
    int right = recursive_robot_movement(x+1, y, dest_x, dest_y);
    int down = recursive_robot_movement(x, y+1, dest_x, dest_y);
    
    // Return sum of right and down movement paths
    return right + down;
}

int main() {
    // Initialize starting coordinates and destination coordinates
    int start_x = 0, start_y = 0, dest_x = 3, dest_y = 3;
    
    // Calculate possible movement paths
    int paths = recursive_robot_movement(start_x, start_y, dest_x, dest_y);
    
    // Print out result
    printf("Number of possible movement paths: %d\n", paths);
    
    return 0;
}