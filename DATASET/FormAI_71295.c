//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: active
#include <stdio.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Body;

int main() {
    // create the bodies
    Body sun = {1.98e30, 0, 0, 0, 0, 0, 0};
    Body earth = {5.97e24, 1.5e11, 0, 0, 0, 3e4, 0};
    
    // simulate for 1 year
    double dt = 60*60*24;
    int n = 365;
    for (int i = 0; i < n; i++) {
        // calculate the distance between the bodies
        double dx = earth.x - sun.x;
        double dy = earth.y - sun.y;
        double dz = earth.z - sun.z;
        double d = sqrt(dx*dx + dy*dy + dz*dz);
        
        // calculate the force of gravity
        double f = G * sun.mass * earth.mass / (d*d);
        
        // calculate the acceleration of earth
        double ax = f * dx / (earth.mass * d);
        double ay = f * dy / (earth.mass * d);
        double az = f * dz / (earth.mass * d);
        
        // update earth's velocity and position
        earth.vx += ax * dt;
        earth.vy += ay * dt;
        earth.vz += az * dt;
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;
        earth.z += earth.vz * dt;
        
        // print out earth's position
        printf("Day %d: (%.2f, %.2f, %.2f)\n", i+1, earth.x, earth.y, earth.z);
    }
    
    return 0;
}