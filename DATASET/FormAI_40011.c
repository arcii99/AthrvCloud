//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: detailed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define G 6.6743e-11 // Gravitational constant

#define N 4 // Number of planets

struct planet {
    double x; // Position x
    double y; // Position y
    double vx; // Velocity x
    double vy; // Velocity y
    double mass; // Mass
};

int main() {
    struct planet planets[N];

    double radius[N] = {695510e3 / 149.6e9, 2.440e6 / 149.6e9, 6.371e6 / 149.6e9, 7.1492e7 / 149.6e9}; // Radii of the planets
    double mass[N] = {1.98e30, 3.30e23, 5.97e24, 6.42e23}; // Masses of the planets
    double velocity[N] = {0, 47.9e3, 29.8e3, 24.1e3}; // Starting velocities of the planets
    double distance[N] = {0, 0.5791e9 / 149.6e9, 1, 1.524}; // Starting distances of the planets from the sun

    for (int i = 0; i < N; i++) {
        planets[i].x = distance[i];
        planets[i].y = 0;
        planets[i].vx = 0;
        planets[i].vy = velocity[i];
        planets[i].mass = mass[i];
    }

    double t = 0; // Time 
    double dt = 24*60*60; // Time step
    double tf = 31536000*3; // Final time

    double fx, fy, r, ax, ay;

    // Simulation loop
    while (t < tf) {
        for (int i = 0; i < N; i++) {
            fx = 0;
            fy = 0;

            for (int j = 0; j < N; j++) {
                if (i != j) {
                    r = sqrt(pow(planets[i].x - planets[j].x, 2) + pow(planets[i].y - planets[j].y, 2));
                    fx += G * planets[i].mass * planets[j].mass * (planets[j].x - planets[i].x) / pow(r, 3);
                    fy += G * planets[i].mass * planets[j].mass * (planets[j].y - planets[i].y) / pow(r, 3);
                }
            }

            ax = fx / planets[i].mass;
            ay = fy / planets[i].mass;

            planets[i].vx += ax * dt;
            planets[i].vy += ay * dt;

            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
        }

        // Output data to file
        FILE *fp;
        fp = fopen("output.txt", "a");
        if (fp == NULL) {
            printf("Error opening file.\n");
            return 1;
        }

        fprintf(fp, "%f ", t);
        for (int i = 0; i < N; i++) {
            fprintf(fp, "%f %f %f %f %f ", planets[i].x, planets[i].y, planets[i].vx, planets[i].vy, planets[i].mass);
        }
        fprintf(fp, "\n");

        fclose(fp);

        t += dt;
    }

    return 0;
}