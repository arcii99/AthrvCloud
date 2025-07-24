//FormAI DATASET v1.0 Category: Physics simulation ; Style: secure
#include <stdio.h>
#include <math.h>

/* This program simulates the motion of a pendulum using the Euler-Cromer method. */

int main() {
    double L = 1.0; // length of pendulum
    double g = 9.81; // acceleration due to gravity
    double dt = 0.01; // time step
    double t = 0.0; // current time
    double theta = 0.2; // initial angle
    double omega = 0.0; // initial angular velocity
    
    FILE* fp = fopen("pendulum.txt", "w"); // create file to store output data
    
    fprintf(fp, "time angle\n");
    
    while (t < 10.0) { // run simulation for 10 seconds
        double alpha = (-g / L) * sin(theta); // calculate angular acceleration

        omega += alpha * dt; // update angular velocity
        theta += omega * dt; // update angle
        
        fprintf(fp, "%lf %lf\n", t, theta); // write time and angle data to file
        
        t += dt; // increment time
    }
    
    fclose(fp); // close file
    
    return 0;
}