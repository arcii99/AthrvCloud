//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: systematic
#include <stdio.h>
#include <math.h>

#define G 6.674e-11     // Gravitational constant
#define NUM_PLANETS 3   // Number of planets in simulation
#define NUM_STEPS 365   // Number of simulation steps (days)

// A struct to represent a planet
typedef struct {
    char name[20];
    double mass;    
    double radius;
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
} Planet;

// A function to calculate the gravitational force between two planets
double calculate_force(Planet p1, Planet p2) {
    double distance = sqrt(pow(p1.pos_x - p2.pos_x, 2) + pow(p1.pos_y - p2.pos_y, 2));
    double force = (G * p1.mass * p2.mass) / pow(distance, 2);
    return force;
}

int main() {
    // Create an array to store all planets in simulation
    Planet planets[NUM_PLANETS];
    
    // Initialize the planets with their data
    planets[0] = (Planet){"Earth", 5.97e24, 6.37e6, 0, 0, 0, 29780};
    planets[1] = (Planet){"Mars", 6.39e23, 3.39e6, 2.27e11, 0, 0, 24007};
    planets[2] = (Planet){"Venus", 4.87e24, 6.05e6, 1.08e11, 0, 0, 35259};
    
    // Simulation loop
    for (int i = 0; i < NUM_STEPS; i++) {
        // Calculate the net force applied to each planet
        double forces_x[NUM_PLANETS] = {0};
        double forces_y[NUM_PLANETS] = {0};
        for (int j = 0; j < NUM_PLANETS; j++) {
            for (int k = 0; k < NUM_PLANETS; k++) {
                if (j == k) {
                    continue;
                }
                double force = calculate_force(planets[j], planets[k]);
                double distance = sqrt(pow(planets[j].pos_x - planets[k].pos_x, 2) + pow(planets[j].pos_y - planets[k].pos_y, 2));
                double angle = atan2(planets[k].pos_y - planets[j].pos_y, planets[k].pos_x - planets[j].pos_x);
                forces_x[j] += force * cos(angle);
                forces_y[j] += force * sin(angle);
            }
        }
        
        // Update each planet's position and velocity based on net force
        for (int j = 0; j < NUM_PLANETS; j++) {
            double acceleration_x = forces_x[j] / planets[j].mass;
            double acceleration_y = forces_y[j] / planets[j].mass;
            planets[j].vel_x += acceleration_x;
            planets[j].vel_y += acceleration_y;
            planets[j].pos_x += planets[j].vel_x;
            planets[j].pos_y += planets[j].vel_y;
        }
        
        // Print out the positions of each planet after each step
        printf("Day %d:\n", i + 1);
        for (int j = 0; j < NUM_PLANETS; j++) {
            printf("%s: (%.2e, %.2e)\n", planets[j].name, planets[j].pos_x, planets[j].pos_y);
        }
        printf("\n");
    }
    
    return 0;
}