//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8

typedef struct {
    char name[20];
    double mass; // in kg
    double x; // in m
    double y; // in m
    double z; // in m
    double vx; // in m/s
    double vy; // in m/s
    double vz; // in m/s
} Planet;

void update_velocity(Planet planets[]) {
    int i, j;
    double G = 6.67430e-11; // Gravitational constant in m^3 kg^-1 s^-2
    double dx, dy, dz, r, F, ax, ay, az;
    for (i = 0; i < NUM_PLANETS; i++) {
        ax = ay = az = 0;
        for (j = 0; j < NUM_PLANETS; j++) {
            if (i == j) continue;
            dx = planets[j].x - planets[i].x;
            dy = planets[j].y - planets[i].y;
            dz = planets[j].z - planets[i].z;
            r = sqrt(dx*dx + dy*dy + dz*dz);
            F = G * planets[i].mass * planets[j].mass / (r*r);
            ax += F * dx / r;
            ay += F * dy / r;
            az += F * dz / r;
        }
        planets[i].vx += ax;
        planets[i].vy += ay;
        planets[i].vz += az;
    }
}

void update_position(Planet planets[], double dt) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
        planets[i].z += planets[i].vz * dt;
    }
}

int main() {
    Planet planets[NUM_PLANETS] = {
        {"Sun", 1.98892e30, 0, 0, 0, 0, 0, 0},
        {"Mercury", 3.3011e23, -4.60012e10, -5.09796e10, -6.0214e8, 38860, -30777, -8233},
        {"Venus", 4.8675e24, 1.07477e11, -1.04671e10, -6.05164e9, 15700, 34951, 1232},
        {"Earth", 5.97237e24, -1.48662e11, -2.67401e10, 3.10038e5, -1029, -29293, -0.067},
        {"Mars", 6.4171e23, -2.07228e11, 4.90434e10, 7.4517e9, -14111, -6189, 444},
        {"Jupiter", 1.89819e27, 7.40569e11, -6.45563e11, -1.58577e10, 7370, 8028, -136},
        {"Saturn", 5.6834e26, 1.36438e12, -9.85604e11, -2.17376e10, 5455, 7532, -152},
        {"Uranus", 8.68103e25, 2.67746e12, 1.20947e12, -2.43193e10, -3831, 6397, 40},
        {"Neptune", 1.0241e26, 4.34513e12, -9.96517e11, -7.92318e10, 1797, 4547, -90}
    };
    double dt = 86400; // 1 day in seconds
    int num_steps = 365 * 20; // simulate 20 years
    int i, j;
    for (i = 0; i < num_steps; i++) {
        update_velocity(planets);
        update_position(planets, dt);
        // Print planet positions
        printf("Time step %d:\n", i);
        for (j = 0; j < NUM_PLANETS; j++) {
            printf("%-10s x = %10.2e m, y = %10.2e m, z = %10.2e m\n", planets[j].name, planets[j].x, planets[j].y, planets[j].z);
        }
        printf("\n");
    }
    return 0;
}