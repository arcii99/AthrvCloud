//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: portable
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // universal gravitational constant
#define DT 3600 // time step for simulation
#define RADIUS 6.371e6 // radius of Earth in meters

typedef struct {
    double x, y; // position in meters
    double vx, vy; // velocity in meters per second
    double ax, ay; // acceleration in meters per second squared
    double mass; // mass in kilograms
} Body;

int main() {
    Body earth = {0, 0, 0, 0, 0, 0, 5.972e24}; // initialize Earth
    Body moon = {3.844e8, 0, 0, 1022, 0, 0, 7.342e22}; // initialize Moon
    Body mars = {0, 2.279e11, -24000, 0, 0, 0, 6.39e23}; // initialize Mars
    Body venus = {-1.082e11, 0, 0, -35260, 0, 0, 4.87e24}; // initialize Venus

    Body bodies[4] = {earth, moon, mars, venus}; // array of all bodies in simulation
    int num_bodies = 4;

    for (int i = 0; i < num_bodies; i++) {
        for (int j = 0; j < num_bodies; j++) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double distance = sqrt(dx*dx + dy*dy); // distance between bodies
                double F = G * bodies[i].mass * bodies[j].mass / (distance * distance); // gravitational force
                double angle = atan2(dy, dx); // angle between bodies
                bodies[i].ax += F * cos(angle) / bodies[i].mass; // horizontal acceleration
                bodies[i].ay += F * sin(angle) / bodies[i].mass; // vertical acceleration
            }
        }
    }

    for (int i = 0; i < num_bodies; i++) {
        bodies[i].x += bodies[i].vx * DT + 0.5 * bodies[i].ax * DT * DT; // update position
        bodies[i].y += bodies[i].vy * DT + 0.5 * bodies[i].ay * DT * DT;
        bodies[i].vx += bodies[i].ax * DT; // update velocity
        bodies[i].vy += bodies[i].ay * DT;

        double distance_from_earth = sqrt(bodies[i].x*bodies[i].x + bodies[i].y*bodies[i].y) - RADIUS; // distance from Earth's surface
        if (distance_from_earth < 0) {
            distance_from_earth = 0;
        }
        printf("Body %d: x = %.2f meters, y = %.2f meters, distance from Earth's surface = %.2f meters\n", i, bodies[i].x, bodies[i].y, distance_from_earth);
    }

    return 0;
}