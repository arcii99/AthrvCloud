//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_PLANETS 10

int main()
{
    // declaring variables
    double x[MAX_PLANETS], y[MAX_PLANETS], vx[MAX_PLANETS], vy[MAX_PLANETS],
    fx[MAX_PLANETS], fy[MAX_PLANETS], m[MAX_PLANETS], r[MAX_PLANETS];

    int i, j, n = 0;
    double t, dt = 0.01, G = 1;

    // initializing the planets
    // planet format: x, y, vx, vy, fx, fy, mass, radius
    x[0] = 0; y[0] = 0; vx[0] = 0; vy[0] = 0; fx[0] = 0; fy[0] = 0; m[0] = 1000; r[0] = 10;
    x[1] = 500; y[1] = 0; vx[1] = 0; vy[1] = 20; fx[1] = 0; fy[1] = 0; m[1] = 1; r[1] = 1;
    x[2] = -750; y[2] = -750; vx[2] = 5; vy[2] = 5; fx[2] = 0; fy[2] = 0; m[2] = 10; r[2] = 5;
    n = 3;

    // starting the simulation loop
    for (t = 0; t < 1000; t += dt) {
        // resetting the forces on the planets
        for (i = 0; i < n; i++) {
            fx[i] = 0;
            fy[i] = 0;
        }

        // calculating the forces between planets
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i != j) {
                    double dx = x[j] - x[i];
                    double dy = y[j] - y[i];
                    double d = sqrt(dx*dx + dy*dy);
                    double f = G*m[i]*m[j]/(d*d);
                    fx[i] += f*dx/d;
                    fy[i] += f*dy/d;
                }
            }
        }

        // updating the velocity and position of the planets
        for (i = 0; i < n; i++) {
            vx[i] += fx[i]/m[i]*dt;
            vy[i] += fy[i]/m[i]*dt;
            x[i] += vx[i]*dt;
            y[i] += vy[i]*dt;
        }

        // printing the positions of the planets
        printf("t = %lf\n", t);
        for (i = 0; i < n; i++) {
            printf("Planet %d: x = %lf, y = %lf\n", i+1, x[i], y[i]);
        }
        printf("\n");
    }

    // ending the program
    return 0;
}