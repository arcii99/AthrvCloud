//FormAI DATASET v1.0 Category: Physics simulation ; Style: happy
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Define constants for simulation
#define G 9.81 // gravitational constant
#define DT 0.1 // time step
#define NUM_STEPS 100 // number of simulation steps

int main() {
    // Declare variables
    float pos = 10.0; // starting position
    float vel = 0.0; // starting velocity
    
    // Set seed for random number generation
    srand(time(0));
    
    // Loop through simulation steps
    for (int i = 0; i < NUM_STEPS; i++) {
        // Calculate resulting force
        float force = -G * sin(pos);
        
        // Add random force component
        force += ((float)rand() / RAND_MAX) - 0.5;
        
        // Calculate resulting acceleration
        float accel = force;
        
        // Update velocity and position
        vel += accel * DT;
        pos += vel * DT;
        
        // Output current position
        printf("Step %d: Position = %f\n", i+1, pos);
    }
    
    // Finish simulation
    printf("Simulation complete!\n");
    return 0;
}