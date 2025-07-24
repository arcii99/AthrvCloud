//FormAI DATASET v1.0 Category: Physics simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define GRAV_CONSTANT 6.674e-11   // Gravitational constant

// Structure for defining a point in 3D space
typedef struct {
    double x;
    double y;
    double z;
} Point;

// Structure for defining a velocity vector in 3D space
typedef struct {
    double vx;
    double vy;
    double vz;
} Velocity;

// Structure for defining a planet
typedef struct {
    char name[50];      // Name of the planet
    Point location;     // Location of the planet in space
    Velocity velocity;  // Velocity of the planet
    double mass;        // Mass of the planet
} Planet;

// Function to calculate the force between two planets
void calculateForce(Planet p1, Planet p2, double *force_x, double *force_y, double *force_z) {
    double distance = sqrt(pow(p1.location.x - p2.location.x, 2) + pow(p1.location.y - p2.location.y, 2) + pow(p1.location.z - p2.location.z, 2));
    double force = (GRAV_CONSTANT * p1.mass * p2.mass) / pow(distance, 2);
    *force_x = force * (p2.location.x - p1.location.x) / distance;
    *force_y = force * (p2.location.y - p1.location.y) / distance;
    *force_z = force * (p2.location.z - p1.location.z) / distance;
}

int main() {
    int numPlanets = 3; // Number of planets in our simulation
    int numSteps = 10000; // Number of time steps we want to simulate
    double timeStep = 0.01; // Time step size in seconds

    // Define our planets
    Planet earth = {"Earth", {0, 0, 0}, {0, 0, 0}, 5.972e24};
    Planet moon = {"Moon", {384400000, 0, 0}, {0, 1022, 0}, 7.342e22};
    Planet mars = {"Mars", {0, 227940000000, 0}, {-24100, 0, 0}, 6.39e23};

    // Define variables to hold the force between each pair of planets
    double force_earth_moon_x, force_earth_moon_y, force_earth_moon_z;
    double force_earth_mars_x, force_earth_mars_y, force_earth_mars_z;
    double force_moon_mars_x, force_moon_mars_y, force_moon_mars_z;

    // Run the simulation for the specified number of time steps
    for (int i = 0; i < numSteps; i++) {
        // Calculate the forces between each pair of planets
        calculateForce(earth, moon, &force_earth_moon_x, &force_earth_moon_y, &force_earth_moon_z);
        calculateForce(earth, mars, &force_earth_mars_x, &force_earth_mars_y, &force_earth_mars_z);
        calculateForce(moon, mars, &force_moon_mars_x, &force_moon_mars_y, &force_moon_mars_z);

        // Update the velocity and position of each planet using the calculated forces
        earth.velocity.vx += (force_earth_moon_x + force_earth_mars_x) / earth.mass * timeStep;
        earth.velocity.vy += (force_earth_moon_y + force_earth_mars_y) / earth.mass * timeStep;
        earth.velocity.vz += (force_earth_moon_z + force_earth_mars_z) / earth.mass * timeStep;
        earth.location.x += earth.velocity.vx * timeStep;
        earth.location.y += earth.velocity.vy * timeStep;
        earth.location.z += earth.velocity.vz * timeStep;

        moon.velocity.vx += (-force_earth_moon_x + force_moon_mars_x) / moon.mass * timeStep;
        moon.velocity.vy += (-force_earth_moon_y + force_moon_mars_y) / moon.mass * timeStep;
        moon.velocity.vz += (-force_earth_moon_z + force_moon_mars_z) / moon.mass * timeStep;
        moon.location.x += moon.velocity.vx * timeStep;
        moon.location.y += moon.velocity.vy * timeStep;
        moon.location.z += moon.velocity.vz * timeStep;

        mars.velocity.vx += (-force_earth_mars_x - force_moon_mars_x) / mars.mass * timeStep;
        mars.velocity.vy += (-force_earth_mars_y - force_moon_mars_y) / mars.mass * timeStep;
        mars.velocity.vz += (-force_earth_mars_z - force_moon_mars_z) / mars.mass * timeStep;
        mars.location.x += mars.velocity.vx * timeStep;
        mars.location.y += mars.velocity.vy * timeStep;
        mars.location.z += mars.velocity.vz * timeStep;

        // Output the locations of the planets
        printf("Step %d:\n", i);
        printf("%s: (%.2f, %.2f, %.2f)\n", earth.name, earth.location.x, earth.location.y, earth.location.z);
        printf("%s: (%.2f, %.2f, %.2f)\n", moon.name, moon.location.x, moon.location.y, moon.location.z);
        printf("%s: (%.2f, %.2f, %.2f)\n", mars.name, mars.location.x, mars.location.y, mars.location.z);
    }

    return 0;
}