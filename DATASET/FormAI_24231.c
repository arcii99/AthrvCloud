//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846 // define PI

typedef struct {
    double x, y; // coordinates
} Vector;

typedef struct {
    Vector position, velocity; // position and velocity vectors
    double mass; // mass of the object
} Body;

int main() {
    Body sun, earth, moon; // initialize bodies

    // assign properties to the sun
    sun.position.x = sun.position.y = 0;
    sun.velocity.x = sun.velocity.y = 0;
    sun.mass = 1.989e30; // sun's mass in kilograms

    // assign properties to the earth
    earth.position.x = 1.496e11; // distance from the sun in meters
    earth.position.y = 0;
    earth.velocity.x = 0;
    earth.velocity.y = 2.978e4; // orbital velocity in meters per second
    earth.mass = 5.972e24; // earth's mass in kilograms

    // assign properties to the moon
    moon.position.x = 1.496e11 + 3.844e8; // distance from the earth in meters
    moon.position.y = 0;
    moon.velocity.x = 0;
    moon.velocity.y = 1.022e3; // orbital velocity in meters per second
    moon.mass = 7.342e22; // moon's mass in kilograms

    double force, r, dx, dy, ax, ay, dt = 86400; // initialize variables
    int i;
    for (i = 0; i < 365; i++) { // simulate one year
        // calculate force on earth due to sun
        dx = sun.position.x - earth.position.x;
        dy = sun.position.y - earth.position.y;
        r = sqrt(dx*dx + dy*dy);
        force = 6.674e-11 * sun.mass * earth.mass / (r*r);
        ax = force / earth.mass * dx / r;
        ay = force / earth.mass * dy / r;

        // calculate force on moon due to earth
        dx = earth.position.x - moon.position.x;
        dy = earth.position.y - moon.position.y;
        r = sqrt(dx*dx + dy*dy);
        force = 6.674e-11 * moon.mass * earth.mass / (r*r);
        ax += force / moon.mass * dx / r;
        ay += force / moon.mass * dy / r;

        // update positions and velocities of the bodies
        earth.velocity.x += ax * dt;
        earth.velocity.y += ay * dt;
        earth.position.x += earth.velocity.x * dt;
        earth.position.y += earth.velocity.y * dt;

        moon.velocity.x += ax * dt;
        moon.velocity.y += ay * dt;
        moon.position.x += moon.velocity.x * dt;
        moon.position.y += moon.velocity.y * dt;

        // print out earth and moon positions
        printf("Day %d: Earth (%e, %e), Moon (%e, %e)\n", i+1, earth.position.x, earth.position.y, moon.position.x, moon.position.y);
    }

    return 0; // end of program
}