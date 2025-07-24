//FormAI DATASET v1.0 Category: Robot movement control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define structure of robot's position
struct Position {
    double x;
    double y;
    double theta; // in radians
};

// Define robot's movement function
void move(struct Position* pos, double distance, double angle) {
    // Update x and y position
    pos->x += distance * cos(pos->theta + angle);
    pos->y += distance * sin(pos->theta + angle);
    // Update robot's orientation
    pos->theta += angle;
    // Keep theta within range of 0 to 2*pi
    if (pos->theta < 0) {
        pos->theta += 2 * PI;
    } else if (pos->theta > 2 * PI) {
        pos->theta -= 2 * PI;
    }
}

int main() {
    // Initialize robot's position
    struct Position pos = {0, 0, 0}; // at (0, 0) facing east
    // Move robot forward 1 unit
    move(&pos, 1, 0);
    // Move robot forward 0.5 units and turn 60 degrees to the left
    move(&pos, 0.5, -PI/3);
    // Move robot forward 0.5 units and turn 60 degrees to the right
    move(&pos, 0.5, PI/3);
    // Move robot forward 1 unit and turn 45 degrees to the left
    move(&pos, 1, -PI/4);

    // Print the final position and orientation of the robot
    printf("Robot's final position: (%lf, %lf)\n", pos.x, pos.y);
    printf("Robot's final orientation: %lf radians\n", pos.theta);

    return 0;
}