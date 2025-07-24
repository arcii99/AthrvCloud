//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: excited
// Welcome to the exciting C Planet Gravity Simulation program!
// Get ready to be amazed by the power of programming!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11 //gravitational constant

typedef struct {
    double x, y, z;
} Position;

typedef struct {
    double mass;
    Position pos;
    Position vel;
    Position acc;
} Planet;

int main() {

    //Let's create some planets with their masses, positions, velocities, and accelerations
    Planet sun = {1.989e30, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    Planet earth = {5.972e24, {149.6e9, 0, 0}, {0, 29800, 0}, {0, 0, 0}};
    Planet mars = {6.39e23, {-227.9e9, 0, 0}, {0, -24000, 0}, {0, 0, 0}};

    //Let's simulate the planets' motion for one year
    double dt = 86400; //time step of one day
    double t = 0; //initial time = t0

    while (t <= 365 * 86400) { //let's simulate one year

        //calculate the gravitational force and acceleration for each planet
        Position earthtoSun = {sun.pos.x - earth.pos.x, sun.pos.y - earth.pos.y, sun.pos.z - earth.pos.z};
        Position marstoSun = {sun.pos.x - mars.pos.x, sun.pos.y - mars.pos.y, sun.pos.z - mars.pos.z};
        Position earthtoMars = {mars.pos.x - earth.pos.x, mars.pos.y - earth.pos.y, mars.pos.z - earth.pos.z};
        double r1 = sqrt(pow(earthtoSun.x, 2) + pow(earthtoSun.y, 2) + pow(earthtoSun.z, 2));
        double r2 = sqrt(pow(marstoSun.x, 2) + pow(marstoSun.y, 2) + pow(marstoSun.z, 2));
        double r3 = sqrt(pow(earthtoMars.x, 2) + pow(earthtoMars.y, 2) + pow(earthtoMars.z, 2));
        double F1 = G * earth.mass * sun.mass / pow(r1, 2);
        double F2 = G * mars.mass * sun.mass / pow(r2, 2);
        double F3 = G * earth.mass * mars.mass / pow(r3, 2);
        double a1x = F1 * earthtoSun.x / (earth.mass * r1);
        double a1y = F1 * earthtoSun.y / (earth.mass * r1);
        double a1z = F1 * earthtoSun.z / (earth.mass * r1);
        double a2x = F2 * marstoSun.x / (mars.mass * r2);
        double a2y = F2 * marstoSun.y / (mars.mass * r2);
        double a2z = F2 * marstoSun.z / (mars.mass * r2);
        double a3x = F3 * earthtoMars.x / (earth.mass * r3);
        double a3y = F3 * earthtoMars.y / (earth.mass * r3);
        double a3z = F3 * earthtoMars.z / (earth.mass * r3);

        //update the velocities and positions of each planet
        earth.vel.x += a1x * dt;
        earth.vel.y += a1y * dt;
        earth.vel.z += a1z * dt;
        earth.pos.x += earth.vel.x * dt;
        earth.pos.y += earth.vel.y * dt;
        earth.pos.z += earth.vel.z * dt;

        mars.vel.x += a2x * dt;
        mars.vel.y += a2y * dt;
        mars.vel.z += a2z * dt;
        mars.pos.x += mars.vel.x * dt;
        mars.pos.y += mars.vel.y * dt;
        mars.pos.z += mars.vel.z * dt;

        sun.vel.x += (a3x * dt) / (-1);
        sun.vel.y += (a3y * dt) / (-1);
        sun.vel.z += (a3z * dt) / (-1);
        sun.pos.x += sun.vel.x * dt / (-1);
        sun.pos.y += sun.vel.y * dt / (-1);
        sun.pos.z += sun.vel.z * dt / (-1);

        t += dt; //let's move on to the next time step
    }

    //let's print the final positions of the planets
    printf("The final position of the Earth is: (%f, %f, %f)\n", earth.pos.x, earth.pos.y, earth.pos.z);
    printf("The final position of Mars is: (%f, %f, %f)\n", mars.pos.x, mars.pos.y, mars.pos.z);
    printf("The final position of the Sun is: (%f, %f, %f)\n", sun.pos.x, sun.pos.y, sun.pos.z);

    return 0; // Thank you for joining the C Planet Gravity Simulation program!
}