//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67 * pow(10, -11)

typedef struct Planet { // Define a custom datatype for a planet
    double mass;
    double x, y;
    double vx, vy;
} Planet;

// Function to calculate the distance between two planets
double distance(Planet p1, Planet p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to calculate the force between two planets
double force(Planet p1, Planet p2) {
    return G * ((p1.mass * p2.mass) / pow(distance(p1, p2), 2));
}

int main() {
    // Create an array of 3 planets
    Planet planets[3];

    // Initialize planet properties
    planets[0].mass = 5.97 * pow(10, 24);
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;

    planets[1].mass = 1.99 * pow(10, 30);
    planets[1].x = 1.496 * pow(10, 11);
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 29783;

    planets[2].mass = 6.39 * pow(10, 23);
    planets[2].x = 0;
    planets[2].y = 2.279 * pow(10, 11);
    planets[2].vx = 24007;
    planets[2].vy = 0;

    // Simulate the movement of the planets
    int iterations = 10000; // Simulate 10,000 iterations
    double delta_t = 1000; // Time step of 1,000 seconds
    for (int i = 0; i < iterations; i++) {
        // Calculate the net force on each planet
        for (int j = 0; j < 3; j++) {
            double net_fx = 0;
            double net_fy = 0;

            for (int k = 0; k < 3; k++) {
                if (j != k) { // Do not calculate force on itself
                    double f = force(planets[j], planets[k]);
                    double angle = atan2(planets[k].y - planets[j].y, planets[k].x - planets[j].x);
                    net_fx += f * cos(angle);
                    net_fy += f * sin(angle);
                }
            }

            // Calculate the acceleration of each planet based on the net force
            double ax = net_fx / planets[j].mass;
            double ay = net_fy / planets[j].mass;

            // Update the velocity and position of each planet
            planets[j].vx += ax * delta_t;
            planets[j].vy += ay * delta_t;
            planets[j].x += planets[j].vx * delta_t;
            planets[j].y += planets[j].vy * delta_t;
        }

        printf("Iteration: %d\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Planet %d: x = %f, y = %f\n", j + 1, planets[j].x, planets[j].y);
        }
        printf("\n");
    }

    return 0;
}