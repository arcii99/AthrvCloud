//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: high level of detail
// C Planet Gravity Simulation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G_CONST 6.67408e-11 // gravitational constant G

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double mass; // mass
} Planet;

// calculate the distance between two planets
double distance(Planet p1, Planet p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// calculate the gravitational force between two planets
double force(Planet p1, Planet p2) {
    double r = distance(p1, p2);
    return G_CONST * p1.mass * p2.mass / (r * r);
}

int main() {
    // initialize planets
    Planet sun = {0, 0, 0, 0, 0, 1.989e30}; // mass of sun
    Planet earth = {1.496e11, 0, 0, 29783, 0, 5.972e24}; // mass of earth
    
    double dt = 3600; // time step in seconds
    double totalTime = 365 * 24 * 3600; // simulate 1 year
    int numSteps = (int) (totalTime / dt);

    // simulate motion of earth around sun
    for (int i = 0; i < numSteps; i++) {
        // calculate acceleration of earth due to gravity from sun
        double f = force(sun, earth);
        double ax = f / earth.mass * (sun.x - earth.x) / distance(sun, earth);
        double ay = f / earth.mass * (sun.y - earth.y) / distance(sun, earth);

        // update velocity and position of earth
        earth.vx += ax * dt;
        earth.vy += ay * dt;
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;

        // print position of earth
        printf("Step %d: x = %f, y = %f\n", i, earth.x, earth.y);
    }

    return 0;
}