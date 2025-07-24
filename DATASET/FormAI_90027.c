//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational Constant

struct planet {
    double mass; 
    double x;
    double y;
    double xVelocity;
    double yVelocity;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void simulateGravity(struct planet *p, int n, double timeStep) {
    for(int i = 0; i < n; i++) {
        double Fx = 0, Fy = 0;
        
        for(int j = 0; j < n; j++) {
            if(i == j) { // skipping self
                continue;
            }
            double r = distance(p[i].x, p[i].y, p[j].x, p[j].y); // distance between two planets
            double F = G * p[i].mass * p[j].mass / pow(r, 2); // gravitational force
            double angle = atan2(p[j].y - p[i].y, p[j].x - p[i].x); // angle between two planets
            Fx += F * cos(angle);
            Fy += F * sin(angle);
        }
        
        double Ax = Fx / p[i].mass;
        double Ay = Fy / p[i].mass;
        p[i].xVelocity += Ax * timeStep; // updating velocity 
        p[i].yVelocity += Ay * timeStep; // updating velocity
        p[i].x += p[i].xVelocity * timeStep; // updating position
        p[i].y += p[i].yVelocity * timeStep; // updating position
    }
}

int main() {
    int numPlanets = 2;
    double timeStep = 1.0;
    struct planet *planets = (struct planet *) malloc(numPlanets * sizeof(struct planet));
    planets[0].mass = 5.972e24; // Earth's mass
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].xVelocity = 0;
    planets[0].yVelocity = 0;
    planets[1].mass = 7.342e22; // Moon's mass
    planets[1].x = 3.84e8; // distance from Earth 
    planets[1].y = 0;
    planets[1].xVelocity = 0;
    planets[1].yVelocity = 1022; // Moon's orbital velocity
    
    printf("Initial Positions:\n");
    for(int i = 0; i < numPlanets; i++) {
        printf("Planet %d: (%f, %f)\n", i+1, planets[i].x, planets[i].y);
    }
    
    for(int i = 0; i < 365; i++) { // running simulation for 1 year (365 days)
        simulateGravity(planets, numPlanets, timeStep);
    }
    
    printf("Final Positions:\n");
    for(int i = 0; i < numPlanets; i++) {
        printf("Planet %d: (%f, %f)\n", i+1, planets[i].x, planets[i].y);
    }
    free(planets);
    return 0;
}