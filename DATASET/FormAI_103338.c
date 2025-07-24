//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant, m^3/kg*s^2

typedef struct Planet {
    char name[20]; // planet name
    double mass; // mass, kg
    double radius; // radius, m
    double x; // x coordinate, m
    double y; // y coordinate, m
    double vx; // velocity in x direction, m/s
    double vy; // velocity in y direction, m/s
} Planet;

void calculateForce(Planet* p1, Planet* p2, double *fx, double *fy) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx * dx + dy * dy);
    double force = G * p1->mass * p2->mass / (distance * distance);
    *fx = force * dx / distance;
    *fy = force * dy / distance;
}

void updateVelocity(Planet* p1, Planet* p2, double t, double fx, double fy) {
    double ax = fx / p1->mass;
    double ay = fy / p1->mass;
    p1->vx += ax * t;
    p1->vy += ay * t;
}

void updatePosition(Planet* p, double t) {
    p->x += p->vx * t;
    p->y += p->vy * t;
}

void printPlanet(Planet p) {
    printf("%s: x=%.2e m, y=%.2e m, vx=%.2e m/s, vy=%.2e m/s\n", p.name, p.x, p.y, p.vx, p.vy);
}

int main() {
    int num_planets = 5;
    Planet planets[num_planets];

    // initialize planets
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.97e24;
    planets[0].radius = 6.37e6;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;

    strcpy(planets[1].name, "Moon");
    planets[1].mass = 7.34e22;
    planets[1].radius = 1.74e6;
    planets[1].x = 3.84e8;
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 1022;

    strcpy(planets[2].name, "Mars");
    planets[2].mass = 6.39e23;
    planets[2].radius = 3.39e6;
    planets[2].x = 2.28e11;
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = 240;

    strcpy(planets[3].name, "Venus");
    planets[3].mass = 4.87e24;
    planets[3].radius = 6.05e6;
    planets[3].x = 1.08e11;
    planets[3].y = 0;
    planets[3].vx = 0;
    planets[3].vy = 350;

    strcpy(planets[4].name, "Jupiter");
    planets[4].mass = 1.90e27;
    planets[4].radius = 6.99e7;
    planets[4].x = 7.78e11;
    planets[4].y = 0;
    planets[4].vx = 0;
    planets[4].vy = 130;

    // set random initial velocities
    srand(time(NULL));
    for (int i = 0; i < num_planets; i++) {
        double angle = (double) rand() / RAND_MAX * 2 * M_PI;
        double v = sqrt(G * planets[0].mass / sqrt(planets[i].x * planets[i].x + planets[i].y * planets[i].y));
        planets[i].vx = v * sin(angle);
        planets[i].vy = -v * cos(angle);
    }

    // simulate for 1 year
    double dt = 60 * 60 * 24 * 365; // time step, s
    int num_steps = 1000;
    for (int step = 0; step < num_steps; step++) {
        // calculate forces
        double fx[num_planets], fy[num_planets];
        for (int i = 0; i < num_planets; i++) {
            double net_fx = 0, net_fy = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i == j) continue;
                double fxij, fyij;
                calculateForce(&planets[i], &planets[j], &fxij, &fyij);
                net_fx += fxij;
                net_fy += fyij;
            }
            fx[i] = net_fx;
            fy[i] = net_fy;
        }

        // update velocities and positions
        for (int i = 0; i < num_planets; i++) {
            updateVelocity(&planets[i], &planets[0], dt, fx[i], fy[i]);
            updatePosition(&planets[i], dt);
        }
    }

    // print final positions and velocities
    for (int i = 0; i < num_planets; i++) {
        printPlanet(planets[i]);
    }

    return 0;
}