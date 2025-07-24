//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.673*pow(10, -11)     // gravitational constant
#define DT 1                      // time increment
#define MAX_TIME 1000             // max simulation time

typedef struct {
    double x, y, z;              // position
    double vx, vy, vz;           // velocity
    double ax, ay, az;           // acceleration
    double mass;                 // mass
} Body;

void updateAcceleration(Body *bodies, int n) {
    int i, j;
    double dx, dy, dz, r, f, fx, fy, fz;
    
    for (i = 0; i < n; i++) {
        fx = fy = fz = 0;
        
        for (j = 0; j < n; j++) {
            if (i != j) {
                dx = bodies[j].x - bodies[i].x;
                dy = bodies[j].y - bodies[i].y;
                dz = bodies[j].z - bodies[i].z;
                r = sqrt(dx*dx + dy*dy + dz*dz);
                f = G*bodies[i].mass*bodies[j].mass/(r*r);
                fx += f*dx/r;
                fy += f*dy/r;
                fz += f*dz/r;
            }
        }
        
        bodies[i].ax = fx/bodies[i].mass;
        bodies[i].ay = fy/bodies[i].mass;
        bodies[i].az = fz/bodies[i].mass;
    }
}

void updateVelocity(Body *bodies, int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        bodies[i].vx += bodies[i].ax*DT;
        bodies[i].vy += bodies[i].ay*DT;
        bodies[i].vz += bodies[i].az*DT;
    }
}

void updatePosition(Body *bodies, int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        bodies[i].x += bodies[i].vx*DT;
        bodies[i].y += bodies[i].vy*DT;
        bodies[i].z += bodies[i].vz*DT;
    }
}

void printBodies(Body *bodies, int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        printf("Body %d:\n", i+1);
        printf("    Position: (%f, %f, %f)\n", bodies[i].x, bodies[i].y, bodies[i].z);
        printf("    Velocity: (%f, %f, %f)\n", bodies[i].vx, bodies[i].vy, bodies[i].vz);
        printf("    Acceleration: (%f, %f, %f)\n", bodies[i].ax, bodies[i].ay, bodies[i].az);
        printf("    Mass: %f\n", bodies[i].mass);
    }
}

int main() {
    Body bodies[3];
    int i, step;
    
    // set initial conditions
    bodies[0].x = 0;
    bodies[0].y = 0;
    bodies[0].z = 0;
    bodies[0].vx = 0;
    bodies[0].vy = 0;
    bodies[0].vz = 0;
    bodies[0].mass = 100000;
    
    bodies[1].x = 1000;
    bodies[1].y = 0;
    bodies[1].z = 0;
    bodies[1].vx = 0;
    bodies[1].vy = 6000;
    bodies[1].vz = 0;
    bodies[1].mass = 100;
    
    bodies[2].x = 0;
    bodies[2].y = 1000;
    bodies[2].z = 0;
    bodies[2].vx = -6000;
    bodies[2].vy = 0;
    bodies[2].vz = 0;
    bodies[2].mass = 500;
    
    // simulate
    for (step = 0; step < MAX_TIME; step++) {
        updateAcceleration(bodies, 3);
        updateVelocity(bodies, 3);
        updatePosition(bodies, 3);
        
        printf("Step %d:\n", step+1);
        printBodies(bodies, 3);
    }
    
    return 0;
}