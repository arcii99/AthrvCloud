//FormAI DATASET v1.0 Category: Physics simulation ; Style: rigorous
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant

struct Planet {
    char name[20];
    double mass;
    double radius;
    double x, y; // Current position
    double vx, vy; // Current velocity
    double ax, ay; // Current acceleration
};

void update_acceleration(struct Planet *planet, struct Planet planets[], int num_planets) {
    double fx = 0, fy = 0, distance_sq, force;
    for (int i = 0; i < num_planets; i++) {
        if (planet == &planets[i]) continue; // Skip self
        distance_sq = (planet->x - planets[i].x) * (planet->x - planets[i].x) + (planet->y - planets[i].y) * (planet->y - planets[i].y);
        force = G * planet->mass * planets[i].mass / distance_sq;
        fx += force * (planets[i].x - planet->x) / sqrt(distance_sq);
        fy += force * (planets[i].y - planet->y) / sqrt(distance_sq);
    }
    planet->ax = fx / planet->mass;
    planet->ay = fy / planet->mass;
}

void update_velocity(struct Planet *planet, double dt) {
    planet->vx += planet->ax * dt;
    planet->vy += planet->ay * dt;
}

void update_position(struct Planet *planet, double dt) {
    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
}

int main() {
    struct Planet planets[3] = {
        {"Earth", 5.972e24, 6.371e6, 0, 0, 0, 0, 0, 0},
        {"Moon", 7.342e22, 1.736e6, 3.84e8, 0, 0, 1022, 0, 0},
        {"Mars", 6.39e23, 3.3895e6, 0, 1.524e11, -24130, 0, 0, 0}
    };
    int num_planets = 3;
    double dt = 60, total_time = 86400 * 365, current_time = 0;
    while (current_time < total_time) {
        for (int i = 0; i < num_planets; i++) {
            update_acceleration(&planets[i], planets, num_planets);
        }
        for (int i = 0; i < num_planets; i++) {
            update_velocity(&planets[i], dt);
        }
        for (int i = 0; i < num_planets; i++) {
            update_position(&planets[i], dt);
        }
        current_time += dt;
    }
    for (int i = 0; i < num_planets; i++) {
        printf("%s: (%e, %e)", planets[i].name, planets[i].x, planets[i].y);
    }
    return 0;
}