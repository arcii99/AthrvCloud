//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass; // mass
} planet;

void calcAccel(planet *p1, planet *p2, double *ax, double *ay, double *az) {
    
    // calculate distance between planets
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    
    // calculate gravitational force
    double f = G * p1->mass * p2->mass / (r*r);
    
    // calculate acceleration
    *ax = f * dx / r / p1->mass;
    *ay = f * dy / r / p1->mass;
    *az = f * dz / r / p1->mass;
}

void update(planet *p, double dt, double ax, double ay, double az) {
    
    // update velocity and position
    p->vx += dt * ax;
    p->vy += dt * ay;
    p->vz += dt * az;
    p->x += dt * p->vx;
    p->y += dt * p->vy;
    p->z += dt * p->vz;
}

int main() {
    
    // create planet objects
    planet sun = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.989e30};
    planet earth = {149.6e9, 0.0, 0.0, 0.0, 29783.0, 0.0, 5.972e24};
    
    // initialize variables
    double dt = 3600.0; // time step (1 hour)
    double t = 0.0; // time
    
    // simulation loop
    while (t < 31556952.0) { // 1 earth year
        
        // calculate acceleration for each planet
        double ax, ay, az;
        calcAccel(&sun, &earth, &ax, &ay, &az);
        
        // update velocity and position for each planet
        update(&sun, dt, 0.0, 0.0, 0.0);
        update(&earth, dt, ax, ay, az);
        
        // increment time
        t += dt;
    }
    
    // print final position of earth
    printf("Final position of Earth:\n");
    printf("x = %.2f km\n", earth.x / 1000.0);
    printf("y = %.2f km\n", earth.y / 1000.0);
    printf("z = %.2f km\n", earth.z / 1000.0);
    
    return 0;
}