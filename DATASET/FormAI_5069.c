//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Vector {
    double x;
    double y;
};

struct Planet {
    struct Vector position;
    struct Vector velocity;
    double mass;
};

const double G = 6.6743e-11;

void calculate_forces(struct Planet planets[], int num_planets, struct Vector forces[]) {
    for (int i = 0; i < num_planets; i++) {
        forces[i].x = forces[i].y = 0.0;
        for (int j = 0; j < num_planets; j++) {
            if (i == j) continue;
            struct Vector delta;
            delta.x = planets[j].position.x - planets[i].position.x;
            delta.y = planets[j].position.y - planets[i].position.y;
            double distance_squared = delta.x * delta.x + delta.y * delta.y;
            double force_magnitude = G * planets[i].mass * planets[j].mass / distance_squared;
            double force_x = force_magnitude * delta.x / sqrt(distance_squared);
            double force_y = force_magnitude * delta.y / sqrt(distance_squared);
            forces[i].x += force_x;
            forces[i].y += force_y;
        }
    }
}

void update_planets(struct Planet planets[], int num_planets, struct Vector forces[], double delta_t) {
    for (int i = 0; i < num_planets; i++) {
        double accel_x = forces[i].x / planets[i].mass;
        double accel_y = forces[i].y / planets[i].mass;
        planets[i].velocity.x += accel_x * delta_t;
        planets[i].velocity.y += accel_y * delta_t;
        planets[i].position.x += planets[i].velocity.x * delta_t;
        planets[i].position.y += planets[i].velocity.y * delta_t;
    }
}

int main() {
    int num_planets = 3;
    struct Planet planets[] = {
        {{0.0, 0.0}, {0.0, 0.0}, 5.97e24},
        {{384400000.0, 0.0}, {0.0, 1022.0}, 7.3477e22},
        {{0.0, 6371000.0}, {-7900.0, 0.0}, 1000.0}
    };
    struct Vector forces[num_planets];
    double delta_t = 10.0;
    for (int i = 0; i < 10000; i++) {
        calculate_forces(planets, num_planets, forces);
        update_planets(planets, num_planets, forces, delta_t);
        printf("Iteration %d\n", i);
        for (int j = 0; j < num_planets; j++) {
            printf("Planet %d: (%f, %f)\n", j, planets[j].position.x, planets[j].position.y);
        }
    }
    return 0;
}