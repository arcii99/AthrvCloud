//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define G 6.67e-11 // Gravitational constant

struct planet {
    double mass;
    double x, y, z; // coordinates
    double vx, vy, vz; // velocities
    double ax, ay, az; // accelerations
};

int main() {

    // defining the planets
    struct planet p1 = {5.97e24, 0, 0, 0, 0, 0, 0, 0, 0};
    struct planet p2 = {6.39e23, 384400000, 0, 0, 0, 1022, 0, 0, 0};

    double t = 0; // time
    double dt = 60; // time step

    // calculating distance between the planets
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);

    // calculating initial acceleration of p1 and p2
    p1.ax = p2.ax = G * p2.mass * (p1.x - p2.x) / pow(r, 3);
    p1.ay = p2.ay = G * p2.mass * (p1.y - p2.y) / pow(r, 3);
    p1.az = p2.az = G * p2.mass * (p1.z - p2.z) / pow(r, 3);

    while (1) { // infinite loop

        // updating positions
        p1.x += p1.vx * dt;
        p1.y += p1.vy * dt;
        p1.z += p1.vz * dt;
        p2.x += p2.vx * dt;
        p2.y += p2.vy * dt;
        p2.z += p2.vz * dt;

        // updating velocities
        p1.vx += p1.ax * dt;
        p1.vy += p1.ay * dt;
        p1.vz += p1.az * dt;
        p2.vx += p2.ax * dt;
        p2.vy += p2.ay * dt;
        p2.vz += p2.az * dt;

        // calculating distance and acceleration
        dx = p2.x - p1.x;
        dy = p2.y - p1.y;
        dz = p2.z - p1.z;
        r = sqrt(dx*dx + dy*dy + dz*dz);
        p1.ax = G * p2.mass * (p2.x - p1.x) / pow(r, 3);
        p1.ay = G * p2.mass * (p2.y - p1.y) / pow(r, 3);
        p1.az = G * p2.mass * (p2.z - p1.z) / pow(r, 3);
        p2.ax = G * p1.mass * (p1.x - p2.x) / pow(r, 3);
        p2.ay = G * p1.mass * (p1.y - p2.y) / pow(r, 3);
        p2.az = G * p1.mass * (p1.z - p2.z) / pow(r, 3);

        t += dt; // updating time

        // printing the positions and velocities of the planets
        printf("Time: %lf\n", t);
        printf("Planet 1: (%lf, %lf, %lf) (%lf, %lf, %lf)\n", p1.x, p1.y, p1.z, p1.vx, p1.vy, p1.vz);
        printf("Planet 2: (%lf, %lf, %lf) (%lf, %lf, %lf)\n", p2.x, p2.y, p2.z, p2.vx, p2.vy, p2.vz);
        printf("-----------------------------------------\n");

        // adding delay
        clock_t start_time = clock();
        while (clock() < start_time + 500000);
    }

    return 0;
}