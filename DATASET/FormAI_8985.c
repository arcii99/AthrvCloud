//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67408e-11  // gravitational constant
#define SUN_MASS 1.9885e30  // mass of sun
#define EARTH_MASS 5.97e24  // mass of earth
#define EARTH_SPEED 29800  // earth's speed in m/s
#define AU 1.495978707e11  // astronomical unit in meters
#define SCALE_FACTOR 1e-10  // scaling factor for visualization

typedef struct {
    double x, y;
} Vector2D;

typedef struct {
    Vector2D position, velocity, acceleration;
    double mass, radius;
} CelestialBody;

CelestialBody sun = {
    .position = {0, 0},
    .velocity = {0, 0},
    .acceleration = {0, 0},
    .mass = SUN_MASS,
    .radius = 695500 * SCALE_FACTOR
};

CelestialBody earth = {
    .position = {AU, 0},
    .velocity = {0, EARTH_SPEED},
    .acceleration = {0, 0},
    .mass = EARTH_MASS,
    .radius = 6378 * SCALE_FACTOR
};

void update_acceleration(CelestialBody *body, double dt, CelestialBody *bodies, int n) {
    body->acceleration.x = 0;
    body->acceleration.y = 0;

    for (int i = 0; i < n; i++) {
        if (&bodies[i] == body) {
            continue;
        }

        double dx = bodies[i].position.x - body->position.x;
        double dy = bodies[i].position.y - body->position.y;
        double distance_squared = dx * dx + dy * dy;
        double force_magnitude = G * body->mass * bodies[i].mass / distance_squared;
        double force_direction_x = dx / sqrt(distance_squared);
        double force_direction_y = dy / sqrt(distance_squared);
        double force_x = force_magnitude * force_direction_x;
        double force_y = force_magnitude * force_direction_y;

        body->acceleration.x += force_x / body->mass;
        body->acceleration.y += force_y / body->mass;
    }
}

void update_velocity(CelestialBody *body, double dt) {
    body->velocity.x += dt * body->acceleration.x;
    body->velocity.y += dt * body->acceleration.y;
}

void update_position(CelestialBody *body, double dt) {
    body->position.x += dt * body->velocity.x;
    body->position.y += dt * body->velocity.y;
}

int main() {
    CelestialBody bodies[] = {sun, earth};
    int num_bodies = sizeof(bodies) / sizeof(CelestialBody);

    const double t_min = 0;
    const double t_max = 365.25 * 24 * 3600;
    const double dt = 3600;
    double t = t_min;

    while (t <= t_max) {
        for (int i = 0; i < num_bodies; i++) {
            update_acceleration(&bodies[i], dt, bodies, num_bodies);
        }
        for (int i = 0; i < num_bodies; i++) {
            update_velocity(&bodies[i], dt);
            update_position(&bodies[i], dt);
        }

        // visualization code here

        t += dt;
    }

    return 0;
}