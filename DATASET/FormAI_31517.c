//FormAI DATASET v1.0 Category: Physics simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

#define TIME_STEP 0.01 // seconds
#define SIMULATION_TIME 10.0 // seconds

#define MASS 10.0 // kg
#define SPRING_CONSTANT 100.0 // N/m
#define EQUILIBRIUM_LENGTH 1.0 // m

#define GRAVITY 9.81 // m/s^2

int main() {

    double time = 0.0; // seconds
    double position = EQUILIBRIUM_LENGTH; // m
    double velocity = 0.0; // m/s
    double acceleration = 0.0; // m/s^2
    
    while (time <= SIMULATION_TIME) {
        
        double force_spring = -SPRING_CONSTANT * (position - EQUILIBRIUM_LENGTH);
        double force_gravity = MASS * GRAVITY;
        double force_total = force_spring + force_gravity;
        
        acceleration = force_total / MASS;
        velocity += acceleration * TIME_STEP;
        position += velocity * TIME_STEP;
        
        printf("Time: %.2lf s, Position: %.4lf m, Velocity: %.4lf m/s, Acceleration: %.4lf m/s^2\n", time, position, velocity, acceleration);
        
        time += TIME_STEP;
    }
    
    return 0;
}