//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double x, y;
} Vector;

typedef struct {
    double mass;
    Vector position, velocity;
} Body;

Vector subtractVectors(Vector a, Vector b) {
    Vector result = {a.x - b.x, a.y - b.y};
    return result;
}

double calculateDistance(Vector a, Vector b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

Vector calculateGravity(Body a, Body b) {
    double distance = calculateDistance(a.position, b.position);
    double force = G * a.mass * b.mass / (distance * distance);
    Vector direction = subtractVectors(b.position, a.position);
    double magnitude = force / sqrt(direction.x*direction.x + direction.y*direction.y);
    direction.x /= distance; direction.y /= distance;
    Vector gravity = {magnitude * direction.x, magnitude * direction.y};
    return gravity;
}

void updatePositions(Body bodies[], int num_bodies, double timestep) {
    for(int i = 0; i < num_bodies; i++) {
        bodies[i].position.x += timestep * bodies[i].velocity.x;
        bodies[i].position.y += timestep * bodies[i].velocity.y; 
    }
}

void updateVelocities(Body bodies[], int num_bodies, double timestep) {
    for(int i = 0; i < num_bodies; i++) {
        Vector net_gravity = {0, 0};
        for(int j = 0; j < num_bodies; j++) {
            if(i == j) continue;
            Vector g = calculateGravity(bodies[i], bodies[j]);
            net_gravity.x += g.x; net_gravity.y += g.y;
        }
        double ax = net_gravity.x / bodies[i].mass;
        double ay = net_gravity.y / bodies[i].mass;
        bodies[i].velocity.x += timestep * ax;
        bodies[i].velocity.y += timestep * ay; 
    }    
}

void simulate(Body bodies[], int num_bodies, double timestep, double duration) {
    int num_steps = (int)(duration / timestep);
    printf("Simulation started\n");
    for(int step = 0; step < num_steps; step++) {
        updatePositions(bodies, num_bodies, timestep);
        updateVelocities(bodies, num_bodies, timestep);
        printf("Step %d: ", step+1);
        for(int i = 0; i < num_bodies; i++) {
            printf("(%f, %f) ", bodies[i].position.x, bodies[i].position.y);
        }
        printf("\n");
    }
}

int main() {
    Body sun = {1.98e30, {0, 0}, {0, 0}};
    Body earth = {5.97e24, {147e9, 0}, {0, 30290}};
    Body moon = {7.34e22, {147e9+385e6, 0}, {0, 30290+1023}};
    Body mars = {6.42e23, {-244e9, 0}, {0, -24140}};
    Body jupiter = {1.9e27, {778e9, 0}, {0, 13060}};
    Body saturn = {5.69e26, {-1434e9, 0}, {0, -9690}};
    Body uranus = {8.68e25, {2871e9, 0}, {0, 6810}};
    Body neptune = {1.02e26, {-4504e9, 0}, {0, -5430}};
    Body bodies[] = {sun, earth, moon, mars, jupiter, saturn, uranus, neptune};
    int num_bodies = sizeof(bodies) / sizeof(Body);
    double timestep = 86400; // one day in seconds
    double duration = 365 * 60 * 60 * 24; // one year in seconds
    simulate(bodies, num_bodies, timestep, duration);
    return 0;
}