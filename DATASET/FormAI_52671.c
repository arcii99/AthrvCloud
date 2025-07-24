//FormAI DATASET v1.0 Category: Physics simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double mass = 10.0; // object's mass in kg
    double height = 10.0; // object's initial height in meters
    double velocity = 0.0; // object's initial velocity in m/s
    double acceleration = -9.81; // acceleration due to gravity in m/s^2
    double time = 0.0; // initial time in seconds
    double dt = 0.01; // time step in seconds
    double height_new, velocity_new;

    printf("Starting simulation...\n");
    printf("Object's mass: %f kg\n", mass);
    printf("Object's initial height: %f m\n", height);
    printf("Object's initial velocity: %f m/s\n", velocity);
    printf("Acceleration due to gravity: %f m/s^2\n", acceleration);

    while (height >= 0.0) {
        height_new = height + velocity*dt + 0.5*acceleration*dt*dt;
        velocity_new = velocity + acceleration*dt;

        if (height_new < 0.0) {
            height_new = 0.0;
            velocity_new = -velocity*0.9; // object bounces back with some loss of energy
            acceleration = -9.81; // acceleration due to gravity applies again
            printf("Object has hit the ground and bounced back...\n");
        }

        height = height_new;
        velocity = velocity_new;

        time += dt;

        printf("Height at time %.2f s: %f m\n", time, height);
        printf("Velocity at time %.2f s: %f m/s\n", time, velocity);
    }

    printf("Simulation ended.\n");

    return 0;
}