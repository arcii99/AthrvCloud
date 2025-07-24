//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430E-11 // Gravitational constant
#define AU 1.495979E11 // Astronomical unit
#define year 31557600 // Number of seconds in a year

// Structure for celestial body
struct Body {
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

// Function to calculate distance between two bodies
double distance(struct Body b1, struct Body b2) {
    double dx = b2.x - b1.x;
    double dy = b2.y - b1.y;
    double dz = b2.z - b1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Function to calculate the force due to gravity between two bodies
double force(struct Body b1, struct Body b2) {
    double r = distance(b1, b2);
    double f = G * b1.mass * b2.mass / (r*r);
    return f;
}

// Function to update the velocity and position of a single body
void update_body(struct Body *b, double fx, double fy, double fz, double dt) {
    double ax = fx / b->mass;
    double ay = fy / b->mass;
    double az = fz / b->mass;
    b->vx += ax * dt;
    b->vy += ay * dt;
    b->vz += az * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    b->z += b->vz * dt;
}

int main() {
    // Define celestial bodies
    struct Body sun = {1.9891E30, 696340, 0, 0, 0, 0, 0, 0};
    struct Body earth = {5.9736E24, 6378100, AU, 0, 0, 0, 29800, 0};
    struct Body moon = {7.3420E22, 1737100, AU + 384400000, 0, 0, 0, 29800 + 1022, 0};
    struct Body mars = {6.4171E23, 3396200, -1.524*(AU), 0, 0, 0, 24007, 0};
    
    // Define simulation parameters
    int num_steps = 5000;
    double dt = year / num_steps;
    
    // Run simulation for each time step
    for (int i = 0; i < num_steps; i++) {
        // Calculate force due to gravity between sun and earth
        double f_se = force(sun, earth);
        double fx_se = f_se * (sun.x - earth.x) / distance(sun, earth);
        double fy_se = f_se * (sun.y - earth.y) / distance(sun, earth);
        double fz_se = f_se * (sun.z - earth.z) / distance(sun, earth);
        
        // Calculate force due to gravity between earth and moon
        double f_em = force(earth, moon);
        double fx_em = f_em * (earth.x - moon.x) / distance(earth, moon);
        double fy_em = f_em * (earth.y - moon.y) / distance(earth, moon);
        double fz_em = f_em * (earth.z - moon.z) / distance(earth, moon);
        
        // Calculate force due to gravity between sun and mars
        double f_sm = force(sun, mars);
        double fx_sm = f_sm * (sun.x - mars.x) / distance(sun, mars);
        double fy_sm = f_sm * (sun.y - mars.y) / distance(sun, mars);
        double fz_sm = f_sm * (sun.z - mars.z) / distance(sun, mars);
        
        // Update velocity and position of each body
        update_body(&sun, -fx_se - fx_em - fx_sm, -fy_se - fy_em - fy_sm, -fz_se - fz_em - fz_sm, dt);
        update_body(&earth, fx_se - fx_em, fy_se - fy_em, fz_se - fz_em, dt);
        update_body(&moon, fx_em, fy_em, fz_em, dt);
        update_body(&mars, fx_sm, fy_sm, fz_sm, dt);
        
        // Print the position of the earth every 100th step
        if (i % 100 == 0) {
            printf("Step %d: Earth at (%f, %f, %f)\n", i, earth.x, earth.y, earth.z);
        }
    }
    
    return 0;
}