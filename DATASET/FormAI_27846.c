//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: unmistakable
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11   // gravitational constant

typedef struct {    // structure to represent each planet
    double x;
    double y;
    double z;
    double mass;
    double vx;
    double vy;
    double vz;
} Planet;

void updateAcceleration(Planet *p1, Planet *p2, double *ax, double *ay, double *az) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double dist = sqrt(dx*dx + dy*dy + dz*dz);
    double force = G * p1->mass * p2->mass / (dist * dist);
    *ax += force * dx / dist / p1->mass;
    *ay += force * dy / dist / p1->mass;
    *az += force * dz / dist / p1->mass;
}

void updateVelocity(Planet *p, double ax, double ay, double az, double t) {
    p->vx += ax * t;
    p->vy += ay * t;
    p->vz += az * t;
}

void updatePosition(Planet *p, double t) {
    p->x += p->vx * t;
    p->y += p->vy * t;
    p->z += p->vz * t;
}

int main(void) {
    // initialize planets
    Planet planets[] = {
        {1.0, 0.0, 0.0, 5.0e+24, 0.0, 30.0e+3, 0.0},
        {0.0, 1.0, 0.0, 5.0e+24, -30.0e+3, 0.0, 0.0},
        {0.0, 0.0, 0.0, 1.0e+6, 0.0, 0.0, 0.0}
    };
    int numPlanets = sizeof(planets) / sizeof(Planet);

    double t = 1.0;     // time step in seconds
    double totalTime = 3.0 * 365.25 * 24.0 * 60.0 * 60.0;    // total simulation time in seconds

    for (double time = 0; time < totalTime; time += t) {
        // calculate accelerations
        for (int i = 0; i < numPlanets; i++) {
            double ax = 0.0;
            double ay = 0.0;
            double az = 0.0;
            for (int j = 0; j < numPlanets; j++) {
                if (i != j) {
                    updateAcceleration(&planets[i], &planets[j], &ax, &ay, &az);
                }
            }
            // update velocities and positions
            updateVelocity(&planets[i], ax, ay, az, t);
            updatePosition(&planets[i], t);
        }
        // print current positions of planets
        for (int i = 0; i < numPlanets; i++) {
            printf("Planet %d: (%f, %f, %f)\n", i+1, planets[i].x, planets[i].y, planets[i].z);
        }
        printf("\n");
    }

    return 0;
}