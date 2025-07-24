//FormAI DATASET v1.0 Category: Physics simulation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

#define G 9.8 // gravitational constant
#define DT 0.1 // time step
#define MAX_STEP 1000 // maximum number of simulation steps

int main(void) {
    double h, v, a; // height, velocity, acceleration
    int t, i; // time, loop index

    // initialize variables
    h = 10.0; // initial height in meters
    v = 0.0; // initial velocity in m/s
    a = -G; // initial acceleration in m/s^2
    t = 0;

    // simulate motion
    for (i = 0; i < MAX_STEP; i++) {
        printf("t = %d, h = %.2f m, v = %.2f m/s\n", t, h, v);
        h += v * DT + 0.5 * a * DT * DT; // update height
        v += a * DT; // update velocity
        t++; // increment time
        if (h < 0) {
            break; // stop simulation if ball hits the ground
        }
    }

    return 0;
}