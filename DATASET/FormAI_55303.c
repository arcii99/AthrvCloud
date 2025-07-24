//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: realistic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

#define SUN_MASS 1.989E30
#define EARTH_ORBIT_RADIUS 1.496E11
#define EARTH_ORBIT_VELOCITY 2.9783E4
#define MOON_ORBIT_RADIUS 3.84E8
#define MOON_ORBIT_VELOCITY 1.022E3
#define GRAVITATIONAL_CONSTANT 6.6743E-11

typedef struct {
    double x, y, z;
} Vector3;

typedef struct {
    Vector3 position, velocity;
    double mass;
} CelestialBody;

// Updates the velocity and position of the body due to gravitational forces from other bodies
void update_body(CelestialBody* body, CelestialBody* other_bodies, int num_bodies, double dt) {
    Vector3 acceleration = {0, 0, 0};

    for (int i = 0; i < num_bodies; i++) {
        if (other_bodies[i].mass == body->mass) {
            continue;
        }

        Vector3 diff = {
            other_bodies[i].position.x - body->position.x,
            other_bodies[i].position.y - body->position.y,
            other_bodies[i].position.z - body->position.z
        };

        double distance_squared = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
        double distance = sqrt(distance_squared);

        double force_magnitude = GRAVITATIONAL_CONSTANT * body->mass * other_bodies[i].mass / distance_squared;

        Vector3 force_direction = {diff.x / distance, diff.y / distance, diff.z / distance};
        Vector3 force = {force_direction.x * force_magnitude, force_direction.y * force_magnitude, force_direction.z * force_magnitude};

        acceleration.x += force.x / body->mass;
        acceleration.y += force.y / body->mass;
        acceleration.z += force.z / body->mass;
    }

    body->velocity.x += acceleration.x * dt;
    body->velocity.y += acceleration.y * dt;
    body->velocity.z += acceleration.z * dt;

    body->position.x += body->velocity.x * dt;
    body->position.y += body->velocity.y * dt;
    body->position.z += body->velocity.z * dt;
}

void simulate_solar_system(CelestialBody* bodies, int num_bodies, double duration, double time_step) {
    for (double t = 0; t < duration; t += time_step) {
        for (int i = 0; i < num_bodies; i++) {
            update_body(&bodies[i], bodies, num_bodies, time_step);
        }
    }
}

int main() {
    // Initialize the sun, earth, and moon
    CelestialBody sun = {
        .position = {0, 0, 0},
        .velocity = {0, 0, 0},
        .mass = SUN_MASS
    };

    CelestialBody earth = {
        .position = {EARTH_ORBIT_RADIUS, 0, 0},
        .velocity = {0, EARTH_ORBIT_VELOCITY, 0},
        .mass = 5.972E24
    };

    CelestialBody moon = {
        .position = {EARTH_ORBIT_RADIUS + MOON_ORBIT_RADIUS, 0, 0},
        .velocity = {0, EARTH_ORBIT_VELOCITY + MOON_ORBIT_VELOCITY, 0},
        .mass = 7.342E22
    };

    // Simulate the solar system
    CelestialBody bodies[] = {sun, earth, moon};
    int num_bodies = sizeof(bodies) / sizeof(*bodies);

    double duration = 31536000; // 1 year in seconds
    double time_step = 86400; // 1 day in seconds

    simulate_solar_system(bodies, num_bodies, duration, time_step);

    // Print the final positions of the bodies
    printf("Sun position: (%f, %f, %f)\n", sun.position.x, sun.position.y, sun.position.z);
    printf("Earth position: (%f, %f, %f)\n", earth.position.x, earth.position.y, earth.position.z);
    printf("Moon position: (%f, %f, %f)\n", moon.position.x, moon.position.y, moon.position.z);

    return 0;
}