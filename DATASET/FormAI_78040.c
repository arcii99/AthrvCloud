//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAV_CONST 6.6743e-11 // gravitational constant
#define MASS_EARTH 5.972e24 // mass of Earth in kg
#define MASS_MOON 7.342e22 // mass of Moon in kg
#define DIST_EM 3.844e8 // distance from Earth to Moon in meters

int main() {
    float earthMass, moonMass, earthX, earthY, moonX, moonY, px, py, vx, vy, dt;
    int steps;
    earthMass = MASS_EARTH * 10; // increase Earth's mass by a factor of 10
    moonMass = MASS_MOON * 10; // increase Moon's mass by a factor of 10
    earthX = 0; earthY = 0; // Earth starts at origin
    moonX = DIST_EM; moonY = 0; // Moon starts at a distance from Earth
    vx = 0; vy = 1000; // initial velocity of Moon
    dt = 500; // time step
    steps = 5000; // number of time steps to simulate

    for (int i = 0; i < steps; i++) {
        float dx = moonX - earthX, dy = moonY - earthY; // distance between Earth and Moon
        float f = GRAV_CONST * earthMass * moonMass / (dx * dx + dy * dy); // gravitational force
        float fx = f * dx / (sqrt(dx * dx + dy * dy)); // x-component of force
        float fy = f * dy / (sqrt(dx * dx + dy * dy)); // y-component of force
        float ax = fx / moonMass, ay = fy / moonMass; // x- and y-components of acceleration
        vx -= ax * dt; vy -= ay * dt; // update velocity
        px += vx * dt; py += vy * dt; // update position
        moonX = px; moonY = py; // update Moon's position
        printf("%.2f %.2f\n", moonX, moonY); // print position of Moon
    }
    return 0;
}