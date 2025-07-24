//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: medieval
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11

struct Planet {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
};

void update_position(struct Planet *planet, double dt) {
    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
}

void update_velocity(struct Planet *planet, double fx, double fy, double dt) {
    double ax = fx / planet->mass;
    double ay = fy / planet->mass;
    planet->vx += ax * dt;
    planet->vy += ay * dt;
}

double force(double mass1, double mass2, double distance) {
    return G * mass1 * mass2 / pow(distance, 2);
}

double distance(struct Planet *planet1, struct Planet *planet2) {
    double dx = planet1->x - planet2->x;
    double dy = planet1->y - planet2->y;
    return sqrt(dx * dx + dy * dy);
}

void update_gravity(struct Planet *planet1, struct Planet *planet2, double dt) {
    double dist = distance(planet1, planet2);
    double f = force(planet1->mass, planet2->mass, dist);
    double fx = f * (planet2->x - planet1->x) / dist;
    double fy = f * (planet2->y - planet1->y) / dist;
    update_velocity(planet1, fx, fy, dt);
}

int main() {
    struct Planet earth = {5.975e24, 0, 0, 0, 0};
    struct Planet moon = {7.349e22, 3.84e8, 0, 0, 1022};
    double dt = 1.0;

    for (int i = 0; i < 100; i++) {
        update_gravity(&earth, &moon, dt);
        update_gravity(&moon, &earth, dt);
        update_position(&earth, dt);
        update_position(&moon, dt);
        printf("%f, %f, %f, %f\n", earth.x, earth.y, moon.x, moon.y);
    }

    return 0;
}