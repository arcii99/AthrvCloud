//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11     // gravitational constant in m^3/(kg*s^2)

typedef struct {
    double x, y, z;     // position vector
    double vx, vy, vz;  // velocity vector
    double fx, fy, fz;  // net force vector in x,y,z
    double mass;        // mass of the planet
} Planet;

void update_force(Planet* p1, Planet* p2) {
    // calculate the gravitational force between two planets
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1->mass * p2->mass / (r*r);
    
    // update the force vectors of each planet
    p1->fx -= f * (dx/r);
    p1->fy -= f * (dy/r);
    p1->fz -= f * (dz/r);
    p2->fx += f * (dx/r);
    p2->fy += f * (dy/r);
    p2->fz += f * (dz/r);
}

void update_velocity(Planet* p, double dt) {
    // update the velocity vector using the net force vector
    p->vx += (p->fx / p->mass) * dt;
    p->vy += (p->fy / p->mass) * dt;
    p->vz += (p->fz / p->mass) * dt;
}

void update_position(Planet* p, double dt) {
    // update the position vector using the velocity vector
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    // set up the simulation constants
    double dt = 3600;   // one hour in seconds
    Planet planets[3] = {
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 5.97e24},
        {{384400000, 0, 0}, {0, 1022, 0}, {0, 0, 0}, 7.349e22},
        {{0, 0, 149600000}, {29290, 0, 0}, {0, 0, 0}, 1.99e30}
    };
    
    // simulate the gravitational dynamics for 1 year
    int num_steps = (365*24*3600) / dt;
    for (int step = 0; step < num_steps; step++) {
        // reset the force vectors for each planet
        for (int p = 0; p < 3; p++) {
            planets[p].fx = 0;
            planets[p].fy = 0;
            planets[p].fz = 0;
        }
        
        // calculate the net force on each planet
        for (int i = 0; i < 2; i++) {
            for (int j = i+1; j < 3; j++) {
                update_force(&planets[i], &planets[j]);
            }
        }
        
        // update the velocity and position vectors for each planet
        for (int p = 0; p < 3; p++) {
            update_velocity(&planets[p], dt);
            update_position(&planets[p], dt);
        }
        
        // print the position of each planet
        printf("Step %d:\n", step+1);
        for (int p = 0; p < 3; p++) {
            printf("Planet %d: (%f, %f, %f)\n", p+1, planets[p].x, planets[p].y, planets[p].z);
        }
    }
    
    return 0;
}