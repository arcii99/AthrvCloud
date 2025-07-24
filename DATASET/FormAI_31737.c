//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67428e-11 // gravitational constant
#define AU 149597870700 // astronomical unit (meters)

typedef struct {
    char name[20];
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

void calculateForce(Planet *p1, Planet *p2, double *fx, double *fy, double *fz) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double d = sqrt(dx * dx + dy * dy + dz * dz);
    double f = G * p1->mass * p2->mass / (d * d);
    *fx = f * dx / d;
    *fy = f * dy / d;
    *fz = f * dz / d;
}

void updatePosition(Planet *p, double timeStep) {
    p->x += p->vx * timeStep;
    p->y += p->vy * timeStep;
    p->z += p->vz * timeStep;
}

void updateVelocity(Planet *p, double fx, double fy, double fz, double timeStep) {
    p->vx += fx / p->mass * timeStep;
    p->vy += fy / p->mass * timeStep;
    p->vz += fz / p->mass * timeStep;
}

int main() {
    srand(time(NULL));
    Planet sun = {"Sun", 1.989e30, 696340000, 0, 0, 0, 0, 0, 0};
    Planet earth = {"Earth", 5.972e24, 6371000, 1 * AU, 0, 0, 0, 29800, 0};
    Planet moon = {"Moon", 7.342e22, 1737100, 1.0028 * AU, 0, 0, 0, 3070 + 29800, 0};
    Planet mars = {"Mars", 6.39e23, 3397000, 1.524 * AU, 0, 0, 0, 24130, 0};
    Planet planets[] = {earth, moon, mars};
    int numPlanets = sizeof(planets) / sizeof(Planet);
    double timeStep = 3600; // 1 hour
    double duration = 365 * 24 * 3600; // 1 year in seconds
    
    
    // print initial locations
    printf("Initial Locations:\n");
    for (int i = 0; i < numPlanets; i++) {
        printf("%s: (%.2e,%.2e,%.2e)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }
    
    // simulation loop
    double fx, fy, fz;
    for (double t = 0; t < duration; t += timeStep) {
        
        // calculate forces
        for (int i = 0; i < numPlanets; i++) {
            
            // reset forces
            fx = fy = fz = 0;
            
            for (int j = 0; j < numPlanets; j++) {
                if (i == j) continue;
                double pfx, pfy, pfz;
                calculateForce(&planets[i], &planets[j], &pfx, &pfy, &pfz);
                fx += pfx;
                fy += pfy;
                fz += pfz;
            }
        }
        
        // update positions and velocities
        for (int i = 0; i < numPlanets; i++) {
            updatePosition(&planets[i], timeStep);
            updateVelocity(&planets[i], fx, fy, fz, timeStep);
        }

        // print locations at certain intervals
        if ((int)t % 86400 == 0) { // every day
            printf("Locations at %.0f days:\n", t / 86400);
            for (int i = 0; i < numPlanets; i++) {
                printf("%s: (%.2e,%.2e,%.2e)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
            }
            printf("\n");
        }
    }
    
    return 0;
}