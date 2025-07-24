//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: intelligent
#include <stdio.h>
#include <math.h>

#define G 6.674e-11  // gravitational constant
#define T 100        // total time of simulation
#define DT 0.1       // time step
#define N 2          // number of planets

typedef struct {
    double x, y;    // position
    double vx, vy;  // velocity
    double mass;    // mass
} Planet;

// function that calculates the distance between two planets
double distance(Planet *p1, Planet *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}

// function that calculates the gravitational force between two planets
void gravitational_force(Planet *p1, Planet *p2, double *fx, double *fy) {
    double r = distance(p1, p2);
    double f = G * p1->mass * p2->mass / (r*r);
    *fx = f * (p2->x - p1->x) / r;
    *fy = f * (p2->y - p1->y) / r;
}

// function that updates the velocity and position of a planet
void update_planet(Planet *p, double fx, double fy) {
    double ax = fx / p->mass;
    double ay = fy / p->mass;
    p->vx += ax * DT;
    p->vy += ay * DT;
    p->x += p->vx * DT;
    p->y += p->vy * DT;
}

int main() {

    Planet planets[N] = {{0, 0, 0, 0, 1e5}, {1e8, 0, 0, 1e4, 1e10}};
    // planet 1: located at the origin with mass 1e5 and no velocity
    // planet 2: located at (1e8, 0) with mass 1e10 and initial velocity of 1e4 in x-direction
    
    for (double t = 0; t < T; t += DT) {
        // calculate gravitational forces between all pairs of planets
        double fx[N] = {0}, fy[N] = {0};
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                double fxi, fyi, fxj, fyj;
                gravitational_force(&planets[i], &planets[j], &fxi, &fyi);
                fx[i] += fxi; fy[i] += fyi;
                fx[j] -= fxi; fy[j] -= fyi;
            }
        }
        // update velocities and positions of all planets
        for (int i = 0; i < N; i++) {
            update_planet(&planets[i], fx[i], fy[i]);
        }
        // output position of each planet at current time step
        for (int i = 0; i < N; i++) {
            printf("%.2f %.2f\n", planets[i].x, planets[i].y);
        }
    }

    return 0;
}