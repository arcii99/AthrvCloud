//FormAI DATASET v1.0 Category: Physics simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int n = 5; // number of pendulums
    double dt = 0.01; // time step in seconds
    double g = 9.81; // acceleration due to gravity in m/s^2
    double l = 1.0; // length of the pendulums in meters
    double theta[n], omega[n], alpha[n]; // initialize arrays for theta, omega, and alpha for each pendulum
    double t = 0.0; // initialize time
    
    // initialize the starting values for theta and omega for each pendulum
    for (int i = 0; i < n; i++) {
        theta[i] = ((double)i + 1) * PI / (double)n;
        omega[i] = 0.0;
    }
    
    // simulate the motion of the pendulums
    while (1) {
        // calculate the alpha (angular acceleration) for each pendulum
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                sum += sin(theta[j] - theta[i]);
            }
            alpha[i] = -(g / l) * sin(theta[i]) - (1 / l) * sum;
        }
        
        // update the values of theta and omega for each pendulum using the time step and new alpha values
        for (int i = 0; i < n; i++) {
            theta[i] += omega[i] * dt;
            omega[i] += alpha[i] * dt;
        }
        
        // print out the current values of theta for each pendulum
        printf("t = %f", t);
        for (int i = 0; i < n; i++) {
            printf("\ttheta%d = %f", i+1, theta[i]);
        }
        printf("\n");
        
        // increment time
        t += dt;
    }
    
    return 0;
}