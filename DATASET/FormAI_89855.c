//FormAI DATASET v1.0 Category: Physics simulation ; Style: authentic
// This program simulates the motion of a ball thrown at an angle with horizontal.
// It uses the equations of motion to calculate the position and velocity of the ball at each time interval.

#include <stdio.h>
#include <math.h>

#define PI 3.14159265
const float g = 9.8; // acceleration due to gravity (m/s^2)

int main() {
    // Input parameters
    float v0, theta, delta_t;
    printf("Enter initial velocity (m/s): ");
    scanf("%f", &v0);
    printf("Enter angle from horizontal (degrees): ");
    scanf("%f", &theta);
    printf("Enter time step (s): ");
    scanf("%f", &delta_t);
    
    // Convert angle to radians
    theta = theta * PI / 180.0;
    
    // Initial conditions
    float x = 0.0, y = 0.0;
    float v_x = v0 * cos(theta);
    float v_y = v0 * sin(theta);
    
    // Simulation loop
    while (y >= 0.0) {
        // Update position and velocity
        x += v_x * delta_t;
        y += v_y * delta_t - 0.5 * g * delta_t * delta_t;
        v_y -= g * delta_t;
        
        // Print current position
        printf("x = %.2f m, y = %.2f m\n", x, y);
    }
    
    // Final results
    printf("\nTotal distance: %.2f m\n", x);
    printf("Time of flight: %.2f s\n", 2.0 * v0 * sin(theta) / g);
    printf("Maximum height: %.2f m\n", v0 * v0 * sin(theta) * sin(theta) / (2.0 * g));
    
    return 0;
}