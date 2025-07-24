//FormAI DATASET v1.0 Category: Robot movement control ; Style: beginner-friendly
#include <stdio.h>

// Robot position struct
struct position {
    int x;
    int y;
};

// Function to move the robot
void moveRobot(struct position *pos, int x_move, int y_move) {
    pos->x += x_move;
    pos->y += y_move;
}

int main() {
    // Initialize the robot's starting position
    struct position robot_pos = {0, 0};
    
    // Move the robot forward
    moveRobot(&robot_pos, 0, 1);
    printf("Robot moved to position (%d, %d)\n", robot_pos.x, robot_pos.y);
    
    // Move the robot left
    moveRobot(&robot_pos, -1, 0);
    printf("Robot moved to position (%d, %d)\n", robot_pos.x, robot_pos.y);
    
    // Move the robot diagonally
    moveRobot(&robot_pos, 1, -1);
    printf("Robot moved to position (%d, %d)\n", robot_pos.x, robot_pos.y);
    
    return 0;
}