//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: modular
#include<stdio.h>
#include<math.h>

#define N 3 // number of planets
#define G 6.674e-11 // gravitational constant
#define T 3600 // simulation time in seconds

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass; // mass
    double fx, fy, fz; // force
} planet;

void init(planet planets[N]) {
    planets[0] = (planet) {0, 0, 0, 0, 0, 0, 5.9742e24, 0, 0, 0}; // Earth
    planets[1] = (planet) {147e9, 0, 0, 0, 30300, 0, 7.342e22, 0, 0, 0}; // Moon
    planets[2] = (planet) {-147e9, 0, 0, 0, -30300, 0, 6.39e23, 0, 0, 0}; // Mars
}

double distance(planet* p1, planet* p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void update_forces(planet planets[N]) {
    for(int i = 0; i < N; i++) {
        planet* p1 = &planets[i];
        p1->fx = p1->fy = p1->fz = 0;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            planet* p2 = &planets[j];
            double r = distance(p1, p2);
            double f = G * p1->mass * p2->mass / (r*r);
            p1->fx += f * (p2->x - p1->x) / r;
            p1->fy += f * (p2->y - p1->y) / r;
            p1->fz += f * (p2->z - p1->z) / r;
        }
    }
}

void update_positions(planet planets[N], double dt) {
    for(int i = 0; i < N; i++) {
        planet* p = &planets[i];
        p->x += p->vx*dt;
        p->y += p->vy*dt;
        p->z += p->vz*dt;
    }
}

void update_velocities(planet planets[N], double dt) {
    for(int i = 0; i < N; i++) {
        planet* p = &planets[i];
        p->vx += p->fx/p->mass*dt;
        p->vy += p->fy/p->mass*dt;
        p->vz += p->fz/p->mass*dt;
    }
}

void print_positions(planet planets[N]) {
    for(int i = 0; i < N; i++) {
        planet* p = &planets[i];
        printf("Planet %d: (%.2f, %.2f, %.2f)\n", i+1, p->x, p->y, p->z);
    }
}

int main() {
    planet planets[N];
    init(planets);
    double dt = 10;
    for(int i = 0; i < T; i += dt) {
        update_forces(planets);
        update_positions(planets, dt);
        update_velocities(planets, dt);
    }
    print_positions(planets);
    return 0;
}