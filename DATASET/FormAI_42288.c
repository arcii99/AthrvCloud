//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11   // gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;   // 3D vector for position, velocity and acceleration

typedef struct {
    double mass;
    Vector3D pos;
    Vector3D vel;
    Vector3D acc;
} Planet;   // planet struct

int main() {

    // initialize planets
    Planet earth = { 5.97e24, {0, 0, 0}, {0, 0, 0} };
    Planet moon = { 7.35e22, {384400000, 0, 0}, {0, 1022.0, 0} };   // distance to earth = 384400000 m, initial velocity = 1022 m/s

    double timeStep = 60.0;   // time step in seconds
    double totalTime = 86400 * 30;   // total simulation time in seconds (30 days)
    int steps = ceil(totalTime / timeStep);   // number of simulation steps

    for (int step = 0; step < steps; step++) {

        // calculate positions
        earth.pos.x += earth.vel.x * timeStep + 0.5 * earth.acc.x * pow(timeStep, 2);
        earth.pos.y += earth.vel.y * timeStep + 0.5 * earth.acc.y * pow(timeStep, 2);
        earth.pos.z += earth.vel.z * timeStep + 0.5 * earth.acc.z * pow(timeStep, 2);
        moon.pos.x += moon.vel.x * timeStep + 0.5 * moon.acc.x * pow(timeStep, 2);
        moon.pos.y += moon.vel.y * timeStep + 0.5 * moon.acc.y * pow(timeStep, 2);
        moon.pos.z += moon.vel.z * timeStep + 0.5 * moon.acc.z * pow(timeStep, 2);

        // calculate accelerations
        double r = sqrt(pow(moon.pos.x - earth.pos.x, 2) + pow(moon.pos.y - earth.pos.y, 2) + pow(moon.pos.z - earth.pos.z, 2));   // distance between earth and moon
        double force = G * earth.mass * moon.mass / pow(r, 2);   // gravitational force between earth and moon
        Vector3D direction = { (moon.pos.x - earth.pos.x) / r, (moon.pos.y - earth.pos.y) / r, (moon.pos.z - earth.pos.z) / r };   // direction of gravitational force
        earth.acc.x = force / earth.mass * direction.x;
        earth.acc.y = force / earth.mass * direction.y;
        earth.acc.z = force / earth.mass * direction.z;
        moon.acc.x = -1 * force / moon.mass * direction.x;
        moon.acc.y = -1 * force / moon.mass * direction.y;
        moon.acc.z = -1 * force / moon.mass * direction.z;

        // calculate velocities
        earth.vel.x += 0.5 * (earth.acc.x + earth.acc.x) * timeStep;
        earth.vel.y += 0.5 * (earth.acc.y + earth.acc.y) * timeStep;
        earth.vel.z += 0.5 * (earth.acc.z + earth.acc.z) * timeStep;
        moon.vel.x += 0.5 * (moon.acc.x + moon.acc.x) * timeStep;
        moon.vel.y += 0.5 * (moon.acc.y + moon.acc.y) * timeStep;
        moon.vel.z += 0.5 * (moon.acc.z + moon.acc.z) * timeStep;

        // print positions
        printf("Step %d: Earth (%.2f, %.2f, %.2f), Moon (%.2f, %.2f, %.2f)\n", step+1, earth.pos.x, earth.pos.y, earth.pos.z, moon.pos.x, moon.pos.y, moon.pos.z);

    }

    return 0;
}