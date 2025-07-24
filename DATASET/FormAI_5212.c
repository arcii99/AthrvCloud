//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

int main() {
    float m = 5; // mass of the object
    float x = 0; // initial position of the object
    float v = 10; // initial velocity of the object
    float k = 3; // spring constant of the spring
    float b = 2; // damping coefficient of the system
    float t = 0; // current time
    float dt = 0.01; // time step
    float a, f_spring, f_damping;
    int i;

    printf("Time\tPosition\tVelocity\n"); // print table header

    for (i = 0; i < 1000; i++) { // simulation loop
        f_spring = -k * x; // spring force
        f_damping = -b * v; // damping force
        a = (f_spring + f_damping) / m; // acceleration
        x += v * dt; // update position
        v += a * dt; // update velocity
        t += dt; // update time

        printf("%.2f\t%.2f\t\t%.2f\n", t, x, v); // print data row
    }

    return 0;
}