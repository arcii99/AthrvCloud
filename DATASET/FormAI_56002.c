//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PLANETS 10
#define G 6.674e-11

struct planet {
    double mass;
    double x, y;
    double vx, vy;
};

int main() {
    struct planet planets[MAX_PLANETS];
    int num_planets = 2;
    
    // Initialize srand
    srand(time(0));
    
    // Initialize planets' masses, positions, and velocities
    planets[0].mass = 5.97e24;
    planets[0].x = 0.0;
    planets[0].y = 0.0;
    planets[0].vx = 0.0;
    planets[0].vy = 0.0;
    
    planets[1].mass = 7.34e22;
    planets[1].x = 384400000.0;
    planets[1].y = 0.0;
    planets[1].vx = 0.0;
    planets[1].vy = 1022.0;
    
    // Add more planets
    for (int i = 2; i < num_planets; i++) {
        planets[i].mass = rand() % 100 + 1; // Random mass between 1 and 100
        planets[i].x = rand() % 10000 - 5000; // Random x position between -5000 and 5000
        planets[i].y = rand() % 10000 - 5000; // Random y position between -5000 and 5000
        planets[i].vx = rand() % 1000 - 500; // Random x velocity between -500 and 500
        planets[i].vy = rand() % 1000 - 500; // Random y velocity between -500 and 500
    }
    
    // Simulation Loop
    double delta_t = 1.0; // Time step
    double fx, fy, r, ax, ay;
    for (int t = 0; t < 1000; t++) { // Simulate for 1000 time steps
        for (int i = 0; i < num_planets; i++) {
            fx = fy = 0.0;
            for (int j = 0; j < num_planets; j++) {
                if (i == j) continue;
                r = sqrt(pow((planets[j].x - planets[i].x), 2) + pow((planets[j].y - planets[i].y), 2)); // Distance between two planets
                fx += G * planets[i].mass * planets[j].mass * (planets[j].x - planets[i].x) / pow(r, 3); // x component of force
                fy += G * planets[i].mass * planets[j].mass * (planets[j].y - planets[i].y) / pow(r, 3); // y component of force
            }
            ax = fx / planets[i].mass; // x component of acceleration
            ay = fy / planets[i].mass; // y component of acceleration
            planets[i].vx += ax * delta_t; // Update x velocity
            planets[i].vy += ay * delta_t; // Update y velocity
            planets[i].x += planets[i].vx * delta_t; // Update x position
            planets[i].y += planets[i].vy * delta_t; // Update y position
        }
    }
    
    // Print final positions
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: x=%lf y=%lf\n", i, planets[i].x, planets[i].y);
    }
    
    return 0;
}