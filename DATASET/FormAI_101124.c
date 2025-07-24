//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

int main() {
    double mass = 10.0; // mass of object in kg
    double force = 50.0; // force exerted on object in N
    double velocity = 0.0; // starting velocity of object in m/s
    double acceleration = force / mass; // acceleration of object in m/s^2
    double time = 0.0; // starting time in seconds
    double distance = 0.0; // starting distance in meters
    double dt = 0.01; // time step in seconds
    
    printf("Time\tDistance\tVelocity\tAcceleration\n");
    
    while (distance < 100.0) { // simulate until object travels 100m
        distance = distance + velocity * dt + 0.5 * acceleration * dt * dt;
        velocity = velocity + acceleration * dt;
        time = time + dt;
        printf("%.2f\t%.2f\t%.2f\t%.2f\n", time, distance, velocity, acceleration);
    }
    
    return 0;
}