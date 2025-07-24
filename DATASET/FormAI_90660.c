//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // Gravitational constant
#define N 100 // Number of planets
#define T 31536000 // Time step (seconds in a year)

struct Planet {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
};

typedef struct Planet Planet;

void simulate(Planet* planets, int n, double dt);
void calculate_acceleration(Planet* p1, Planet* p2, double* ax, double* ay);
double calculate_distance(Planet* p1, Planet* p2);

int main() {
    int i;
    Planet planets[N];

    // Set up initial conditions
    for (i = 0; i < N; i++) {
        planets[i].mass = rand() % 100;
        planets[i].x = rand() % 1000;
        planets[i].y = rand() % 1000;
        planets[i].vx = rand() % 10;
        planets[i].vy = rand() % 10;
    }

    // Simulate for 100 years
    for (i = 0; i < 100; i++) {
        simulate(planets, N, T);
    }

    return 0;
}

void simulate(Planet* planets, int n, double dt) {
    int i, j;
    double ax, ay, d;

    for (i = 0; i < n; i++) {
        ax = 0;
        ay = 0;

        for (j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            calculate_acceleration(&planets[i], &planets[j], &ax, &ay);
        }

        // Update position and velocity
        planets[i].x += planets[i].vx * dt + 0.5 * ax * dt * dt;
        planets[i].y += planets[i].vy * dt + 0.5 * ay * dt * dt;
        planets[i].vx += ax * dt;
        planets[i].vy += ay * dt;
    }
}

void calculate_acceleration(Planet* p1, Planet* p2, double* ax, double* ay) {
    double d = calculate_distance(p1, p2);
    double f = G * p1->mass * p2->mass / (d * d);

    *ax += f / p1->mass * (p2->x - p1->x) / d;
    *ay += f / p1->mass * (p2->y - p1->y) / d;
}

double calculate_distance(Planet* p1, Planet* p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;

    return sqrt(dx * dx + dy * dy);
}