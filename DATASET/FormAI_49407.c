//FormAI DATASET v1.0 Category: Physics simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double x, y, z, vx, vy, vz;
    double dt, t, m, k, r, F, xs, ys, zs, fx, fy, fz;
    int i, n;

    m = 1.0; // mass of particle
    k = 1.0; // spring constant

    // initial position and velocity of particle
    x = 0.0;
    y = 0.1;
    z = 0.0;
    vx = 0.0;
    vy = 0.0;
    vz = 0.0;

    // simulation parameters
    dt = 0.001; // time step
    n = 10000; // number of time steps

    // open output file
    FILE *output;
    output = fopen("output.txt", "w");

    // loop over time steps
    for (i = 0; i < n; i++) {
        t = i*dt; // current time

        // calculate force on particle
        r = sqrt(x*x + y*y + z*z); // distance from origin
        F = -k*(r - 1.0); // Hooke's law
        xs = x/r; // unit vector in x direction
        ys = y/r; // unit vector in y direction
        zs = z/r; // unit vector in z direction
        fx = F*xs; // force in x direction
        fy = F*ys; // force in y direction
        fz = F*zs; // force in z direction

        // update position and velocity using Verlet integration
        x = x + vx*dt + 0.5*fx/m*dt*dt;
        y = y + vy*dt + 0.5*fy/m*dt*dt;
        z = z + vz*dt + 0.5*fz/m*dt*dt;
        r = sqrt(x*x + y*y + z*z); // update distance from origin
        xs = x/r; // update unit vector in x direction
        ys = y/r; // update unit vector in y direction
        zs = z/r; // update unit vector in z direction
        F = -k*(r - 1.0); // update force
        fx = F*xs; // update force in x direction
        fy = F*ys; // update force in y direction
        fz = F*zs; // update force in z direction
        vx = vx + 0.5*(fx/m + fx/m)*dt;
        vy = vy + 0.5*(fy/m + fy/m)*dt;
        vz = vz + 0.5*(fz/m + fz/m)*dt;

        // write current position and velocity to output file
        fprintf(output, "%f %f %f %f %f %f\n", x, y, z, vx, vy, vz);
    }

    // close output file
    fclose(output);

    return 0;
}