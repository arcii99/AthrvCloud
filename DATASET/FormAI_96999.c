//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define GR 6.67408E-11        // gravitational constant

// structure to hold information about a planet
struct planet {
    char name[20];
    double mass, radius;
    double x, y, z;          // current position
    double vx, vy, vz;       // current velocity
};

// function to calculate force between two planets
void calculateForce(struct planet* p1, struct planet* p2, double* fx, double* fy, double* fz) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = GR * p1->mass * p2->mass / (r*r);
    *fx = f * dx / r;
    *fy = f * dy / r;
    *fz = f * dz / r;
}

// main program
int main() {
    // create two planets
    struct planet p1 = {"Earth", 5.972E24, 6371E3, 0, 0, 0, 0, 0, 0};
    struct planet p2 = {"Moon", 7.348E22, 1737E3, 384400E3, 0, 0, 0, 1022, 0};
    
    // simulation parameters
    double dt = 60;
    double maxTime = 24*3600*365.25;   // one year
    int steps = maxTime / dt;
    
    // simulation loop
    for (int i = 0; i < steps; i++) {
        // calculate force between planets
        double fx12, fy12, fz12;
        calculateForce(&p1, &p2, &fx12, &fy12, &fz12);
        double fx21 = -fx12, fy21 = -fy12, fz21 = -fz12;

        // update velocities
        p1.vx += fx21 / p1.mass * dt;
        p1.vy += fy21 / p1.mass * dt;
        p1.vz += fz21 / p1.mass * dt;
        p2.vx += fx12 / p2.mass * dt;
        p2.vy += fy12 / p2.mass * dt;
        p2.vz += fz12 / p2.mass * dt;

        // update positions
        p1.x += p1.vx * dt;
        p1.y += p1.vy * dt;
        p1.z += p1.vz * dt;
        p2.x += p2.vx * dt;
        p2.y += p2.vy * dt;
        p2.z += p2.vz * dt;
        
        // output current positions
        printf("t = %.2f days: %s (%.1f kg) at (%.0f, %.0f, %.0f) m\n",
               i*dt/3600/24, p1.name, p1.mass, p1.x, p1.y, p1.z);
        printf("t = %.2f days: %s (%.1f kg) at (%.0f, %.0f, %.0f) m\n",
               i*dt/3600/24, p2.name, p2.mass, p2.x, p2.y, p2.z);
    }
    
    return 0;
}