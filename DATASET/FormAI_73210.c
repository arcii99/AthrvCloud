//FormAI DATASET v1.0 Category: Physics simulation ; Style: mathematical
#include<stdio.h>
#include<math.h>

int main() {
    double time_step = 0.01; // Time step in seconds
    double total_time = 10; // Total simulation time in seconds
    int num_steps = (int)(total_time/time_step);
    
    // Simulation parameters
    double mass = 1; // Mass of the object in kg
    double k = 10; // Spring constant in N/m
    double x_0 = 2; // Initial displacement in meters
    double v_0 = 0; // Initial velocity in m/s

    // Derived variables
    double omega = sqrt(k/mass); // Angular frequency in 1/s
    double T = 2*M_PI/omega; // Time period in s
    
    // Simulation variables
    double x = x_0; // Displacement at time t
    double v = v_0; // Velocity at time t
    
    // Print initial conditions
    printf("Initial conditions:\n");
    printf("Time: t = 0 s\n");
    printf("Displacement: x = %lf m\n", x);
    printf("Velocity: v = %lf m/s\n\n", v);

    // Simulation loop
    for (int i=1; i<=num_steps; i++) {
        // Calculate new position and velocity using Euler's method
        double a = -k*x/mass; // Acceleration at time t
        v += a*time_step;
        x += v*time_step;

        // Print results for every time period
        if (fmod(i*time_step,T) == 0) {
            printf("Time: t = %lf s\n", i*time_step);
            printf("Displacement: x = %lf m\n", x);
            printf("Velocity: v = %lf m/s\n\n", v);
        }
    }
    
    return 0;
}