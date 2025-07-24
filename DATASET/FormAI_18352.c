//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 0.0000000000674

typedef struct {
    double x, y;
} Vector2D;

typedef struct {
    Vector2D position, velocity, acceleration;
    double mass, radius;
    char* name;
} CelestialBody;

CelestialBody sun = {
    .position = { .x = 0.0, .y = 0.0 },
    .velocity = { .x = 0.0, .y = 0.0 },
    .acceleration = { .x = 0.0, .y = 0.0 },
    .mass = 1.989e30,
    .radius = 696340.0,
    .name = "Sun"
};

CelestialBody earth = {
    .position = { .x = 147e9, .y = 0.0 },
    .velocity = { .x = 0.0, .y = 30.29e3 },
    .acceleration = { .x = 0.0, .y = 0.0 },
    .mass = 5.972e24,
    .radius = 6371.0,
    .name = "Earth"
};

CelestialBody moon = {
    .position = { .x = 147e9 + 384400.0, .y = 0.0 },
    .velocity = { .x = 0.0, .y = 1022.0 },
    .acceleration = { .x = 0.0, .y = 0.0 },
    .mass = 7.342e22,
    .radius = 1737.0,
    .name = "Moon"
};

double distance(Vector2D a, Vector2D b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double magnitude(Vector2D vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

Vector2D normalize(Vector2D vec) {
    double mag = magnitude(vec);
    return (Vector2D) { .x = vec.x / mag, .y = vec.y / mag };
}

Vector2D subtract(Vector2D a, Vector2D b) {
    return (Vector2D) { .x = a.x - b.x, .y = a.y - b.y };
}

Vector2D multiply(Vector2D vec, double scalar) {
    return (Vector2D) { .x = vec.x * scalar, .y = vec.y * scalar };
}

Vector2D add(Vector2D a, Vector2D b) {
    return (Vector2D) { .x = a.x + b.x, .y = a.y + b.y };
}

Vector2D compute_gravity(CelestialBody a, CelestialBody b) {
    double dist = distance(a.position, b.position);
    double force = GRAV_CONST * a.mass * b.mass / (dist * dist);
    Vector2D direction = normalize(subtract(b.position, a.position));
    return multiply(direction, force / a.mass);
}

void update(CelestialBody* body, double dt) {
    add(body->velocity, multiply(body->acceleration, dt));
    add(body->position, multiply(body->velocity, dt));
}

void run_simulation(double time_step, double end_time) {
    int num_steps = end_time / time_step;
    printf("Starting Solar System simulation...\n");
    printf("Initial positions: Sun (%lf,%lf), Earth (%lf,%lf), Moon (%lf,%lf)\n", 
           sun.position.x, sun.position.y, 
           earth.position.x, earth.position.y, 
           moon.position.x, moon.position.y);
           
    for (int i = 0; i <= num_steps; i++) {
        Vector2D sun_gravity = compute_gravity(sun, earth);
        add(earth.acceleration, sun_gravity);
        update(&earth, time_step);
        
        Vector2D earth_gravity1 = compute_gravity(earth, sun);
        Vector2D earth_gravity2 = compute_gravity(earth, moon);
        add(earth_gravity1, earth_gravity2);
        add(earth.acceleration, earth_gravity1);
        update(&earth, time_step);
        
        Vector2D moon_gravity1 = compute_gravity(moon, earth);
        Vector2D moon_gravity2 = compute_gravity(moon, sun);
        add(moon_gravity1, moon_gravity2);
        add(moon.acceleration, moon_gravity1);
        update(&moon, time_step);
    }
    
    printf("Final positions: Sun (%lf,%lf), Earth (%lf,%lf), Moon (%lf,%lf)\n", 
           sun.position.x, sun.position.y, 
           earth.position.x, earth.position.y, 
           moon.position.x, moon.position.y);
}

int main() {
    run_simulation(86400.0, 365.0);
    return 0;
}