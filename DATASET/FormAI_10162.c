//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TIME_STEP 0.01
#define GRAVITATIONAL_CONSTANT 6.674e-11
#define NUM_PLANETS 3

struct planet {
    double mass;
    double x, y, z;
    double v_x, v_y, v_z;
};

void update_positions(struct planet* planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].v_x * TIME_STEP;
        planets[i].y += planets[i].v_y * TIME_STEP;
        planets[i].z += planets[i].v_z * TIME_STEP;
    }
}

void update_velocities(struct planet* planets) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        double a_x = 0.0;
        double a_y = 0.0;
        double a_z = 0.0;
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i == j) {
                continue;
            }
            double r_x = planets[j].x - planets[i].x;
            double r_y = planets[j].y - planets[i].y;
            double r_z = planets[j].z - planets[i].z;
            double r = pow(r_x * r_x + r_y * r_y + r_z * r_z, 1.5);
            double a = GRAVITATIONAL_CONSTANT * planets[j].mass / r;
            a_x += a * r_x;
            a_y += a * r_y;
            a_z += a * r_z;
        }
        planets[i].v_x += a_x * TIME_STEP;
        planets[i].v_y += a_y * TIME_STEP;
        planets[i].v_z += a_z * TIME_STEP;
    }
}

int main() {
    struct planet planets[] = {
        {5.97e24, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {7.34e22, 0.0, 3.84e8, 0.0, 1022.0, 0.0, 0.0},
        {1.89e27, 1.5e11, 0.0, 0.0, 0.0, 29290.0, 0.0},
    };
    for (int i = 0; i < 365; i++) {
        update_positions(planets);
        update_velocities(planets);
        printf("Day %d - Earth (%f, %f, %f), Moon (%f, %f, %f), Jupiter (%f, %f, %f)\n", i, planets[0].x, planets[0].y, planets[0].z, planets[1].x, planets[1].y, planets[1].z, planets[2].x, planets[2].y, planets[2].z);
    }
    return 0;
}