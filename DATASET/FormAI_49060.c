//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Donald Knuth
// A Simulation of the Solar System 
// Written in a Donald Knuth style

#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant
#define STEPS 10000 // number of time steps
#define DT 1e5 // time step size
#define MASS_SUN 1.98e30 // mass of the sun
#define RADIUS_SUN 6.96e8 // radius of the sun

struct Vector3 {
    double x, y, z;
};

struct Body {
    char name[10];
    double mass;
    double radius;
    struct Vector3 position;
    struct Vector3 velocity;
    struct Vector3 acceleration;
};

void calculate_acceleration(struct Body* b1, struct Body* b2) {
    double distance = sqrt(pow(b1->position.x - b2->position.x, 2) + pow(b1->position.y - b2->position.y, 2) + pow(b1->position.z - b2->position.z, 2));
    double force = G * b1->mass * b2->mass / pow(distance, 2);
    double acceleration = force / b1->mass;
    b1->acceleration.x += acceleration * (b2->position.x - b1->position.x) / distance;
    b1->acceleration.y += acceleration * (b2->position.y - b1->position.y) / distance;
    b1->acceleration.z += acceleration * (b2->position.z - b1->position.z) / distance;
}

void update_body(struct Body* body) {
    body->position.x += body->velocity.x * DT + 0.5 * body->acceleration.x * pow(DT, 2);
    body->position.y += body->velocity.y * DT + 0.5 * body->acceleration.y * pow(DT, 2);
    body->position.z += body->velocity.z * DT + 0.5 * body->acceleration.z * pow(DT, 2);
    body->velocity.x += body->acceleration.x * DT;
    body->velocity.y += body->acceleration.y * DT;
    body->velocity.z += body->acceleration.z * DT;
    body->acceleration.x = 0;
    body->acceleration.y = 0;
    body->acceleration.z = 0;
}

int main() {
    struct Body sun = {"Sun", MASS_SUN, RADIUS_SUN, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    struct Body earth = {"Earth", 5.97e24, 6.37e6, {1.5e11, 0, 0}, {0, 3e4, 0}, {0, 0, 0}};
    struct Body moon = {"Moon", 7.34e22, 1.74e6, {1.5e11 + 3.84e8, 0, 0}, {0, 3e4 + 1.022e3, 0}, {0, 0, 0}};

    printf("%-10s%10s%10s%10s\n", "Time", "Earth.x", "Earth.y", "Earth.z");
    for (int i = 0; i < STEPS; i++) {
        calculate_acceleration(&earth, &sun);
        calculate_acceleration(&moon, &sun);
        calculate_acceleration(&moon, &earth);
        update_body(&earth);
        update_body(&moon);
        printf("%-10.2f%10.2f%10.2f%10.2f\n", i * DT, earth.position.x, earth.position.y, earth.position.z);
    }

    return 0;
}