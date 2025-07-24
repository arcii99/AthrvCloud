//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: visionary
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant

typedef struct {
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double mass; // Mass
} Body;

int main() {

    // Define the gravitational bodies
    Body sun = {0, 0, 0, 0, 0, 0, 1.989e30}; // Sun
    Body earth = {1.496e11, 0, 0, 0, 29783, 0, 5.97e24}; // Earth
    Body moon= {1.496e11+384400000, 0, 0, 0, 29783+1022, 0, 7.342e22}; // Moon
    
    // Define the simulation parameters
    double dt = 3600; // Time step
    int steps = 8760; // Number of time steps in one year
    double time = 0; // Simulation time
    
    // Run the simulation
    for(int i=0; i<steps; i++) {

        // Compute the distances between the bodies
        double r_earth_sun = sqrt(pow(earth.x - sun.x, 2) + pow(earth.y - sun.y, 2) + pow(earth.z - sun.z, 2));
        double r_moon_earth = sqrt(pow(moon.x - earth.x, 2) + pow(moon.y - earth.y, 2) + pow(moon.z - earth.z, 2));
        double r_moon_sun = sqrt(pow(moon.x - sun.x, 2) + pow(moon.y - sun.y, 2) + pow(moon.z - sun.z, 2));
        
        // Compute the gravitational forces between the bodies
        double f_earth_sun = G * earth.mass * sun.mass / pow(r_earth_sun, 2);
        double f_moon_earth = G * moon.mass * earth.mass / pow(r_moon_earth, 2);
        double f_moon_sun = G * moon.mass * sun.mass / pow(r_moon_sun, 2);
        
        // Decompose the forces into x, y, z components
        double fx_earth_sun = f_earth_sun * (sun.x - earth.x)/r_earth_sun;
        double fy_earth_sun = f_earth_sun * (sun.y - earth.y)/r_earth_sun;
        double fz_earth_sun = f_earth_sun * (sun.z - earth.z)/r_earth_sun;
        double fx_moon_earth = f_moon_earth * (earth.x - moon.x)/r_moon_earth;
        double fy_moon_earth = f_moon_earth * (earth.y - moon.y)/r_moon_earth;
        double fz_moon_earth = f_moon_earth * (earth.z - moon.z)/r_moon_earth;
        double fx_moon_sun = f_moon_sun * (sun.x - moon.x)/r_moon_sun;
        double fy_moon_sun = f_moon_sun * (sun.y - moon.y)/r_moon_sun;
        double fz_moon_sun = f_moon_sun * (sun.z - moon.z)/r_moon_sun;
        
        // Update the velocities of the bodies
        earth.vx += dt * (fx_earth_sun + fx_moon_earth) / earth.mass;
        earth.vy += dt * (fy_earth_sun + fy_moon_earth) / earth.mass;
        earth.vz += dt * (fz_earth_sun + fz_moon_earth) / earth.mass;
        moon.vx += dt * (fx_moon_sun + fx_moon_earth) / moon.mass;
        moon.vy += dt * (fy_moon_sun + fy_moon_earth) / moon.mass;
        moon.vz += dt * (fz_moon_sun + fz_moon_earth) / moon.mass;
        sun.vx += dt * (-fx_earth_sun - fx_moon_sun) / sun.mass;
        sun.vy += dt * (-fy_earth_sun - fy_moon_sun) / sun.mass;
        sun.vz += dt * (-fz_earth_sun - fz_moon_sun) / sun.mass;
        
        // Update the positions of the bodies
        earth.x += dt * earth.vx;
        earth.y += dt * earth.vy;
        earth.z += dt * earth.vz;
        moon.x += dt * moon.vx;
        moon.y += dt * moon.vy;
        moon.z += dt * moon.vz;
        sun.x += dt * sun.vx;
        sun.y += dt * sun.vy;
        sun.z += dt * sun.vz;
        
        // Print the position of the Earth and the Moon
        if(i % 1000 == 0) {
            printf("Time: %f years, Earth: (%f, %f, %f), Moon: (%f, %f, %f)\n", time/31557600, earth.x, earth.y, earth.z, moon.x, moon.y, moon.z);
        }
        
        // Update the simulation time
        time += dt;
    }

    return 0;
}