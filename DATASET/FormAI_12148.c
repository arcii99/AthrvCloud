//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define G 6.67408e-11 // The gravitational constant

/**
 * A structure to hold information about a planet
 */
typedef struct Planet {
    char name[50];
    double mass;
    double radius;
    double x;
    double y;
    double vx;
    double vy;
} Planet;

/**
 * A function to calculate the gravitational force between two planets
 */
double gravitationalForce(Planet p1, Planet p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double distance = sqrt(dx*dx + dy*dy);
    double force = G * p1.mass * p2.mass / (distance * distance);
    return force;
}

/**
 * A function to update the velocity and position of a planet
 * based on the gravitational force of all other planets
 */
void updatePlanet(Planet *p, Planet *planets, int numPlanets, double timestep) {
    double fx = 0;
    double fy = 0;
    for (int i = 0; i < numPlanets; i++) {
        if (strcmp(p->name, planets[i].name) != 0) {
            double force = gravitationalForce(*p, planets[i]);
            double dx = planets[i].x - p->x;
            double dy = planets[i].y - p->y;
            fx += force * dx / sqrt(dx*dx + dy*dy);
            fy += force * dy / sqrt(dx*dx + dy*dy);
        }
    }
    double ax = fx / p->mass;
    double ay = fy / p->mass;
    p->vx += ax * timestep;
    p->vy += ay * timestep;
    p->x += p->vx * timestep;
    p->y += p->vy * timestep;
}

int main() {
    // Create some planets
    Planet sun = {"Sun", 1.989e30, 695.7e6, 0, 0, 0, 0};
    Planet earth = {"Earth", 5.972e24, 6.371e6, 147.09e9, 0, 0, 29.29e3};
    Planet mars = {"Mars", 6.39e23, 3.389e6, 206.62e9, 0, 0, 21.97e3};
    
    // Place the planets in an array
    Planet planets[] = {sun, earth, mars};
    int numPlanets = 3;
    
    // Set up the simulation parameters
    double timestep = 3600; // 1 hour
    double duration = 2 * 365 * 24 * 3600; // 2 years
    
    // Run the simulation
    for (double time = 0; time < duration; time += timestep) {
        for (int i = 0; i < numPlanets; i++) {
            updatePlanet(&planets[i], planets, numPlanets, timestep);
        }
        printf("Time: %g\n", time);
        for (int i = 0; i < numPlanets; i++) {
            printf("%s: (%g, %g)\n", planets[i].name, planets[i].x, planets[i].y);
        }
    }
    
    return 0;
}