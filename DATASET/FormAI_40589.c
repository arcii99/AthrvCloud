//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: configurable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define constants
#define G 6.6743E-11 // Gravitational constant
#define SUN_MASS 1.9885E30 // Mass of the sun

// Define structure for a celestial body
typedef struct {
    char name[20]; // Name of the celestial body
    double mass; // Mass of the celestial body
    double radius; // Radius of the celestial body
    double posX, posY, posZ; // Position of the celestial body
    double velX, velY, velZ; // Velocity of the celestial body
} Body;

// Define function to calculate the distance between two celestial bodies
double distance(Body body1, Body body2) {
    return sqrt(pow((body2.posX - body1.posX), 2) + pow((body2.posY - body1.posY), 2) + pow((body2.posZ - body1.posZ), 2));
}

// Define function to calculate the gravitational force between two celestial bodies
double force(Body body1, Body body2) {
    double dist = distance(body1, body2);
    return (G * body1.mass * body2.mass) / pow(dist, 2);
}

// Define function to update the velocity and position of a celestial body
void updateBody(Body *body, double fX, double fY, double fZ, double dt) {
    // Update velocity
    body->velX += fX / body->mass * dt;
    body->velY += fY / body->mass * dt;
    body->velZ += fZ / body->mass * dt;
    
    // Update position
    body->posX += body->velX * dt;
    body->posY += body->velY * dt;
    body->posZ += body->velZ * dt;
}

int main() {
    // Define celestial bodies
    Body sun = {"Sun", SUN_MASS, 696340000.0, 0, 0, 0, 0, 0, 0};
    Body earth = {"Earth", 5.972E24, 6371000.0, 0, 149600000000.0, 0, 0, 29780, 0};
    Body moon = {"Moon", 7.342E22, 1737100.0, 0, 149600000000.0 + 384400000.0, 0, 1022, 30251, 0};

    // Define simulation parameters
    double dt = 1000.0; // Time step (in seconds)
    int steps = 365 * 24 * 60 * 60 / dt; // Number of simulation steps
    int i;

    // Run simulation
    for (i = 0; i < steps; i++) {
        // Calculate force and update velocity and position for Earth
        double fSun = force(sun, earth);
        double fMoon = force(moon, earth);
        updateBody(&earth, fSun * sin(PI / 3) + fMoon * sin(PI / 3), fSun * cos(PI / 3) + fMoon * cos(PI / 3), 0, dt);

        // Calculate force and update velocity and position for Moon
        double fEarth = force(earth, moon);
        updateBody(&moon, fEarth * sin(PI / 3), fEarth * cos(PI / 3), 0, dt);

        // Output positions of Earth and Moon
        printf("Step %d: Earth Position: (%f, %f, %f), Moon Position: (%f, %f, %f)\n", i+1, earth.posX, earth.posY, earth.posZ, moon.posX, moon.posY, moon.posZ);
    }

    return 0;
}