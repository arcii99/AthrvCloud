//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: scalable
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238462643383279502884197

// Structure for planets
struct Planet {
    char name[50];
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
    double mass;
};

// Function to calculate distance between two planets
double distance(struct Planet p1, struct Planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Function to calculate gravitational attraction force between two planets
double attraction(struct Planet p1, struct Planet p2) {
    double r = distance(p1, p2);
    double force = (p1.mass * p2.mass) / (r*r);
    return force;
}

int main() {
    struct Planet sun = {"Sun", 0, 0, 0, 0, 0, 0, 1000}; // Mass of sun: 1000
    struct Planet earth = {"Earth", 150, 0, 0, 0, 29.29, 0, 10}; // Distance from sun to earth: 150, Mass of earth: 10
    struct Planet moon = {"Moon", 150.5, 0, 0, 0, 29.2, 0, 1}; // Distance from earth to moon: 0.5, Mass of moon: 1
    
    double time_step = 0.01; // Time step for simulation
    int num_steps = 10000; // Number of simulation steps
    double G = 6.674e-11; // Gravitational constant
    
    for (int i = 0; i < num_steps; i++) {
        double fx = 0, fy = 0, fz = 0; // Total force of earth
        double f_moon_x = 0, f_moon_y = 0, f_moon_z = 0; // Total force of moon
        
        // Calculate attraction forces between planets
        double f_sun_earth = attraction(sun, earth);
        double f_earth_sun = f_sun_earth;
        double f_sun_moon = attraction(sun, moon);
        double f_moon_sun = f_sun_moon;
        double f_earth_moon = attraction(earth, moon);
        double f_moon_earth = f_earth_moon;
        
        // Calculate individual components of force
        double fx_sun_earth = f_sun_earth * ((earth.x - sun.x) / distance(sun, earth));
        double fy_sun_earth = f_sun_earth * ((earth.y - sun.y) / distance(sun, earth));
        double fz_sun_earth = f_sun_earth * ((earth.z - sun.z) / distance(sun, earth));
        
        double fx_earth_sun = -fx_sun_earth;
        double fy_earth_sun = -fy_sun_earth;
        double fz_earth_sun = -fz_sun_earth;
        
        double fx_sun_moon = f_sun_moon * ((moon.x - sun.x) / distance(sun, moon));
        double fy_sun_moon = f_sun_moon * ((moon.y - sun.y) / distance(sun, moon));
        double fz_sun_moon = f_sun_moon * ((moon.z - sun.z) / distance(sun, moon));
        
        double fx_moon_sun = -fx_sun_moon;
        double fy_moon_sun = -fy_sun_moon;
        double fz_moon_sun = -fz_sun_moon;
        
        double fx_earth_moon = f_earth_moon * ((moon.x - earth.x) / distance(earth, moon));
        double fy_earth_moon = f_earth_moon * ((moon.y - earth.y) / distance(earth, moon));
        double fz_earth_moon = f_earth_moon * ((moon.z - earth.z) / distance(earth, moon));
        
        double fx_moon_earth = -fx_earth_moon;
        double fy_moon_earth = -fy_earth_moon;
        double fz_moon_earth = -fz_earth_moon;
        
        // Calculate total force acting on earth due to sun and moon
        fx += fx_sun_earth + fx_moon_earth;
        fy += fy_sun_earth + fy_moon_earth;
        fz += fz_sun_earth + fz_moon_earth;
        
        // Calculate total force acting on moon due to sun and earth
        f_moon_x += fx_sun_moon + fx_earth_moon;
        f_moon_y += fy_sun_moon + fy_earth_moon;
        f_moon_z += fz_sun_moon + fz_earth_moon;
        
        // Calculate acceleration of earth and moon
        double ax = fx / earth.mass;
        double ay = fy / earth.mass;
        double az = fz / earth.mass;
        
        double a_moon_x = f_moon_x / moon.mass;
        double a_moon_y = f_moon_y / moon.mass;
        double a_moon_z = f_moon_z / moon.mass;
        
        // Update velocities of earth and moon
        earth.vx += ax * time_step;
        earth.vy += ay * time_step;
        earth.vz += az * time_step;
        
        moon.vx += a_moon_x * time_step;
        moon.vy += a_moon_y * time_step;
        moon.vz += a_moon_z * time_step;
        
        // Update positions of earth and moon
        earth.x += earth.vx * time_step;
        earth.y += earth.vy * time_step;
        earth.z += earth.vz * time_step;
        
        moon.x += moon.vx * time_step;
        moon.y += moon.vy * time_step;
        moon.z += moon.vz * time_step;
        
        // Print position of earth and moon
        printf("Step %d: Earth: (%lf, %lf, %lf) Moon: (%lf, %lf, %lf)\n", i+1, earth.x, earth.y, earth.z, moon.x, moon.y, moon.z);
    }
    return 0;
}