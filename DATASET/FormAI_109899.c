//FormAI DATASET v1.0 Category: Physics simulation ; Style: accurate
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    double velocity = 0.0;
    double angle = 0.0;

    printf("Welcome to the projectile motion simulator!\n\n");

    printf("Please enter the initial velocity (in meters/second): ");
    scanf("%lf", &velocity);

    printf("Please enter the angle of the projectile (in degrees): ");
    scanf("%lf", &angle);

    double radians = angle * (PI / 180.0); // conversion to radians
    double initial_velocity_x = velocity * cos(radians);
    double initial_velocity_y = velocity * sin(radians);

    double acceleration_x = 0.0;
    double acceleration_y = -9.81;

    double time = 0.0;
    double time_step = 0.01; // 10 ms

    double position_x = 0.0;
    double position_y = 0.0;

    printf("\n\n--------------------------------------------\n");
    printf("Time (seconds)\tPosition (meters)\n");
    printf("--------------------------------------------\n");

    while (position_y >= 0) {
        position_x = initial_velocity_x * time + 0.5 * acceleration_x * pow(time, 2);
        position_y = initial_velocity_y * time + 0.5 * acceleration_y * pow(time, 2);
        
        printf("%-.2lf\t\t%-.2lf\n", time, position_y);

        time += time_step;
    }

    printf("\nThe projectile has landed after %.2lf seconds.\n", time);

    return 0;
}