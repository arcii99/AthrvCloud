//FormAI DATASET v1.0 Category: Physics simulation ; Style: modular
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81    // Acceleration due to gravity in m/s^2

float calc_time_of_flight (float h_i, float h_f) {
    // Calculates the time of flight of a projectile from initial height h_i to final height h_f
    float time;
    time = sqrt(2*(h_i-h_f)/GRAVITY);
    return time;
}

float calc_horizontal_range (float v_i, float theta) {
    // Calculates the horizontal range of a projectile given initial velocity v_i and launch angle theta
    float range;
    range = (v_i*v_i*sin(2*theta))/GRAVITY;
    return range;
}

int main() {
    float init_height, final_height, init_vel, launch_angle;
    float time_of_flight, horizontal_range;
    printf("Enter the initial height of the projectile (m): ");
    scanf("%f", &init_height);
    printf("Enter the final height of the projectile (m): ");
    scanf("%f", &final_height);
    printf("Enter the initial velocity of the projectile (m/s): ");
    scanf("%f", &init_vel);
    printf("Enter the launch angle of the projectile (degrees): ");
    scanf("%f", &launch_angle);

    float theta = launch_angle * (M_PI/180); // Convert launch angle to radians

    time_of_flight = calc_time_of_flight(init_height, final_height);
    horizontal_range = calc_horizontal_range(init_vel, theta);

    printf("The time of flight is %f seconds.\n", time_of_flight);
    printf("The horizontal range is %f meters.\n", horizontal_range);

    return 0;
}