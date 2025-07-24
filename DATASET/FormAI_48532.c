//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67408e-11    // gravitational constant

typedef struct PointMass {
    double mass;
    double pos[2];    // x and y position
    double vel[2];    // x and y velocity
    double acc[2];    // x and y acceleration
} PointMass;

// Distance formula to calculate distance between two point masses
double dist(PointMass p1, PointMass p2) {
    double dx = p2.pos[0] - p1.pos[0];
    double dy = p2.pos[1] - p1.pos[1];
    return sqrt(dx*dx + dy*dy);
}

// Updates the velocity, position, and acceleration of a point mass
void update(PointMass *p, double delta_t) {
    // Update velocity
    p->vel[0] += p->acc[0] * delta_t;
    p->vel[1] += p->acc[1] * delta_t;
    // Update position
    p->pos[0] += p->vel[0] * delta_t;
    p->pos[1] += p->vel[1] * delta_t;
    // Reset acceleration for next update
    p->acc[0] = 0;
    p->acc[1] = 0;
}

// Calculates the gravitational force between two point masses
double gravForce(PointMass p1, PointMass p2) {
    double r = dist(p1, p2);
    return (G * p1.mass * p2.mass) / (r*r);
}

// Updates the acceleration of a point mass based on the gravitational forces
// of all other point masses in the system
void updateAcceleration(PointMass *p, PointMass pm[], int n) {
    double fx = 0;
    double fy = 0;
    for (int i = 0; i < n; i++) {
        if (p == &pm[i]) {    // skip self
            continue;
        }
        double f = gravForce(*p, pm[i]);
        double theta = atan2(pm[i].pos[1] - p->pos[1], pm[i].pos[0] - p->pos[0]);
        fx += f * cos(theta);
        fy += f * sin(theta);
    }
    p->acc[0] = fx / p->mass;
    p->acc[1] = fy / p->mass;
}

int main() {
    srand(time(NULL));
    PointMass pm[3] = {
        {10000, {0, 0}, {0, 0}, {0, 0}},
        {100, {50, 0}, {0, 2}, {0, 0}},
        {100, {0, 50}, {-2, 0}, {0, 0}}
    };
    int n = sizeof(pm) / sizeof(PointMass);

    // Simulation parameters
    double delta_t = 0.01;
    double total_t = 10;

    for (double t = 0; t < total_t; t += delta_t) {
        for (int i = 0; i < n; i++) {
            updateAcceleration(&pm[i], pm, n);
        }
        for (int i = 0; i < n; i++) {
            update(&pm[i], delta_t);
            printf("Point mass %d: x = %lf, y = %lf\n", i, pm[i].pos[0], pm[i].pos[1]);
        }
        printf("\n");
    }

    return 0;
}