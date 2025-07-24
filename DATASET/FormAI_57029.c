//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

int main(void) {
    // Define variables
    double time = 0.0;
    double theta = 0.1;
    double omega = 0.0;
    double alpha = 0.0;
    double g = 9.81;
    double l = 1.0;
    double dt = 0.01;
  
    while (time <= 10.0) {
        // Calculate acceleration and update theta and omega
        alpha = -g/l * sin(theta);
        omega += alpha * dt;
        theta += omega * dt;
        
        // Print theta and time
        printf("theta = %lf, time = %lf\n", theta, time);
        
        // Update time
        time += dt;
    }
  
    return 0;
}