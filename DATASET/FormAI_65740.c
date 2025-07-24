//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265

struct planet {
    char name[20];
    double radius;
    double mass;
    double distance;
    double angle;
    double velocity;
};

int main() {

    // Create an array of planets
    struct planet solar_system[9];

    // Initialize the data for each planet
    strcpy(solar_system[0].name, "Mercury");
    solar_system[0].radius = 2439.7;
    solar_system[0].mass = 3.285e23;
    solar_system[0].distance = 57910000;
    solar_system[0].angle = 0;
    solar_system[0].velocity = sqrt(6.6743e-11 * 1.989e30 / solar_system[0].distance);

    strcpy(solar_system[1].name, "Venus");
    solar_system[1].radius = 6051.8;
    solar_system[1].mass = 4.867e24;
    solar_system[1].distance = 108200000;
    solar_system[1].angle = 45;
    solar_system[1].velocity = sqrt(6.6743e-11 * 1.989e30 / solar_system[1].distance);

    strcpy(solar_system[2].name, "Earth");
    solar_system[2].radius = 6371;
    solar_system[2].mass = 5.972e24;
    solar_system[2].distance = 149600000;
    solar_system[2].angle = 90;
    solar_system[2].velocity = sqrt(6.6743e-11 * 1.989e30 / solar_system[2].distance);

    strcpy(solar_system[3].name, "Mars");
    solar_system[3].radius = 3389.5;
    solar_system[3].mass = 6.39e23;
    solar_system[3].distance = 227900000;
    solar_system[3].angle = 135;
    solar_system[3].velocity = sqrt(6.6743e-11 * 1.989e30 / solar_system[3].distance);

    strcpy(solar_system[4].name, "Jupiter");
    solar_system[4].radius = 69911;
    solar_system[4].mass = 1.898e27;
    solar_system[4].distance = 778500000;
    solar_system[4].angle = 180;
    solar_system[4].velocity = sqrt(6.6743e-11 * 1.989e30 / solar_system[4].distance);

    strcpy(solar_system[5].name, "Saturn");
    solar_system[5].radius = 58232;
    solar_system[5].mass = 5.683e26;
    solar_system[5].distance = 1433000000;
    solar_system[5].angle = 225;
    solar_system[5].velocity = sqrt(6.6743e-11 * 1.989e30 / solar_system[5].distance);

    strcpy(solar_system[6].name, "Uranus");
    solar_system[6].radius = 25362;
    solar_system[6].mass = 8.681e25;
    solar_system[6].distance = 2877000000;
    solar_system[6].angle = 270;
    solar_system[6].velocity = sqrt(6.6743e-11 * 1.989e30 / solar_system[6].distance);

    strcpy(solar_system[7].name, "Neptune");
    solar_system[7].radius = 24622;
    solar_system[7].mass = 1.024e26;
    solar_system[7].distance = 4503000000;
    solar_system[7].angle = 315;
    solar_system[7].velocity = sqrt(6.6743e-11 * 1.989e30 / solar_system[7].distance);

    strcpy(solar_system[8].name, "Pluto");
    solar_system[8].radius = 1187;
    solar_system[8].mass = 1.309e22;
    solar_system[8].distance = 5913000000;
    solar_system[8].angle = 360;
    solar_system[8].velocity = sqrt(6.6743e-11 * 1.989e30 / solar_system[8].distance);

    // Set up the simulation
    double dt = 86400; // One day timestep
    double time = 0; // Start the simulation at time 0

    // Loop through the simulation
    while (time < 365 * 86400) { // Run the simulation for one year
        for (int i = 0; i < 9; i++) {

            // Update angle
            solar_system[i].angle += solar_system[i].velocity * dt / solar_system[i].distance;

            // Calculate position
            double x = solar_system[i].distance * cos(solar_system[i].angle * PI / 180);
            double y = solar_system[i].distance * sin(solar_system[i].angle * PI / 180);

            // Print the position of each planet for one day
            printf("%s: %f, %f\n", solar_system[i].name, x, y);
        }

        // Move time forward
        time += dt;
    }

    return 0;
}