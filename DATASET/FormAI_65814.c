//FormAI DATASET v1.0 Category: Physics simulation ; Style: multivariable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    double initial_angle_x = 45;
    double initial_angle_y = 60;
    double initial_velocity = 10;
    double acceleration_x = 0;
    double acceleration_y = 9.81;
    double time_step = 0.1;
    
    double current_time = 0;
    double current_position_x = 0;
    double current_position_y = 0;
    double current_velocity_x = initial_velocity * cos(initial_angle_x * PI / 180);
    double current_velocity_y = initial_velocity * sin(initial_angle_y * PI / 180);
    
    int i;
    for (i = 0; i < 50; i++) {
        printf("Time: %lf Position: (%lf, %lf) Velocity: (%lf, %lf)\n",
               current_time, current_position_x, current_position_y, current_velocity_x, current_velocity_y);
        
        current_position_x += current_velocity_x * time_step;
        current_position_y += current_velocity_y * time_step;
        current_velocity_x += acceleration_x * time_step;
        current_velocity_y += acceleration_y * time_step;
        current_time += time_step;
    }
    
    return 0;
}