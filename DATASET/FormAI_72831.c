//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
#include <stdio.h>
#include <math.h>

int main() {
    // Simulation parameters
    double time_step = 0.01;
    double duration = 10.0;
    
    // Object parameters
    double mass = 1.0;
    double position_x = 0.0;
    double velocity_x = 1.0;
    double acceleration_x = 0.0;
    double force_x = 0.0;
    double displacement_x = 0.0;
    
    // Environment parameters
    double gravity = -9.81;
    double air_resistance = 0.1;
    double pressure = 101325.0; // air pressure in pascals
    double temperature = 293.0; // air temperature in kelvin
    double air_density = pressure / (287.058 * temperature); // air density in kg/m^3
    
    // Simulation loop
    double time = 0.0;
    while (time < duration) {
        // Calculate forces
        force_x = mass * gravity - air_resistance * air_density * pow(velocity_x, 2);
        
        // Calculate acceleration
        acceleration_x = force_x / mass;
        
        // Update velocity
        velocity_x += acceleration_x * time_step;
        
        // Update position
        displacement_x = velocity_x * time_step + 0.5 * acceleration_x * pow(time_step, 2);
        position_x += displacement_x;
        
        // Print position
        printf("Time: %f seconds, Position: %f meters\n", time, position_x);
        
        // Increment time
        time += time_step;
    }
    
    return 0;
}