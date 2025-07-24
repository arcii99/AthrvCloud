//FormAI DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <math.h>

int main() {
    float mass = 1.0; // mass of the object in kg
    float time_step = 0.01; // size of each time step in seconds
    float k = 2.0; // spring constant
    float x = 0.5; // initial displacement of the object

    float velocity = 0.0; // initial velocity of the object
    float acceleration; // acceleration of the object
    float force; // force acting on the object

    printf("Time\tDisplacement\n");

    for(float t = 0.0; t <= 10.0; t += time_step) {
        force = -k*x; // Hooke's Law
        acceleration = force / mass; // Newton's Second Law
        velocity += acceleration * time_step; // Update the velocity
        x += velocity * time_step; // Update the displacement

        printf("%.2f\t%.2f\n", t, x);
    }

    return 0;
}