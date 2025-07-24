//FormAI DATASET v1.0 Category: Physics simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GRAVITY 9.81

int main() {
    double height = 100; // initial height of the object (in meters)
    double velocity = 0; // initial velocity of the object (in meters per second)
    double timeInterval = 0.01; // time interval for simulation (in seconds)
    double time = 0; // initial time (in seconds)
    double massObject = 0.2; // mass of the object (in kilograms)
    double airResistance = 0.25; // air resistance coefficient
    double displacement = 0; // displacement of the object (in meters)
    double acceleration; // acceleration of the object (in meters per second squared)
    printf("Simulation started...\n");
    while(height > 0) {
        acceleration = (massObject * GRAVITY - airResistance * velocity * velocity) / massObject; 
        displacement = velocity*timeInterval + 0.5*acceleration*timeInterval*timeInterval;
        velocity += acceleration * timeInterval;
        height -= displacement;
        time += timeInterval;
        printf("Time %.2f seconds: Height %.2f meters, Velocity %.2f meters/sec\n", time, height, velocity);
    }
    printf("Simulation ended.\n");
    return 0;
}