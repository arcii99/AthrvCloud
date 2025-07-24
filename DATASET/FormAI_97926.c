//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: futuristic
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Define constants
#define G 6.67408e-11 // gravitational constant
#define MASS 1e6 // mass of each planet
#define TIMESTEP 0.1 // length of each time step

// Define struct for planets
typedef struct {
    double x; // x position
    double y; // y position
    double vx; // x velocity
    double vy; // y velocity
    double ax; // x acceleration
    double ay; // y acceleration
} Planet;

// Define function to calculate distance between two planets
double distance(Planet p1, Planet p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    // Initialize array of planets
    Planet planets[5];
    planets[0] = (Planet){0, 0, 0, 0, 0, 0};
    planets[1] = (Planet){1, 0, 0, 2, 0, 0};
    planets[2] = (Planet){0, 1, -2, 0, 0, 0};
    planets[3] = (Planet){-1, 0, 0, -2, 0, 0};
    planets[4] = (Planet){0, -1, 2, 0, 0, 0};
    
    // Initialize array of forces
    double forces[5][5] = {0};
    
    // Initialize time step counter
    int t = 0;
    
    // Run simulation for 100 time steps
    while (t < 100) {
        // Calculate forces between each pair of planets
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                double dist = distance(planets[i], planets[j]);
                double force = G * MASS * MASS / pow(dist, 2);
                double fx = force * (planets[j].x - planets[i].x) / dist;
                double fy = force * (planets[j].y - planets[i].y) / dist;
                forces[i][j] = fx;
                forces[j][i] = -fx;
                forces[i][i] -= fx;
                forces[j][j] -= fx;
                forces[i][j] = fy;
                forces[j][i] = -fy;
                forces[i][i] -= fy;
                forces[j][j] -= fy;
            }
        }
        
        // Update accelerations based on forces
        for (int i = 0; i < 5; i++) {
            planets[i].ax = forces[i][0] / MASS;
            planets[i].ay = forces[i][1] / MASS;
            for (int j = 1; j < 5; j++) {
                planets[i].ax += forces[i][j] / MASS;
                planets[i].ay += forces[j][i] / MASS;
            }
        }
        
        // Update velocities based on accelerations
        for (int i = 0; i < 5; i++) {
            planets[i].vx += planets[i].ax * TIMESTEP;
            planets[i].vy += planets[i].ay * TIMESTEP;
        }
        
        // Update positions based on velocities
        for (int i = 0; i < 5; i++) {
            planets[i].x += planets[i].vx * TIMESTEP;
            planets[i].y += planets[i].vy * TIMESTEP;
        }
        
        // Print current positions of planets
        printf("Time: %d\n", t);
        for (int i = 0; i < 5; i++) {
            printf("Planet %d: x = %f, y = %f\n", i, planets[i].x, planets[i].y);
        }
        
        // Increment time step counter
        t++;
    }
    
    return 0;
}