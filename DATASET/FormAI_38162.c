//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define G 6.674e-11
#define TIMESTEP 0.01

typedef struct {
    double x;
    double y;
    double z;
} vector;

typedef struct {
    char name[64];
    double mass;
    vector position;
    vector velocity;
    vector force;
} planet;

static double rand_double(double min, double max) {
    return ((double) rand() / RAND_MAX) * (max - min) + min;
}

static double distance(vector a, vector b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

static vector direction(vector a, vector b) {
    double d = distance(a, b);
    vector dir;
    dir.x = (b.x - a.x) / d;
    dir.y = (b.y - a.y) / d;
    dir.z = (b.z - a.z) / d;
    return dir;
}

static vector gravity(planet a, planet b) {
    double dist = distance(a.position, b.position);
    double grav = G * a.mass * b.mass / pow(dist, 2);
    vector dir = direction(a.position, b.position);
    vector g;
    g.x = grav * dir.x;
    g.y = grav * dir.y;
    g.z = grav * dir.z;
    return g;
}

static void update_velocity(planet *p, double dt) {
    vector accel;
    accel.x = p->force.x / p->mass;
    accel.y = p->force.y / p->mass;
    accel.z = p->force.z / p->mass;
    p->velocity.x += accel.x * dt;
    p->velocity.y += accel.y * dt;
    p->velocity.z += accel.z * dt;
}

static void update_position(planet *p, double dt) {
    p->position.x += p->velocity.x * dt;
    p->position.y += p->velocity.y * dt;
    p->position.z += p->velocity.z * dt;
}

int main() {
    srand(time(NULL));
    planet planets[2];
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.972e24;
    planets[0].position.x = 0.0;
    planets[0].position.y = 0.0;
    planets[0].position.z = 0.0;
    planets[0].velocity.x = 0.0;
    planets[0].velocity.y = 0.0;
    planets[0].velocity.z = 0.0;
    strcpy(planets[1].name, "Mars");
    planets[1].mass = 6.417e23;
    planets[1].position.x = 227.9e9;
    planets[1].position.y = 0.0;
    planets[1].position.z = 0.0;
    planets[1].velocity.x = 0.0;
    planets[1].velocity.y = 24.077e3;
    planets[1].velocity.z = 0.0;
    int timesteps = 10000;
    for (int i = 0; i < timesteps; i++) {
        for (int j = 0; j < 2; j++) {
            planets[j].force.x = 0.0;
            planets[j].force.y = 0.0;
            planets[j].force.z = 0.0;
            for (int k = 0; k < 2; k++) {
                if (j != k) {
                    vector g = gravity(planets[j], planets[k]);
                    planets[j].force.x += g.x;
                    planets[j].force.y += g.y;
                    planets[j].force.z += g.z;
                }
            }
        }
        for (int j = 0; j < 2; j++) {
            update_velocity(&planets[j], TIMESTEP);
            update_position(&planets[j], TIMESTEP);
        }
        printf("%d: %s: (%.3g, %.3g, %.3g)\n", i, planets[0].name, planets[0].position.x, planets[0].position.y, planets[0].position.z);
        printf("%d: %s: (%.3g, %.3g, %.3g)\n", i, planets[1].name, planets[1].position.x, planets[1].position.y, planets[1].position.z);
    }
    return 0;
}