//FormAI DATASET v1.0 Category: Physics simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    double L = 1.0; // pendulum length
    double g = 9.81; // gravitational acceleration
    double t = 0.0; // current time
    double theta = PI/4; // initial angle
    double omega = 0.0; // initial angular velocity
    double dt = 0.01; // time step

    while (t < 10.0) {
        double alpha = -g/L * sin(theta); // angular acceleration
        omega += alpha * dt; // update angular velocity
        theta += omega * dt; // update angle
        t += dt; // update time

        // print results every 0.1 seconds
        if (fmod(t, 0.1) < dt) {
            printf("t = %f, theta = %f\n", t, theta);
        }
    }

    return 0;
}