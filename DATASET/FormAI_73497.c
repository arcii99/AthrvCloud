//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    double mass = 10.0; // mass of the object in kg
    double velocity = 2.0; // initial velocity in meters per second
    double acceleration = 0.0; // acceleration in meters per second squared
    double time = 0.0; // time in seconds
    double time_step = 0.01; // time step size in seconds
    double displacement = 0.0; // displacement in meters
    double force = 0.0; // force in newtons
    double position = 0.0; // position in meters

    // apply a constant force of 5 newtons in the positive x-direction
    force = 5.0;

    while (time < 10.0) // simulate for 10 seconds
    {
        // calculate acceleration using F = ma
        acceleration = force / mass;

        // calculate new velocity using a = dv/dt
        velocity = velocity + acceleration * time_step;

        // calculate new displacement using v = dx/dt
        displacement = velocity * time_step;

        // calculate new position
        position = position + displacement;

        // print out current time and position
        printf("time: %lf position: %lf\n", time, position);

        // update time
        time = time + time_step;
    }

    return 0;
}