//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: systematic
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant (m^3 kg^-1 s^-2)

// structure defining a planet or celestial body
typedef struct {
    char name[20];
    double mass; // in kg
    double radius; // in km
    double x; // x-coordinate in km
    double y; // y-coordinate in km
    double z; // z-coordinate in km
    double vx; // velocity in x direction in km/s
    double vy; // velocity in y direction in km/s
    double vz; // velocity in z direction in km/s
} CelestialBody;

// function to calculate the distance between two bodies in km
double distance(CelestialBody body1, CelestialBody body2);

// function to calculate the gravitational force between two bodies in N
double force(CelestialBody body1, CelestialBody body2);

int main() {
    // create an array of CelestialBody structures representing the solar system
    CelestialBody solarSystem[8] = {
        {"Sun", 1.989e30, 696340, 0, 0, 0, 0, 0, 0},
        {"Mercury", 3.285e23, 2439.7, 57910000, 0, 0, 0, 47.4, 0},
        {"Venus", 4.867e24, 6052, 108200000, 0, 0, 0, 35.0, 0},
        {"Earth", 5.972e24, 6378.1, 149600000, 0, 0, 0, 29.8, 0},
        {"Mars", 6.39e23, 3396.2, 227900000, 0, 0, 0, 24.1, 0},
        {"Jupiter", 1.898e27, 69911, 778300000, 0, 0, 0, 13.1, 0},
        {"Saturn", 5.683e26, 58232, 1429000000, 0, 0, 0, 9.7, 0},
        {"Uranus", 8.681e25, 25362, 2877000000, 0, 0, 0, 6.8, 0}
    };
    
    double timestep = 3600; // in seconds

    // simulate the motion of the bodies
    int i, j;
    for (i = 0; i < 1000000; i++) { // loop for one million timesteps
        // calculate the force acting on each body
        for (j = 0; j < 8; j++) {
            int k;
            double fx = 0, fy = 0, fz = 0;
            for (k = 0; k < 8; k++) {
                if (k != j) {
                    double f = force(solarSystem[j], solarSystem[k]);
                    double d = distance(solarSystem[j], solarSystem[k]);
                    fx += f * (solarSystem[k].x - solarSystem[j].x) / d;
                    fy += f * (solarSystem[k].y - solarSystem[j].y) / d;
                    fz += f * (solarSystem[k].z - solarSystem[j].z) / d;
                }
            }
            // update the velocity of the body
            solarSystem[j].vx += fx * timestep / solarSystem[j].mass;
            solarSystem[j].vy += fy * timestep / solarSystem[j].mass;
            solarSystem[j].vz += fz * timestep / solarSystem[j].mass;
        }
        // update the position of each body
        for (j = 0; j < 8; j++) {
            solarSystem[j].x += solarSystem[j].vx * timestep;
            solarSystem[j].y += solarSystem[j].vy * timestep;
            solarSystem[j].z += solarSystem[j].vz * timestep;
        }
        // print the position of the Earth every day
        if (i % 86400 == 0) {
            printf("Day %d: Earth position: (%.0f, %.0f) km\n", i / 86400, solarSystem[3].x, solarSystem[3].y);
        }
    }

    return 0;
}

double distance(CelestialBody body1, CelestialBody body2) {
    double dx = body2.x - body1.x;
    double dy = body2.y - body1.y;
    double dz = body2.z - body1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

double force(CelestialBody body1, CelestialBody body2) {
    double d = distance(body1, body2);
    return G * body1.mass * body2.mass / (d*d);
}