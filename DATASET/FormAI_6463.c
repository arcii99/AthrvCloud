//FormAI DATASET v1.0 Category: Physics simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define DELTA_T 0.01   // Time step size for simulation
#define G 9.81         // Acceleration due to gravity

int main() {
    double x1, x2, v1, v2, m1, m2, f1, f2, a1, a2, r, d;   // Variables for simulation
    
    // Ask user to input initial conditions
    printf("Enter initial position of first object: ");
    scanf("%lf", &x1);
    printf("Enter initial position of second object: ");
    scanf("%lf", &x2);
    printf("Enter initial speed of first object: ");
    scanf("%lf", &v1);
    printf("Enter initial speed of second object: ");
    scanf("%lf", &v2);
    printf("Enter mass of first object: ");
    scanf("%lf", &m1);
    printf("Enter mass of second object: ");
    scanf("%lf", &m2);
    printf("Enter distance between objects: ");
    scanf("%lf", &d);
    
    // Initialize forces, acceleration, and time
    f1 = -G * m1 * m2 / pow(d, 2);
    f2 = -f1;
    a1 = f1 / m1;
    a2 = f2 / m2;
    double t = 0;
    
    // Run simulation for 10 seconds
    while (t < 10) {
        // Update positions
        x1 += v1 * DELTA_T + 0.5 * a1 * DELTA_T * DELTA_T;
        x2 += v2 * DELTA_T + 0.5 * a2 * DELTA_T * DELTA_T;
        
        // Calculate new distance and force between objects
        r = x2 - x1;
        f1 = -G * m1 * m2 / pow(r, 2);
        f2 = -f1;
        
        // Update accelerations using new forces
        a1 = f1 / m1;
        a2 = f2 / m2;
        
        // Update velocities
        v1 += a1 * DELTA_T;
        v2 += a2 * DELTA_T;
        
        // Print current positions and time
        printf("Position of first object at time=%.2f: %.2f\n", t, x1);
        printf("Position of second object at time=%.2f: %.2f\n", t, x2);
        printf("-----------------------------\n");
        
        // Increment time
        t += DELTA_T;
    }
    
    return 0;
}