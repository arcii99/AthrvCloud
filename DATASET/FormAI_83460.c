//FormAI DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STEPS 100
#define MIN_STEP_SIZE 1e-5

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    double x;
    double y;
} Vector;

Point robot_position = {0, 0};
Vector robot_direction = {1, 0};
double robot_speed = 10;

void move_forward(double distance) {
    Vector movement = {distance * robot_direction.x, distance * robot_direction.y};
    robot_position.x += (int) round(movement.x);
    robot_position.y += (int) round(movement.y);
}

void turn(double angle) {
    double cos_theta = cos(angle);
    double sin_theta = sin(angle);
    double new_x = robot_direction.x * cos_theta - robot_direction.y * sin_theta;
    double new_y = robot_direction.x * sin_theta + robot_direction.y * cos_theta;
    robot_direction.x = new_x;
    robot_direction.y = new_y;
}

int main() {
    int target_x = 100;
    int target_y = 200;
    
    Vector to_target = {target_x - robot_position.x, target_y - robot_position.y};
    double distance_to_target = sqrt(to_target.x * to_target.x + to_target.y * to_target.y);
    int step_num = 0;
    double step_size = distance_to_target / MAX_STEPS;
    
    while (distance_to_target > 0 && step_num++ < MAX_STEPS) {
        double distance_to_move = fmin(step_size, distance_to_target);
        move_forward(distance_to_move);
        
        Vector to_target_new = {target_x - robot_position.x, target_y - robot_position.y};
        double dot_product = to_target.x * to_target_new.x + to_target.y * to_target_new.y;
        double cross_product = to_target.x * to_target_new.y - to_target.y * to_target_new.x;
        double angle_to_turn = atan2(cross_product, dot_product);
        turn(angle_to_turn);
        
        distance_to_target = sqrt(to_target_new.x * to_target_new.x + to_target_new.y * to_target_new.y);
        to_target = to_target_new;
    }
    
    if (distance_to_target > MIN_STEP_SIZE) {
        printf("Error: failed to reach target.\n");
        return 1;
    }
    
    printf("Target reached!\n");
    
    return 0;
}