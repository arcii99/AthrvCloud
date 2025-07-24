//FormAI DATASET v1.0 Category: Physics simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.81 // m/s^2
#define DT 0.1 // time step
#define L 1.0 // length of pendulum

int main() {
    double theta = M_PI / 4; // initial angle in radians
    double omega = 0.0; // initial angular velocity
    double alpha; // angular acceleration
    double t = 0.0; // time
    double x, y; // position of pendulum bob
    FILE *output; // file to write output to
    
    output = fopen("pendulum.dat", "w");
    
    for (int i = 0; i < 100; i++) {
        alpha = - (GRAVITY / L) * sin(theta); // calculate angular acceleration
        omega += alpha * DT; // calculate new angular velocity
        theta += omega * DT; // calculate new angle
        x = L * sin(theta); // calculate x position of bob
        y = -L * cos(theta); // calculate y position of bob
        fprintf(output, "%.2f %.2f\n", x, y); // write position to file
        t += DT; // increment time
    }
    
    fclose(output); // close output file
    
    return 0;
}