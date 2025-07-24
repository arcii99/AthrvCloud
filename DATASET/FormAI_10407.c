//FormAI DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    double time = 0.0;  // time elapsed
    double dt = 0.01;   // time step
    double mass = 2.0;  // mass of the object
    double init_vel = 0.0;  // initial velocity of the object
    double force = 10.0;  // applied force
    double pos = 0.0;   // position of the object
    double vel = init_vel;  // velocity of the object

    // simulate the motion of the object using Euler's method
    while (time < 10.0) {
        // calculate acceleration from F=ma
        double accel = force / mass;

        // update velocity and position
        vel += accel * dt;
        pos += vel * dt;

        time += dt;

        // print the position at every second
        if (fmod(time, 1.0) < dt) {
            printf("Position at t=%f: %f\n", time, pos);
        }
    }

    return 0;
}