//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double x, y, z;
} vector;

typedef struct {
    vector pos, vel;
    double mass;
} planet;

const double G = 6.674 * pow(10,-11); // gravitational constant
const double timestep = 86400; // one day in seconds

planet planets[] = {
    {{0, 0, 0}, {0, 0, 0}, 1.989 * pow(10,30)}, // the sun
    {{0, 0, 1.47 * pow(10,11)}, {3.0 * pow(10,4), 0, 0}, 5.972 * pow(10,24)}, // earth
    {{0, 0, 1.07 * pow(10,11)}, {3.5 * pow(10,4), 0, 0}, 0.642 * pow(10,24)}, // venus
    {{0, 0, 2.28 * pow(10,11)}, {2.4 * pow(10,4), 0, 0}, 6.39 * pow(10,23)} // mars
};
const int num_planets = sizeof(planets) / sizeof(*planets);

void update_velocity(planet *a, planet *b) {
    vector r;
    double r_mag;
    double F_mag;
    vector F;
    
    r.x = b->pos.x - a->pos.x;
    r.y = b->pos.y - a->pos.y;
    r.z = b->pos.z - a->pos.z;
    r_mag = sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2));

    F_mag = G * a->mass * b->mass / pow(r_mag, 2);
    F.x = F_mag * r.x / r_mag;
    F.y = F_mag * r.y / r_mag;
    F.z = F_mag * r.z / r_mag;

    a->vel.x += F.x / a->mass * timestep;
    a->vel.y += F.y / a->mass * timestep;
    a->vel.z += F.z / a->mass * timestep;
}

void update_position(planet *a) {
    a->pos.x += a->vel.x * timestep;
    a->pos.y += a->vel.y * timestep;
    a->pos.z += a->vel.z * timestep;
}

void print_positions(int t) {
    printf("After %d days:\n", t);
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: x = %f, y = %f, z = %f\n", i + 1, planets[i].pos.x, planets[i].pos.y, planets[i].pos.z);
    }
}

int main() {
    const int num_iterations = 365 * 10; // ten years
    for (int t = 0; t < num_iterations; t++) {
        for (int i = 0; i < num_planets; i++) {
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    update_velocity(&planets[i], &planets[j]);
                }
            }
        }
        for (int i = 0; i < num_planets; i++) {
            update_position(&planets[i]);
        }
        if (t % 365 == 0) {
            print_positions(t / 365);
        }
    }

    return 0;
}