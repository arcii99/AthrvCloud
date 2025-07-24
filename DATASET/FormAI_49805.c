//FormAI DATASET v1.0 Category: Physics simulation ; Style: satisfied
#include <stdio.h>
#include <math.h>

int main() {
    // Defining constants
    const float mass = 1.0; // kg
    const float springConst = 10.0; // N/m
    const float frictionConst = 0.50; // Ns/m
    
    // Defining initial conditions
    float x = 0.10; // m - initial displacement from equilibrium position
    float v = 0.0; // m/s - initial velocity
    
    // Defining time step and total time
    const float dt = 0.001; // s - time step
    const float totalTime = 10.0; // s
    
    // Defining variables
    float t = 0.0; // s - current time
    float a = 0.0; // m/s^2 - acceleration
    float vNew = 0.0; // m/s - updated velocity
    float xNew = 0.0; // m - updated displacement
    
    // Simulation loop
    while (t <= totalTime) {
        // Calculating acceleration using Hook's Law and damping force
        float fSpring = -springConst * x;
        float fFriction = -frictionConst * v;
        a = (fSpring + fFriction) / mass;
        
        // Updating velocity and displacement
        vNew = v + a * dt;
        xNew = x + vNew * dt;
        
        // Updating variables for next iteration
        v = vNew;
        x = xNew;
        t += dt;
        
        // Printing current time, displacement, and velocity
        printf("t = %.3f s, x = %.3f m, v = %.3f m/s\n", t, x, v);
    }
    
    return 0;
}