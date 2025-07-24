//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant
#define M 5.97e24  // mass of the Earth
#define DT 1000 // time step in seconds

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double mass; // mass of the planet
} Planet;

void update_position(Planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void update_velocity(Planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
}

void reset_acceleration(Planet *p) {
    p->ax = 0;
    p->ay = 0;
}

void update_acceleration(Planet *p, Planet *other) {
    double dx = other->x - p->x;
    double dy = other->y - p->y;
    double r = sqrt(dx*dx + dy*dy);
    double f = G * p->mass * other->mass / (r*r);
    p->ax += f * dx / r / p->mass;
    p->ay += f * dy / r / p->mass;
}

void simulate(Planet *planets, int num_planets, double dt) {
    for(int i = 0; i < num_planets; i++){
        reset_acceleration(&planets[i]);
    }
    for(int i = 0; i < num_planets; i++){
        for(int j = i + 1; j < num_planets; j++){
            update_acceleration(&planets[i], &planets[j]);
            update_acceleration(&planets[j], &planets[i]);
        }
    }
    for(int i = 0; i < num_planets; i++){
        update_velocity(&planets[i], dt);
        update_position(&planets[i], dt);
    }
}

void print_planets(Planet *planets, int num_planets) {
    for(int i = 0; i < num_planets; i++) {
        printf("Planet %d: x=%lf y=%lf vx=%lf vy=%lf\n", i, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
    }
}

int main() {
    Planet earth = {0, 0, 0, 0, 0, M};
    Planet moon = {384400000, 0, 0, 1022, 0, 7.342e22};
    Planet planets[] = {earth, moon};
    int num_planets = sizeof(planets) / sizeof(planets[0]);
    double t = 0;
    while(t < 86400 * 365 * 10) { // simulate 10 years
        simulate(planets, num_planets, DT);
        t += DT;
        printf("Time: %lf\n", t);
        print_planets(planets, num_planets);
    }
    return 0;
}