//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: careful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.674E-11 // gravitational constant
#define AU 1.496E+11 // astronomical unit - distance from Earth to Sun

// 3D vector struct to store positions and velocities
typedef struct {
    double x;
    double y;
    double z;
} vector3D;

// celestial body struct
typedef struct {
    char name[50];
    double mass;
    double radius;
    vector3D position;
    vector3D velocity;
} celestial_body;

// function to calculate gravitational force between two bodies
vector3D gravity_force(celestial_body body1, celestial_body body2) {
    double distance = sqrt(pow((body2.position.x - body1.position.x), 2) + pow((body2.position.y - body1.position.y), 2) + pow((body2.position.z - body1.position.z), 2));
    double force_magnitude = (G * body1.mass * body2.mass) / pow(distance, 2);
    vector3D force;
    force.x = force_magnitude * (body2.position.x - body1.position.x) / distance;
    force.y = force_magnitude * (body2.position.y - body1.position.y) / distance;
    force.z = force_magnitude * (body2.position.z - body1.position.z) / distance;
    return force;
}

// function to update acceleration, velocity, and position of a body over a given time step
void update_body(celestial_body *body, celestial_body *bodies, int num_bodies, double delta_t) {
    vector3D acceleration = {0.0, 0.0, 0.0};
    for (int i = 0; i < num_bodies; i++) {
        if (i != body - bodies) { // ignore force from self
            vector3D force = gravity_force(*body, bodies[i]);
            acceleration.x += force.x / body->mass;
            acceleration.y += force.y / body->mass;
            acceleration.z += force.z / body->mass;
        }
    }
    body->velocity.x += acceleration.x * delta_t;
    body->velocity.y += acceleration.y * delta_t;
    body->velocity.z += acceleration.z * delta_t;
    body->position.x += body->velocity.x * delta_t;
    body->position.y += body->velocity.y * delta_t;
    body->position.z += body->velocity.z * delta_t;
}

int main() {
    // initialize solar system
    srand(time(NULL));
    celestial_body sun = {"Sun", 1.989E+30, 696340000, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
    celestial_body earth = {"Earth", 5.972E+24, 6371000, {AU, 0.0, 0.0}, {0.0, sqrt(G * sun.mass / AU), 0.0}};
    celestial_body moon = {"Moon", 7.342E+22, 1737100, {AU + 384400000, 0.0, 0.0}, {0.0, sqrt(G * (earth.mass + moon.mass) / 384400000), 0.0}};
    celestial_body mars = {"Mars", 6.39E+23, 3396200, {0.0, 1.524 * AU, 0.0}, {-24016, 0.0, 0.0}};
    celestial_body jupiter = {"Jupiter", 1.898E+27, 69911000, {0.0, 0.0, 5.203 * AU}, {0.0, 13070, 0.0}};
    celestial_body saturn = {"Saturn", 5.683E+26, 58232000, {0.0, 0.0, 9.537 * AU}, {0.0, 9690, 0.0}};
    celestial_body uranus = {"Uranus", 8.681E+25, 25362000, {0.0, 0.0, 19.191 * AU}, {0.0, 6810, 0.0}};
    celestial_body neptune = {"Neptune", 1.024E+26, 24622000, {0.0, 0.0, 30.069 * AU}, {0.0, 5430, 0.0}};
    celestial_body pluto = {"Pluto", 1.309E+22, 1186000, {0.0, 0.0, 39.482 * AU}, {0.0, 4660, 0.0}};
    celestial_body bodies[] = {sun, earth, moon, mars, jupiter, saturn, uranus, neptune, pluto};
    int num_bodies = sizeof(bodies) / sizeof(bodies[0]);

    // simulation parameters
    double total_time = 365.25 * 86400 * 5; // 5 years in seconds
    double delta_t = 86400; // 1 day in seconds
    int num_steps = total_time / delta_t;

    // simulation loop
    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_bodies; i++) {
            update_body(&bodies[i], bodies, num_bodies, delta_t);
        }
    }

    // print final positions and velocities of all bodies
    for (int i = 0; i < num_bodies; i++) {
        printf("%s: x=%e m, y=%e m, z=%e m, vx=%e m/s, vy=%e m/s, vz=%e m/s\n", bodies[i].name, bodies[i].position.x, bodies[i].position.y, bodies[i].position.z, bodies[i].velocity.x, bodies[i].velocity.y, bodies[i].velocity.z);
    }

    return 0;
}