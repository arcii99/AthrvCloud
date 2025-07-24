//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant
#define TIMESTEP 86400 // simulation time step in seconds
#define DAYS 365 // number of days to simulate
#define NUM_PLANETS 4 // number of planets in the simulation

struct planet {
    char name[20]; // planet's name
    double mass; // planet's mass in kilograms
    double x; // planet's x position in meters
    double y; // planet's y position in meters
    double z; // planet's z position in meters
    double vx; // planet's x velocity in meters per second
    double vy; // planet's y velocity in meters per second
    double vz; // planet's z velocity in meters per second
    double ax; // planet's x acceleration in meters per second squared
    double ay; // planet's y acceleration in meters per second squared
    double az; // planet's z acceleration in meters per second squared
};

void update_accelerations(struct planet planets[]) {
    int i, j;
    double dx, dy, dz, d, f;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].ax = planets[i].ay = planets[i].az = 0.0;
        for (j = 0; j < NUM_PLANETS; j++) {
            if (i == j) continue;
            dx = planets[j].x - planets[i].x;
            dy = planets[j].y - planets[i].y;
            dz = planets[j].z - planets[i].z;
            d = sqrt(dx*dx + dy*dy + dz*dz);
            f = G * planets[i].mass * planets[j].mass / (d*d);
            planets[i].ax += f * dx / d;
            planets[i].ay += f * dy / d;
            planets[i].az += f * dz / d;
        }
    }
}

void update_velocities(struct planet planets[]) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].vx += planets[i].ax * TIMESTEP;
        planets[i].vy += planets[i].ay * TIMESTEP;
        planets[i].vz += planets[i].az * TIMESTEP;
    }
}

void update_positions(struct planet planets[]) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].vx * TIMESTEP;
        planets[i].y += planets[i].vy * TIMESTEP;
        planets[i].z += planets[i].vz * TIMESTEP;
    }
}

void print_planet(struct planet p) {
    printf("%s: x=%.3e m, y=%.3e m, z=%.3e m, vx=%.3e m/s, vy=%.3e m/s, vz=%.3e m/s\n", p.name, p.x, p.y, p.z, p.vx, p.vy, p.vz);
}

int main() {
    struct planet planets[NUM_PLANETS] = {
        {"Sun", 1.989e30, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {"Earth", 5.972e24, 1.496e11, 0, 0, 0, 29900, 0, 0, 0, 0},
        {"Mars", 6.39e23, -2.279e11, 0, 0, 0, 24007, 0, 0, 0, 0},
        {"Jupiter", 1.898e27, 0, 7.785e11, 0, -13052, 0, 0, 0, 0, 0}
    };
    int day;
    for (day = 0; day < DAYS; day++) {
        update_accelerations(planets);
        update_velocities(planets);
        update_positions(planets);
        printf("Day %d:\n", day+1);
        int i;
        for (i = 0; i < NUM_PLANETS; i++) {
            print_planet(planets[i]);
        }
    }
    return 0;
}