//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_PLANETS 5

double get_random(double min, double max) {
    return ((double) rand() / RAND_MAX) * (max - min) + min;
}

typedef struct {
    double x;
    double y;
    double z;
    double mass;
    double vx;
    double vy;
    double vz;
} planet;

planet planets[NUM_PLANETS];

void print_planet(planet p) {
    printf("Position: (%lf, %lf, %lf), Velocity: (%lf, %lf, %lf), Mass: %lf\n",
            p.x, p.y, p.z, p.vx, p.vy, p.vz, p.mass);
}

double distance_between(planet p1, planet p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void simulate(double dt, double duration) {
    int i, j;
    double distance, force, acceleration, ax, ay, az;
    for (double t = 0; t < duration; t += dt) {
        for (i = 0; i < NUM_PLANETS; i++) {
            ax = ay = az = 0.0;
            for (j = 0; j < NUM_PLANETS; j++) {
                if (i == j) continue;
                distance = distance_between(planets[i], planets[j]);
                force = (planets[i].mass * planets[j].mass) / (distance*distance);
                acceleration = force / planets[i].mass;
                ax += acceleration * (planets[j].x - planets[i].x) / distance;
                ay += acceleration * (planets[j].y - planets[i].y) / distance;
                az += acceleration * (planets[j].z - planets[i].z) / distance;
            }
            planets[i].vx += ax * dt;
            planets[i].vy += ay * dt;
            planets[i].vz += az * dt;
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
            planets[i].z += planets[i].vz * dt;
        }
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x = get_random(-10.0, 10.0);
        planets[i].y = get_random(-10.0, 10.0);
        planets[i].z = get_random(-10.0, 10.0);
        planets[i].mass = get_random(1.0, 100.0);
        planets[i].vx = get_random(-1.0, 1.0);
        planets[i].vy = get_random(-1.0, 1.0);
        planets[i].vz = get_random(-1.0, 1.0);
    }
    printf("Initial state:\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: ", i);
        print_planet(planets[i]);
    }
    simulate(0.1, 10.0);
    printf("Final state:\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: ", i);
        print_planet(planets[i]);
    }
    return 0;
}