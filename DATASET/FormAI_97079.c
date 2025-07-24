//FormAI DATASET v1.0 Category: Physics simulation ; Style: systematic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    double mass = 10; // Mass in kilograms
    double k = 5; // Spring constant in N/m
    double initialPosition = 0.5; // Initial position in meters
    double initialVelocity = 0; // Initial velocity in m/s
    double timeStep = 0.01; // Time step in seconds
    double time = 0; // Current time in seconds
    double position = initialPosition; // Current position in meters
    double velocity = initialVelocity; // Current velocity in m/s
    double amplitude = 1.5; // Amplitude of the driving force in N
    
    while (time < 10) { // Simulation time of 10 seconds
        double acceleration = (-k * position) / mass; // Calculate acceleration using Hooke's law
        acceleration += amplitude * sin(2 * PI * time); // Add driving force acceleration
        
        position += velocity * timeStep; // Update position using current velocity
        velocity += acceleration * timeStep; // Update velocity using current acceleration
        time += timeStep; // Increment time
        
        printf("Time: %f sec, Position: %f m, Velocity: %f m/s, Acceleration: %f m/s^2\n",
               time, position, velocity, acceleration); // Print results
    }
    
    return 0;
}