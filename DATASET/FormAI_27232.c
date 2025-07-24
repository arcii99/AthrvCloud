//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multivariable
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant

struct planet {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

int main() {
    int num_planets;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    struct planet planets[num_planets];

    // prompt user to input data for each planet
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d:\n", i+1);
        printf("Mass (kg): ");
        scanf("%lf", &planets[i].mass);
        printf("Position (x y z, m): ");
        scanf("%lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].z);
        printf("Velocity (vx vy vz, m/s): ");
        scanf("%lf %lf %lf", &planets[i].vx, &planets[i].vy, &planets[i].vz);
    }

    double force[num_planets][num_planets][3]; // 3D array to store forces acting on each planet

    const double timestep = 0.01; // time step (in seconds)
    const int num_steps = 10000; // number of time steps

    // loop over each time step
    for (int t = 0; t < num_steps; t++) {
        // calculate forces between all pairs of planets
        for (int i = 0; i < num_planets; i++) {
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    double dx = planets[j].x - planets[i].x;
                    double dy = planets[j].y - planets[i].y;
                    double dz = planets[j].z - planets[i].z;
                    double r = sqrt(dx*dx + dy*dy + dz*dz); // distance between planets
                    double f = G * planets[i].mass * planets[j].mass / (r*r*r); // gravitational force
                    force[i][j][0] = f * dx;
                    force[i][j][1] = f * dy;
                    force[i][j][2] = f * dz;
                }
            }
        }

        // update positions and velocities of each planet
        for (int i = 0; i < num_planets; i++) {
            double ax = 0;
            double ay = 0;
            double az = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    ax += force[i][j][0] / planets[i].mass;
                    ay += force[i][j][1] / planets[i].mass;
                    az += force[i][j][2] / planets[i].mass;
                }
            }
            planets[i].vx += ax * timestep;
            planets[i].vy += ay * timestep;
            planets[i].vz += az * timestep;
            planets[i].x += planets[i].vx * timestep;
            planets[i].y += planets[i].vy * timestep;
            planets[i].z += planets[i].vz * timestep;
        }

        // print out the positions of each planet every 100 time steps
        if (t % 100 == 0) {
            printf("Time step %d:\n", t);
            for (int i = 0; i < num_planets; i++) {
                printf("Planet %d: (%.2f, %.2f, %.2f)\n", i+1, planets[i].x, planets[i].y, planets[i].z);
            }
        }
    }

    return 0;
}