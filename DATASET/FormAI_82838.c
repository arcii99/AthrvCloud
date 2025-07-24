//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: imaginative
#include <stdio.h>
#include <math.h>

#define G 6.674e-11   // gravitational constant
#define TIME_STEP  0.1 // time step between each calculation

typedef struct {
    double mass;
    double x, y, z;    // position in 3D space
    double vx, vy, vz; // velocity
} Body;

void updateBodyPositions(Body bodies[], int numBodies) {
    int i, j;
    double Fx, Fy, Fz; // force components
    double dx, dy, dz; // distance components
    double dist, distCubed;
    
    for (i = 0; i < numBodies; i++) {
        Fx = Fy = Fz = 0.0;
        for (j = 0; j < numBodies; j++) {
            if (j == i) {
                continue;
            }
            dx = bodies[j].x - bodies[i].x;
            dy = bodies[j].y - bodies[i].y;
            dz = bodies[j].z - bodies[i].z;
            dist = sqrt(dx*dx + dy*dy + dz*dz);
            distCubed = dist * dist * dist;
            Fx += G * bodies[i].mass * bodies[j].mass * dx / distCubed;
            Fy += G * bodies[i].mass * bodies[j].mass * dy / distCubed;
            Fz += G * bodies[i].mass * bodies[j].mass * dz / distCubed;
        }
        // update velocity
        bodies[i].vx += Fx / bodies[i].mass * TIME_STEP;
        bodies[i].vy += Fy / bodies[i].mass * TIME_STEP;
        bodies[i].vz += Fz / bodies[i].mass * TIME_STEP;
        
        // update position
        bodies[i].x += bodies[i].vx * TIME_STEP;
        bodies[i].y += bodies[i].vy * TIME_STEP;
        bodies[i].z += bodies[i].vz * TIME_STEP;
    }
}

int main() {
    int numBodies = 5;
    Body bodies[numBodies];
    bodies[0] = (Body) { 5.97e24, 0, 0, 0, 0, 0, 0 }; // Earth
    bodies[1] = (Body) { 7.35e22, 3.844e8, 0, 0, 0, 1022, 0 }; // Moon
    bodies[2] = (Body) { 0.107 * 5.97e24, 0, 0, 0, 0, 0, 29700 }; // ISS
    bodies[3] = (Body) { 0.5 * 7.35e22, 3.844e8, 0, 0, 0, -1022, 0 }; // fake moon
    bodies[4] = (Body) { 9.81 * 68.1, 0, 6371e3 + 42164e3, 0, 3052, 0, 0 }; // communication satellite
    
    int i;
    for (i = 0; i < 10000; i++) {
        updateBodyPositions(bodies, numBodies);
        printf("%f,%f,%f,%f,%f,%f,%f\n", bodies[0].x, bodies[0].y, bodies[0].z, bodies[1].x, bodies[1].y, bodies[1].z, bodies[2].z);
    }
    
    return 0;
}