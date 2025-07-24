//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11 // universal gravitational constant
#define TOTAL_TIME 1000 // total simulation time
#define TIME_STEP 0.1 // time step size

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
} Body;

int main() {
    Body planet1 = {5.97e24, {0, 0, 0}, {0, 0, 0}}; // Earth
    Body planet2 = {6.39e23, {2.5e7, 0, 0}, {0, 3e4, 0}}; // Mars
    Body planet3 = {1.99e30, {1.5e11, 0, 0}, {0, 0, 0}}; // Sun
    Body planets[] = {planet1, planet2, planet3}; // array of all planets
    int num_planets = sizeof(planets) / sizeof(Body);

    double acceleration[num_planets][3];

    // Run simulation
    for (double time = 0; time < TOTAL_TIME; time += TIME_STEP) {
        // Calculate accelerations
        for (int i = 0; i < num_planets; i++) {
            acceleration[i][0] = acceleration[i][1] = acceleration[i][2] = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i == j) continue; // don't calculate self-gravity
                double distance[3];
                for (int k = 0; k < 3; k++) {
                    distance[k] = planets[j].position[k] - planets[i].position[k];
                }
                double dist = sqrt(distance[0]*distance[0] + distance[1]*distance[1] + distance[2]*distance[2]);
                double force = G * planets[i].mass * planets[j].mass / (dist*dist);
                for (int k = 0; k < 3; k++) {
                    acceleration[i][k] += force / planets[i].mass * distance[k] / dist;
                }
            }
        }
        // Update velocities and positions
        for (int i = 0; i < num_planets; i++) {
            for (int k = 0; k < 3; k++) {
                planets[i].velocity[k] += acceleration[i][k] * TIME_STEP;
                planets[i].position[k] += planets[i].velocity[k] * TIME_STEP;
            }
        }
        // Output planet positions
        printf("Time: %.1f   Earth: (%.2f, %.2f, %.2f)   Mars: (%.2f, %.2f, %.2f)   Sun: (%.2f, %.2f, %.2f)\n",
               time, planet1.position[0], planet1.position[1], planet1.position[2],
               planet2.position[0], planet2.position[1], planet2.position[2],
               planet3.position[0], planet3.position[1], planet3.position[2]);
    }
    
    return 0;
}