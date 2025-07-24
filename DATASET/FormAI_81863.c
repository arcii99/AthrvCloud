//FormAI DATASET v1.0 Category: Physics simulation ; Style: active
#include <stdio.h>
#include <math.h>

int main() {
    // Simulation constants
    const double initial_velocity = 20.0;
    const double mass = 10.0;
    const double air_resistance = 0.1;
    const double time_step = 0.05;
    const int num_steps = 100;

    // Initial state
    double position = 0.0;
    double velocity = initial_velocity;

    // Simulation loop
    for (int i = 0; i < num_steps; i++) {
        // Calculate forces
        double gravity = mass * 9.81;
        double drag = -air_resistance * velocity * fabs(velocity);
        double net_force = gravity + drag;
        
        // Update position and velocity
        double acceleration = net_force / mass;
        position += velocity * time_step + 0.5 * acceleration * time_step * time_step;
        velocity += acceleration * time_step;
        
        // Print current state
        printf("Time: %f, Position: %f, Velocity: %f\n", i * time_step, position, velocity);
    }
    
    return 0;
}