//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float x, y, v_x, v_y, a_x, a_y, t, dt;
    float F_x, F_y, m, ke, u;

    m = 2.0; //mass of the object
    u = 0.7; //coefficient of friction
    ke = 0.5 * m * (pow(v_x, 2) + pow(v_y, 2)); //kinetic energy
    x = y = 0.0; //initial position
    v_x = 10.0; //initial horizontal velocity
    v_y = 5.0; //initial vertical velocity
    a_x = 0.0; //no horizontal acceleration
    a_y = -9.8; //acceleration due to gravity
    t = 0.0; //initial time
    dt = 0.1; //time step

    printf("Time (s)\tX Position (m)\tY Position (m)\tX Velocity (m/s)\tY Velocity (m/s)\n");

    while(y >= 0.0) {
        F_x = -u * m * (v_x / fabs(v_x)); //force due to friction in the x direction
        F_y = m * a_y; //force due to gravity in the y direction
        v_x += (F_x / m) * dt; //update velocity in the x direction
        v_y += (F_y / m) * dt; //update velocity in the y direction
        x += v_x * dt; //update position in the x direction
        y += v_y * dt; //update position in the y direction
        t += dt; //update time
        printf("%f\t%f\t%f\t%f\t%f\n", t, x, y, v_x, v_y);
    }

    printf("\nTotal distance traveled: %f meters\n", x);

    return 0;
}