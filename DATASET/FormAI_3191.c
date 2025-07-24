//FormAI DATASET v1.0 Category: Physics simulation ; Style: high level of detail
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81    // gravitational constant
#define TIMESTEP 0.1    // time step

int main() {
    double initial_velocity = 10.0;    // initial velocity of projectile
    double angle = 45.0;               // angle of projection in degrees
    double position_x = 0.0, position_y = 0.0;  // initial position of projectile
    double velocity_x = initial_velocity * cos(angle * M_PI / 180.0);  // initial velocity in x-direction
    double velocity_y = initial_velocity * sin(angle * M_PI / 180.0);  // initial velocity in y-direction
    double acceleration_x = 0.0, acceleration_y = -GRAVITY;   // constant acceleration in y-direction due to gravity
    double time = 0.0;

    while (position_y >= 0) {   // loop until projectile hits the ground
        printf("time=%.2f x=%.2f y=%.2f\n", time, position_x, position_y);

        // update position
        position_x += velocity_x * TIMESTEP;
        position_y += velocity_y * TIMESTEP;

        // update velocity
        velocity_x += acceleration_x * TIMESTEP;
        velocity_y += acceleration_y * TIMESTEP;

        // update time
        time += TIMESTEP;
    }

    printf("time=%.2f x=%.2f y=%.2f\n", time, position_x, position_y);
    printf("Projectile hit the ground at time %.2f seconds, at position (%.2f, %.2f)\n", time, position_x, position_y);

    return 0;
}