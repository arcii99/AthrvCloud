//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // Gravitational Constant
#define TIMESTEP 86400 // Timestep (1 day)

typedef struct {
    double mass;
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double ax, ay, az; // Acceleration
} Body;

void calculate_acceleration(Body *b1, Body *b2, double *ax, double *ay, double *az) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double dz = b2->z - b1->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double force = G * b1->mass * b2->mass / (distance * distance);
    *ax += force * dx / distance / b1->mass;
    *ay += force * dy / distance / b1->mass;
    *az += force * dz / distance / b1->mass;
}

int main() {
    Body earth = {5.972e24, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Body moon = {7.349e22, 384400000, 0, 0, 0, 0, 0, 0, 0, 0}; // Distance to Earth: 384400 km

    double ax = 0, ay = 0, az = 0;

    printf("Starting Gravity Simulation!\n");

    for (int i = 0; i < 365; i++) { // 1 year
        ax = 0;
        ay = 0;
        az = 0;

        // Calculate acceleration of Earth by Moon
        calculate_acceleration(&earth, &moon, &ax, &ay, &az);

        // Update Earth's velocity and position
        earth.vx += ax * TIMESTEP;
        earth.vy += ay * TIMESTEP;
        earth.vz += az * TIMESTEP;
        earth.x += earth.vx * TIMESTEP;
        earth.y += earth.vy * TIMESTEP;
        earth.z += earth.vz * TIMESTEP;

        // Calculate acceleration of Moon by Earth
        ax = 0;
        ay = 0;
        az = 0;

        calculate_acceleration(&moon, &earth, &ax, &ay, &az);

        // Update Moon's velocity and position
        moon.vx += ax * TIMESTEP;
        moon.vy += ay * TIMESTEP;
        moon.vz += az * TIMESTEP;
        moon.x += moon.vx * TIMESTEP;
        moon.y += moon.vy * TIMESTEP;
        moon.z += moon.vz * TIMESTEP;

        printf("Day: %d | Earth Position: (%e, %e, %e) | Moon Position: (%e, %e, %e)\n", i+1, earth.x, earth.y, earth.z, moon.x, moon.y, moon.z);
    }

    printf("Simulation Completed!\n");

    return 0;
}