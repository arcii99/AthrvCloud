//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: real-life
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.6743e-11  // gravitational constant
#define TIME_STEP 60            // time step in seconds

// define a structure for a planet
struct Planet {
    char name[50];
    double mass;    // in kg
    double radius;  // in m
    double x;       // x coordinate in m
    double y;       // y coordinate in m
    double z;       // z coordinate in m
    double vx;      // x velocity in m/s
    double vy;      // y velocity in m/s
    double vz;      // z velocity in m/s
};

// function to calculate the gravitational force between two planets
void calc_gravity(struct Planet* planet1, struct Planet* planet2, double* fx, double* fy, double* fz) {
    double r = sqrt(pow(planet2->x - planet1->x, 2) + pow(planet2->y - planet1->y, 2) + pow(planet2->z - planet1->z, 2));  // distance between planets
    double f = GRAV_CONST * planet1->mass * planet2->mass / pow(r, 2);   // gravitational force
    *fx = f * (planet2->x - planet1->x) / r;    // x component of force
    *fy = f * (planet2->y - planet1->y) / r;    // y component of force
    *fz = f * (planet2->z - planet1->z) / r;    // z component of force
}

int main() {
    // define the planets in the solar system
    struct Planet sun = {"Sun", 1.989e+30, 696340000, 0, 0, 0, 0, 0, 0};
    struct Planet mercury = {"Mercury", 3.285e+23, 2439700, 0, 57910000, 0, 47362.3, 0, 0};
    struct Planet venus = {"Venus", 4.867e+24, 6051800, 0, 108200000, 0, 35020.4, 0, 0};
    struct Planet earth = {"Earth", 5.972e+24, 6371000, 0, 149600000, 0, 29783.5, 0, 0};
    struct Planet mars = {"Mars", 6.39e+23, 3389500, 0, 227940000, 0, 24129.8, 0, 0};
    struct Planet jupiter = {"Jupiter", 1.898e+27, 69911000, 0, 778330000, 0, 13040.6, 0, 0};
    struct Planet saturn = {"Saturn", 5.683e+26, 58232000, 0, 1429400000, 0, 9690.3, 0, 0};
    struct Planet uranus = {"Uranus", 8.681e+25, 25362000, 0, 2870990000, 0, 6810.7, 0, 0};
    struct Planet neptune = {"Neptune", 1.024e+26, 24622000, 0, 4495000000, 0, 5430.5, 0, 0};

    // initialize the simulation time
    int time = 0;

    // run the simulation for 1000 years
    for (int year = 1; year <= 1000; year++) {
        // update the positions and velocities of all the planets
        mercury.x += mercury.vx * TIME_STEP;
        mercury.y += mercury.vy * TIME_STEP;
        mercury.z += mercury.vz * TIME_STEP;
        venus.x += venus.vx * TIME_STEP;
        venus.y += venus.vy * TIME_STEP;
        venus.z += venus.vz * TIME_STEP;
        earth.x += earth.vx * TIME_STEP;
        earth.y += earth.vy * TIME_STEP;
        earth.z += earth.vz * TIME_STEP;
        mars.x += mars.vx * TIME_STEP;
        mars.y += mars.vy * TIME_STEP;
        mars.z += mars.vz * TIME_STEP;
        jupiter.x += jupiter.vx * TIME_STEP;
        jupiter.y += jupiter.vy * TIME_STEP;
        jupiter.z += jupiter.vz * TIME_STEP;
        saturn.x += saturn.vx * TIME_STEP;
        saturn.y += saturn.vy * TIME_STEP;
        saturn.z += saturn.vz * TIME_STEP;
        uranus.x += uranus.vx * TIME_STEP;
        uranus.y += uranus.vy * TIME_STEP;
        uranus.z += uranus.vz * TIME_STEP;
        neptune.x += neptune.vx * TIME_STEP;
        neptune.y += neptune.vy * TIME_STEP;
        neptune.z += neptune.vz * TIME_STEP;

        // calculate the gravitational forces between all the planets
        double fx, fy, fz;
        calc_gravity(&sun, &mercury, &fx, &fy, &fz);
        mercury.vx += fx * TIME_STEP / mercury.mass;
        mercury.vy += fy * TIME_STEP / mercury.mass;
        mercury.vz += fz * TIME_STEP / mercury.mass;
        calc_gravity(&sun, &venus, &fx, &fy, &fz);
        venus.vx += fx * TIME_STEP / venus.mass;
        venus.vy += fy * TIME_STEP / venus.mass;
        venus.vz += fz * TIME_STEP / venus.mass;
        calc_gravity(&sun, &earth, &fx, &fy, &fz);
        earth.vx += fx * TIME_STEP / earth.mass;
        earth.vy += fy * TIME_STEP / earth.mass;
        earth.vz += fz * TIME_STEP / earth.mass;
        calc_gravity(&sun, &mars, &fx, &fy, &fz);
        mars.vx += fx * TIME_STEP / mars.mass;
        mars.vy += fy * TIME_STEP / mars.mass;
        mars.vz += fz * TIME_STEP / mars.mass;
        calc_gravity(&sun, &jupiter, &fx, &fy, &fz);
        jupiter.vx += fx * TIME_STEP / jupiter.mass;
        jupiter.vy += fy * TIME_STEP / jupiter.mass;
        jupiter.vz += fz * TIME_STEP / jupiter.mass;
        calc_gravity(&sun, &saturn, &fx, &fy, &fz);
        saturn.vx += fx * TIME_STEP / saturn.mass;
        saturn.vy += fy * TIME_STEP / saturn.mass;
        saturn.vz += fz * TIME_STEP / saturn.mass;
        calc_gravity(&sun, &uranus, &fx, &fy, &fz);
        uranus.vx += fx * TIME_STEP / uranus.mass;
        uranus.vy += fy * TIME_STEP / uranus.mass;
        uranus.vz += fz * TIME_STEP / uranus.mass;
        calc_gravity(&sun, &neptune, &fx, &fy, &fz);
        neptune.vx += fx * TIME_STEP / neptune.mass;
        neptune.vy += fy * TIME_STEP / neptune.mass;
        neptune.vz += fz * TIME_STEP / neptune.mass;

        time += TIME_STEP;  // update the simulation time
    }

    // print the final positions and velocities of all the planets
    printf("Final positions and velocities of the planets:\n");
    printf("Planet         x (m)         y (m)         z (m)         vx (m/s)      vy (m/s)      vz (m/s)\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("%-15s %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f\n", sun.name, sun.x, sun.y, sun.z, sun.vx, sun.vy, sun.vz);
    printf("%-15s %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f\n", mercury.name, mercury.x, mercury.y, mercury.z, mercury.vx, mercury.vy, mercury.vz);
    printf("%-15s %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f\n", venus.name, venus.x, venus.y, venus.z, venus.vx, venus.vy, venus.vz);
    printf("%-15s %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f\n", earth.name, earth.x, earth.y, earth.z, earth.vx, earth.vy, earth.vz);
    printf("%-15s %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f\n", mars.name, mars.x, mars.y, mars.z, mars.vx, mars.vy, mars.vz);
    printf("%-15s %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f\n", jupiter.name, jupiter.x, jupiter.y, jupiter.z, jupiter.vx, jupiter.vy, jupiter.vz);
    printf("%-15s %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f\n", saturn.name, saturn.x, saturn.y, saturn.z, saturn.vx, saturn.vy, saturn.vz);
    printf("%-15s %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f\n", uranus.name, uranus.x, uranus.y, uranus.z, uranus.vx, uranus.vy, uranus.vz);
    printf("%-15s %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f %-14.1f\n", neptune.name, neptune.x, neptune.y, neptune.z, neptune.vx, neptune.vy, neptune.vz);

    return 0;
}