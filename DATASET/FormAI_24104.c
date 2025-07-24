//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: secure
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define GRAVITY 6.6743e-11

// Definition of a planet
typedef struct {
    char name[20];
    double mass;
    double radius;
    double distanceToSun;
    double aphelion;
    double perihelion;
    double orbitalPeriod;
    double xAxis;
    double yAxis;
    double zAxis;
} Planet;

// Function to compute the force of gravity between two planets
double computeForce(Planet planet1, Planet planet2) {
    double distance = sqrt(pow(planet2.xAxis - planet1.xAxis, 2) + pow(planet2.yAxis - planet1.yAxis, 2) + pow(planet2.zAxis - planet1.zAxis, 2));
    double force = (GRAVITY * planet1.mass * planet2.mass) / pow(distance, 2);
    return force;
}

int main() {
    // Create an array of planets
    Planet planets[8];

    // Populate the planets array with data
    strcpy(planets[0].name, "Mercury");
    planets[0].mass = 3.285e23;
    planets[0].radius = 2439.7;
    planets[0].distanceToSun = 57.91e6;
    planets[0].aphelion = 69.82e6;
    planets[0].perihelion = 46.00e6;
    planets[0].orbitalPeriod = 87.969;
    planets[0].xAxis = planets[0].aphelion * cos(0);
    planets[0].yAxis = planets[0].perihelion * sin(0);
    planets[0].zAxis = 0;

    strcpy(planets[1].name, "Venus");
    planets[1].mass = 4.867e24;
    planets[1].radius = 6051.8;
    planets[1].distanceToSun = 108.2e6;
    planets[1].aphelion = 108.94e6;
    planets[1].perihelion = 107.48e6;
    planets[1].orbitalPeriod = 224.701;
    planets[1].xAxis = planets[1].aphelion * cos(0);
    planets[1].yAxis = planets[1].perihelion * sin(0);
    planets[1].zAxis = 0;

    strcpy(planets[2].name, "Earth");
    planets[2].mass = 5.972e24;
    planets[2].radius = 6371.0;
    planets[2].distanceToSun = 149.6e6;
    planets[2].aphelion = 152.10e6;
    planets[2].perihelion = 147.10e6;
    planets[2].orbitalPeriod = 365.256;
    planets[2].xAxis = planets[2].aphelion * cos(0);
    planets[2].yAxis = planets[2].perihelion * sin(0);
    planets[2].zAxis = 0;

    strcpy(planets[3].name, "Mars");
    planets[3].mass = 6.39e23;
    planets[3].radius = 3396.2;
    planets[3].distanceToSun = 227.9e6;
    planets[3].aphelion = 249.23e6;
    planets[3].perihelion = 206.62e6;
    planets[3].orbitalPeriod = 686.971;
    planets[3].xAxis = planets[3].aphelion * cos(0);
    planets[3].yAxis = planets[3].perihelion * sin(0);
    planets[3].zAxis = 0;

    strcpy(planets[4].name, "Jupiter");
    planets[4].mass = 1.898e27;
    planets[4].radius = 69911;
    planets[4].distanceToSun = 778.6e6;
    planets[4].aphelion = 816.62e6;
    planets[4].perihelion = 740.52e6;
    planets[4].orbitalPeriod = 4332.59;
    planets[4].xAxis = planets[4].aphelion * cos(0);
    planets[4].yAxis = planets[4].perihelion * sin(0);
    planets[4].zAxis = 0;

    strcpy(planets[5].name, "Saturn");
    planets[5].mass = 5.683e26;
    planets[5].radius = 58232;
    planets[5].distanceToSun = 1433.5e6;
    planets[5].aphelion = 1514.50e6;
    planets[5].perihelion = 1352.55e6;
    planets[5].orbitalPeriod = 10759.22;
    planets[5].xAxis = planets[5].aphelion * cos(0);
    planets[5].yAxis = planets[5].perihelion * sin(0);
    planets[5].zAxis = 0;

    strcpy(planets[6].name, "Uranus");
    planets[6].mass = 8.681e25;
    planets[6].radius = 25362;
    planets[6].distanceToSun = 2872.5e6;
    planets[6].aphelion = 3003.62e6;
    planets[6].perihelion = 2741.30e6;
    planets[6].orbitalPeriod = 30687.15;
    planets[6].xAxis = planets[6].aphelion * cos(0);
    planets[6].yAxis = planets[6].perihelion * sin(0);
    planets[6].zAxis = 0;

    strcpy(planets[7].name, "Neptune");
    planets[7].mass = 1.024e26;
    planets[7].radius = 24622;
    planets[7].distanceToSun = 4495.1e6;
    planets[7].aphelion = 4545.67e6;
    planets[7].perihelion = 4444.45e6;
    planets[7].orbitalPeriod = 60190.03;
    planets[7].xAxis = planets[7].aphelion * cos(0);
    planets[7].yAxis = planets[7].perihelion * sin(0);
    planets[7].zAxis = 0;

    // Simulation loop
    double timeStep = 1;
    for (int t = 0; t < 365 * 5; t++) {
        printf("Day %d:\n", t + 1);

        // Compute the new position and velocity of each planet
        for (int i = 0; i < 8; i++) {
            double netForceX = 0;
            double netForceY = 0;
            double netForceZ = 0;

            // Compute the net force on the current planet due to all other planets
            for (int j = 0; j < 8; j++) {
                if (i == j) {
                    continue;
                }

                double force = computeForce(planets[i], planets[j]);
                double angle = atan2(planets[j].yAxis - planets[i].yAxis, planets[j].xAxis - planets[i].xAxis);
                netForceX += force * cos(angle);
                netForceY += force * sin(angle);
                netForceZ += 0;
            }

            // Compute the new position and velocity of the current planet
            double accelerationX = netForceX / planets[i].mass;
            double accelerationY = netForceY / planets[i].mass;
            double accelerationZ = netForceZ / planets[i].mass;
            planets[i].xAxis += planets[i].yAxis * timeStep + 0.5 * accelerationX * pow(timeStep, 2);
            planets[i].yAxis += planets[i].yAxis * timeStep + 0.5 * accelerationY * pow(timeStep, 2);
            planets[i].zAxis += planets[i].zAxis * timeStep + 0.5 * accelerationZ * pow(timeStep, 2);
            printf("%s: (%.2f, %.2f, %.2f)\n", planets[i].name, planets[i].xAxis, planets[i].yAxis, planets[i].zAxis);
        }

        printf("\n");
    }

    return 0;
}