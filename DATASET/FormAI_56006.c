//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3 // number of planets
#define DIM 2 // number of dimensions

double G = 6.674e-11; // gravitational constant

struct planet {
    double mass;
    double position[DIM];
    double velocity[DIM];
    double acceleration[DIM];
};

void compute_acceleration(struct planet *p, struct planet planets[]) {
    int i;
    double r, force;
    for(i=0; i<N; i++) {
        if(p != &planets[i]) {
            r = sqrt(pow(p->position[0]-planets[i].position[0],2) + pow(p->position[1]-planets[i].position[1],2));
            force = G * p->mass * planets[i].mass / pow(r,2);
            p->acceleration[0] += force * (planets[i].position[0]-p->position[0]) / r / p->mass;
            p->acceleration[1] += force * (planets[i].position[1]-p->position[1]) / r / p->mass;
        }
    }
}

void compute_velocity(struct planet *p, double dt) {
    p->velocity[0] += p->acceleration[0] * dt;
    p->velocity[1] += p->acceleration[1] * dt;
}

void compute_position(struct planet *p, double dt) {
    p->position[0] += p->velocity[0] * dt;
    p->position[1] += p->velocity[1] * dt;
}

void print_planet(struct planet *p) {
    printf("m=%.3e\tx=%.3e\ty=%.3e\tvx=%.3e\tvy=%.3e\n", p->mass, p->position[0], p->position[1], p->velocity[0], p->velocity[1]);
}

void init_planets(struct planet planets[]) {
    int i;
    // sun
    planets[0].mass = 1.989e30;
    planets[0].position[0] = 0.0;
    planets[0].position[1] = 0.0;
    // earth
    planets[1].mass = 5.9742e24;
    planets[1].position[0] = 1.496e11;
    planets[1].position[1] = 0.0;
    planets[1].velocity[1] = 2.9783e4;
    // moon
    planets[2].mass = 7.342e22;
    planets[2].position[0] = 1.496e11 + 3.844e8;
    planets[2].position[1] = 0.0;
    planets[2].velocity[1] = 2.9783e4 + 1.022e3;
}

int main() {
    struct planet planets[N];
    init_planets(planets);
    double dt = 3600.0;
    int steps = 24*365;

    printf("t=0.00:\n");
    for(int i=0; i<N; i++)
        print_planet(&planets[i]);

    for(int s=1; s<=steps; s++) {
        printf("t=%.2f:\n", s*dt/3600/24/365);
        for(int i=0; i<N; i++) {
            planets[i].acceleration[0] = 0.0;
            planets[i].acceleration[1] = 0.0;
            compute_acceleration(&planets[i], planets);
            compute_velocity(&planets[i], dt);
            compute_position(&planets[i], dt);
            print_planet(&planets[i]);
        }
    }
    return 0;
}