//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.6743e-11
#define INTERVAL 10000

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double mass;
} planet_t;

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dz = z1 - z2;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void simulate(planet_t planets[], int num_planets) {
    int i, j;
    double ax, ay, az;
    double fx, fy, fz;
    double r;
    for (i = 0; i < num_planets; i++) {
        ax = ay = az = 0;
        for (j = 0; j < num_planets; j++) {
            if (i != j) {
                r = distance(planets[i].x, planets[i].y, planets[i].z, planets[j].x, planets[j].y, planets[j].z);
                fx = G * planets[i].mass * planets[j].mass * (planets[j].x - planets[i].x) / (r * r * r);
                fy = G * planets[i].mass * planets[j].mass * (planets[j].y - planets[i].y) / (r * r * r);
                fz = G * planets[i].mass * planets[j].mass * (planets[j].z - planets[i].z) / (r * r * r);
                ax += fx / planets[i].mass;
                ay += fy / planets[i].mass;
                az += fz / planets[i].mass;
            }
        }
        planets[i].vx += ax * INTERVAL;
        planets[i].vy += ay * INTERVAL;
        planets[i].vz += az * INTERVAL;
        planets[i].x += planets[i].vx * INTERVAL;
        planets[i].y += planets[i].vy * INTERVAL;
        planets[i].z += planets[i].vz * INTERVAL;
    }
}

void print(planet_t planets[], int num_planets) {
    int i;
    for (i = 0; i < num_planets; i++) {
        printf("Planet %d: (%.2f, %.2f, %.2f), Mass: %.2f, Velocity: (%.2f, %.2f, %.2f)\n", i + 1,
            planets[i].x, planets[i].y, planets[i].z, planets[i].mass, planets[i].vx, planets[i].vy, planets[i].vz);
    }
}

int main() {
    planet_t planets[8];
    int i;
    srand(time(NULL));
    for (i = 0; i < 8; i++) {
        planets[i].mass = rand() % 1000 + 100;
        planets[i].x = rand() % 500 - 250;
        planets[i].y = rand() % 500 - 250;
        planets[i].z = rand() % 500 - 250;
        planets[i].vx = rand() % 1000 - 500;
        planets[i].vy = rand() % 1000 - 500;
        planets[i].vz = rand() % 1000 - 500;
    }
    for (i = 0; i < 10000; i++) {
        simulate(planets, 8);
    }
    print(planets, 8);
    return 0;
}