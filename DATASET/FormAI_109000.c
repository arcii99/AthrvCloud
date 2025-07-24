//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11 // universal gravitational constant

typedef struct {
    double x, y, z; // position vector
    double vx, vy, vz; // velocity vector
    double mass; // mass of the planet
} planet;

// calculate the gravitational force between two planets
void compute_force(planet a, planet b, double *fx, double *fy, double *fz) {
    double dx = b.x-a.x;
    double dy = b.y-a.y;
    double dz = b.z-a.z;
    double dist = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * a.mass * b.mass / (dist*dist);
    *fx = f * dx / dist;
    *fy = f * dy / dist;
    *fz = f * dz / dist;
}

int main() {
    // initialize the planets
    planet planets[3] = {{1e11, 0, 0, 0, 3e4, 0, 5.97e24},
                         {-1e11, 0, 0, 0, -3e4, 0, 5.97e24},
                         {0, 0, 0, 0, 0, 0, 1.98e30}};

    // set up the simulation parameters
    double dt = 10; // time step
    double tmax = 31536000; // maximum simulation time (1 year)
    int nsteps = tmax/dt;

    // create arrays to store the forces and accelerations
    double fx[3], fy[3], fz[3];
    double ax[3], ay[3], az[3];

    // simulate the motion of the planets
    for (int i = 0; i < nsteps; i++) {
        // calculate the forces and accelerations for each planet
        for (int j = 0; j < 3; j++) {
            fx[j] = 0;
            fy[j] = 0;
            fz[j] = 0;
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    double f_x, f_y, f_z;
                    compute_force(planets[j], planets[k], &f_x, &f_y, &f_z);
                    fx[j] += f_x;
                    fy[j] += f_y;
                    fz[j] += f_z;
                }
            }
            ax[j] = fx[j] / planets[j].mass;
            ay[j] = fy[j] / planets[j].mass;
            az[j] = fz[j] / planets[j].mass;
        }

        // update the positions and velocities of the planets
        for (int j = 0; j < 3; j++) {
            planets[j].x += planets[j].vx*dt + 0.5*ax[j]*dt*dt;
            planets[j].y += planets[j].vy*dt + 0.5*ay[j]*dt*dt;
            planets[j].z += planets[j].vz*dt + 0.5*az[j]*dt*dt;
            planets[j].vx += ax[j]*dt;
            planets[j].vy += ay[j]*dt;
            planets[j].vz += az[j]*dt;
        }
    }

    // print the final positions and velocities of the planets
    for (int i = 0; i < 3; i++) {
        printf("Planet %d: Position (%.2e, %.2e, %.2e) Velocity (%.2e, %.2e, %.2e)\n",
               i+1, planets[i].x, planets[i].y, planets[i].z,
               planets[i].vx, planets[i].vy, planets[i].vz);
    }

    return 0;
}