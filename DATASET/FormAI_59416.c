//FormAI DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>

#define PI 3.14159 // Define PI value

typedef struct {
    double x;
    double y;
    double theta;
} Position;

double rad2deg(double rad) {
    return rad * (180 / PI);
}

double deg2rad(double deg) {
    return deg * (PI / 180);
}

double calculate_distance(double x1, double y1, double x2, double y2) {
    double x_diff = x2 - x1;
    double y_diff = y2 - y1;
    double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
    return distance;
}

double calculate_angle(double x1, double y1, double x2, double y2) {
    double x_diff = x2 - x1;
    double y_diff = y2 - y1;
    double angle = atan2(y_diff, x_diff);
    angle = rad2deg(angle);
    if (angle < 0) {
        angle += 360; // Normalize angle to positive value
    }
    return angle;
}

void move_robot(Position *current_position, double distance, double angle) {
    double angle_rad = deg2rad(angle);
    double new_x = current_position->x + distance * cos(angle_rad);
    double new_y = current_position->y + distance * sin(angle_rad);
    current_position->x = new_x;
    current_position->y = new_y;
    current_position->theta = angle;
}

int main() {
    Position robot_position = {0, 0, 0};
    printf("Robot position: %.2lf, %.2lf, %.2lf\n",
            robot_position.x, robot_position.y, robot_position.theta);
    
    double distance = calculate_distance(0, 0, 5, 5);
    double angle = calculate_angle(0, 0, 5, 5);
    printf("Moving robot %lf units at %lf degree angle\n", distance, angle);
    move_robot(&robot_position, distance, angle);
    printf("Robot position after move: %.2lf, %.2lf, %.2lf\n",
            robot_position.x, robot_position.y, robot_position.theta);
    
    distance = calculate_distance(robot_position.x, robot_position.y, 3, 7);
    angle = calculate_angle(robot_position.x, robot_position.y, 3, 7);
    printf("Moving robot %lf units at %lf degree angle\n", distance, angle);
    move_robot(&robot_position, distance, angle);
    printf("Robot position after move: %.2lf, %.2lf, %.2lf\n",
            robot_position.x, robot_position.y, robot_position.theta);
    
    return 0;
}