//FormAI DATASET v1.0 Category: Physics simulation ; Style: single-threaded
#include <stdio.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.6743e-11 // Gravitational Constant for Earth
#define EARTH_MASS 5.97e24 // Mass of Earth in kg
#define EARTH_RADIUS 6371000 // Radius of Earth in meters
#define TIME_STEP 1 // Time step for simulation in seconds
#define MAX_STEPS 10000 // Maximum number of steps for simulation

typedef struct {
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double ax, ay, az; // Acceleration
} Body;

void update_position(Body *b) {
    b->x += b->vx * TIME_STEP + 0.5 * b->ax * pow(TIME_STEP, 2);
    b->y += b->vy * TIME_STEP + 0.5 * b->ay * pow(TIME_STEP, 2);
    b->z += b->vz * TIME_STEP + 0.5 * b->az * pow(TIME_STEP, 2);
}

void update_velocity(Body *b) {
    b->vx += b->ax * TIME_STEP;
    b->vy += b->ay * TIME_STEP;
    b->vz += b->az * TIME_STEP;
}

int main() {
    // Initialize bodies
    Body earth = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Body moon = {384400000, 0, 0, 0, 1022, 0, 0, 0, 0};
    Body spaceship = {0, EARTH_RADIUS + 100000, 0, 7760, 0, 0, 0, 0, 0};

    // Calculate initial acceleration
    double dx = moon.x - earth.x;
    double dy = moon.y - earth.y;
    double dz = moon.z - earth.z;
    double d = sqrt(dx * dx + dy * dy + dz * dz);
    double F = GRAVITATIONAL_CONSTANT * EARTH_MASS * moon.vx * moon.vx / (d * d);
    earth.ax = F / EARTH_MASS;
    moon.ax = -F / EARTH_MASS;
    
    // Simulate motion
    for (int i = 0; i < MAX_STEPS; i++) {
        dx = moon.x - earth.x;
        dy = moon.y - earth.y;
        dz = moon.z - earth.z;
        d = sqrt(dx * dx + dy * dy + dz * dz);
        F = GRAVITATIONAL_CONSTANT * EARTH_MASS * EARTH_MASS / (d * d);
        earth.ax = F * dx / (EARTH_MASS * d);
        earth.ay = F * dy / (EARTH_MASS * d);
        earth.az = F * dz / (EARTH_MASS * d);
        moon.ax = -earth.ax;
        moon.ay = -earth.ay;
        moon.az = -earth.az;

        // Update spaceship acceleration
        dx = spaceship.x - earth.x;
        dy = spaceship.y - earth.y;
        dz = spaceship.z - earth.z;
        d = sqrt(dx * dx + dy * dy + dz * dz);
        F = GRAVITATIONAL_CONSTANT * EARTH_MASS * spaceship.vx * spaceship.vx / (d * d);
        spaceship.ax = F * dx / (EARTH_MASS * d);
        spaceship.ay = F * dy / (EARTH_MASS * d);
        spaceship.az = F * dz / (EARTH_MASS * d);

        // Update positions and velocities
        update_position(&earth);
        update_position(&moon);
        update_position(&spaceship);
        update_velocity(&earth);
        update_velocity(&moon);
        update_velocity(&spaceship);

        // Check if spaceship has reached destination
        if (spaceship.x <= moon.x) {
            printf("Spaceship arrived at the moon after %d seconds.\n", i * TIME_STEP);
            break;
        }
    }
    return 0;
}