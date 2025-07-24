//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: unmistakable
// Solar System Simulation program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.67e-11 // gravitational constant
#define TIME_STEP 86400 // time step in seconds

// Define struct for planet data
typedef struct {
    char name[10];
    double mass; // kg
    double radius; // m
    double pos[3]; // x, y, z position from sun in m
    double vel[3]; // x, y, z velocity in m/s
} Planet;

// Calculate distance between two planets
double distance(double pos1[3], double pos2[3]) {
    double x_diff = pos2[0] - pos1[0];
    double y_diff = pos2[1] - pos1[1];
    double z_diff = pos2[2] - pos1[2];
    return sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
}

// Calculate gravitational force between two planets
void gravitational_force(Planet *planet1, Planet *planet2, double *force) {
    double r = distance(planet1->pos, planet2->pos);
    double force_mag = GRAV_CONST * planet1->mass * planet2->mass / (r * r);
    
    for(int i = 0; i < 3; i++) {
        force[i] = force_mag * (planet2->pos[i] - planet1->pos[i]) / r;
    }
}

int main() {
    // Initialize planets
    Planet sun = {"Sun", 1.989e30, 6.96e8, {0, 0, 0}, {0, 0, 0}};
    Planet earth = {"Earth", 5.972e24, 6.378e6, {1.495e11, 0, 0}, {0, 2.978e4, 0}};
    Planet mars = {"Mars", 6.39e23, 3.39e6, {2.279e11, 0, 0}, {0, 2.407e4, 0}};

    // Simulate 1 year
    double time = 0;
    while(time < 365.25 * 24 * 60 * 60) {
        // Calculate forces on planets from each other
        double force_sun[3] = {0, 0, 0};
        double force_earth[3] = {0, 0, 0};
        double force_mars[3] = {0, 0, 0};
        
        gravitational_force(&earth, &sun, force_earth);
        gravitational_force(&mars, &sun, force_mars);
        gravitational_force(&earth, &mars, force_earth);
        gravitational_force(&sun, &earth, force_sun);
        gravitational_force(&mars, &earth, force_mars);
        gravitational_force(&sun, &mars, force_sun);
        
        // Update positions and velocities based on forces
        for(int i = 0; i < 3; i++) {
            earth.vel[i] += (force_sun[i] + force_mars[i]) / earth.mass * TIME_STEP;
            earth.pos[i] += earth.vel[i] * TIME_STEP;
            
            mars.vel[i] += (force_sun[i] + force_earth[i]) / mars.mass * TIME_STEP;
            mars.pos[i] += mars.vel[i] * TIME_STEP;
        }
        
        for(int i = 0; i < 3; i++) {
            sun.vel[i] += (-1 * (force_earth[i] + force_mars[i])) / sun.mass * TIME_STEP;
            sun.pos[i] += sun.vel[i] * TIME_STEP;
        }

        // Print planet positions
        printf("Time: %f s\n", time);
        printf("Sun: x=%e m, y=%e m, z=%e m\n", sun.pos[0], sun.pos[1], sun.pos[2]);
        printf("Earth: x=%e m, y=%e m, z=%e m\n", earth.pos[0], earth.pos[1], earth.pos[2]);
        printf("Mars: x=%e m, y=%e m, z=%e m\n", mars.pos[0], mars.pos[1], mars.pos[2]);
        printf("\n");
        
        // Increment time by one day
        time += TIME_STEP;
    }

    return 0;
}