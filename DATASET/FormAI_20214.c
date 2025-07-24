//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G_CONST 6.674 * pow(10, -11)
#define TIME_STEP 1800 // 30 minutes in seconds

struct planet {
    char name[20];
    double mass;
    double radius;
    double position[3];
    double velocity[3];
};

double distancesq(double x1, double y1, double z1, double x2, double y2, double z2) {
    return pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2);
}

double force(double m1, double m2, double r) {
    return (G_CONST * m1 * m2) / pow(r, 2);
}

void update_velocity(double m1, double m2, double r, double v1[3], double v2[3], double dt) {
    double f = force(m1, m2, r);
    double dvx = (f * (v2[0] - v1[0])) / (r * m1) * dt;
    double dvy = (f * (v2[1] - v1[1])) / (r * m1) * dt;
    double dvz = (f * (v2[2] - v1[2])) / (r * m1) * dt;
    v1[0] += dvx;
    v1[1] += dvy;
    v1[2] += dvz;
    v2[0] -= dvx;
    v2[1] -= dvy;
    v2[2] -= dvz;
}

void update_position(double p[3], double v[3], double dt) {
    p[0] += v[0] * dt;
    p[1] += v[1] * dt;
    p[2] += v[2] * dt;
}

int main() {
    srand(time(NULL));
    struct planet earth = {"Earth", 5.972 * pow(10, 24), 6371000, {0, 0, 0}, {0, 0, 0}};
    struct planet asteroid1 = {"Asteroid1", rand() % ((int) pow(10, 22)) + pow(10, 20), rand() % 5000000 + 5000000, {pow(10, 10), 0, 0}, {0, 3000, 0}};
    struct planet asteroid2 = {"Asteroid2", rand() % ((int) pow(10, 22)) + pow(10, 20), rand() % 5000000 + 5000000, {0, pow(10, 10), 0}, {-3000, 0, 0}};
    struct planet mars = {"Mars", 6.39 * pow(10, 23), 3389500, {0, 0, pow(10, 11)}, {2400, 0, 0}};

    for (int t = 0; t < 365 * 24 * 60 * 60; t += TIME_STEP) {
        double d1 = sqrt(distancesq(earth.position[0], earth.position[1], earth.position[2], asteroid1.position[0], asteroid1.position[1], asteroid1.position[2]));
        double d2 = sqrt(distancesq(earth.position[0], earth.position[1], earth.position[2], asteroid2.position[0], asteroid2.position[1], asteroid2.position[2]));
        double d3 = sqrt(distancesq(earth.position[0], earth.position[1], earth.position[2], mars.position[0], mars.position[1], mars.position[2]));
        update_velocity(earth.mass, asteroid1.mass, d1, earth.velocity, asteroid1.velocity, TIME_STEP);
        update_velocity(earth.mass, asteroid2.mass, d2, earth.velocity, asteroid2.velocity, TIME_STEP);
        update_velocity(earth.mass, mars.mass, d3, earth.velocity, mars.velocity, TIME_STEP);
        update_velocity(asteroid1.mass, asteroid2.mass, sqrt(distancesq(asteroid1.position[0], asteroid1.position[1], asteroid1.position[2], asteroid2.position[0], asteroid2.position[1], asteroid2.position[2])), asteroid1.velocity, asteroid2.velocity, TIME_STEP);
        update_velocity(mars.mass, asteroid1.mass, sqrt(distancesq(mars.position[0], mars.position[1], mars.position[2], asteroid1.position[0], asteroid1.position[1], asteroid1.position[2])), mars.velocity, asteroid1.velocity, TIME_STEP);
        update_velocity(mars.mass, asteroid2.mass, sqrt(distancesq(mars.position[0], mars.position[1], mars.position[2], asteroid2.position[0], asteroid2.position[1], asteroid2.position[2])), mars.velocity, asteroid2.velocity, TIME_STEP);
        update_position(earth.position, earth.velocity, TIME_STEP);
        update_position(asteroid1.position, asteroid1.velocity, TIME_STEP);
        update_position(asteroid2.position, asteroid2.velocity, TIME_STEP);
        update_position(mars.position, mars.velocity, TIME_STEP);

        printf("Day %d:\n", t / (24 * 60 * 60));
        printf("%s: (%.2f, %.2f, %.2f)\n", earth.name, earth.position[0], earth.position[1], earth.position[2]);
        printf("%s: (%.2f, %.2f, %.2f)\n", asteroid1.name, asteroid1.position[0], asteroid1.position[1], asteroid1.position[2]);
        printf("%s: (%.2f, %.2f, %.2f)\n", asteroid2.name, asteroid2.position[0], asteroid2.position[1], asteroid2.position[2]);
        printf("%s: (%.2f, %.2f, %.2f)\n", mars.name, mars.position[0], mars.position[1], mars.position[2]);
        printf("\n");
    }

    return 0;
}