//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: detailed
#include <stdio.h>

#define G 6.67 // gravitational constant

struct Vector {
    double x, y, z;
};

struct Body {
    struct Vector position;
    struct Vector velocity;
    double mass;
};

void print_vector(struct Vector v) {
    printf("(%.2f, %.2f, %.2f)", v.x, v.y, v.z);
}

void print_body(struct Body b) {
    printf("Position: ");
    print_vector(b.position);
    printf("\nVelocity: ");
    print_vector(b.velocity);
    printf("\nMass: %.2f\n", b.mass);
}

struct Vector calculate_gravity(struct Body b1, struct Body b2) {
    struct Vector direction;
    direction.x = b2.position.x - b1.position.x;
    direction.y = b2.position.y - b1.position.y;
    direction.z = b2.position.z - b1.position.z;
    double distance_squared = direction.x * direction.x + direction.y * direction.y + direction.z * direction.z;
    double force = G * b1.mass * b2.mass / distance_squared;
    double magnitude = sqrt(distance_squared);
    direction.x /= magnitude;
    direction.y /= magnitude;
    direction.z /= magnitude;
    direction.x *= force;
    direction.y *= force;
    direction.z *= force;
    return direction;
}

void update_body(struct Body *b, struct Vector force, double time_step) {
    struct Vector acceleration;
    acceleration.x = force.x / b->mass;
    acceleration.y = force.y / b->mass;
    acceleration.z = force.z / b->mass;
    b->velocity.x += acceleration.x * time_step;
    b->velocity.y += acceleration.y * time_step;
    b->velocity.z += acceleration.z * time_step;
    b->position.x += b->velocity.x * time_step;
    b->position.y += b->velocity.y * time_step;
    b->position.z += b->velocity.z * time_step;
}

int main() {
    struct Body sun = {
        {0, 0, 0},
        {0, 0, 0},
        1.989e30 // mass of the sun in kg
    };
    struct Body earth = {
        {149.6e9, 0, 0},
        {0, 29.78e3, 0},
        5.97e24 // mass of the earth in kg
    };
    double time_step = 24 * 3600; // one day
    double total_time = 365 * time_step; // one year
    for (double t = 0; t < total_time; t += time_step) {
        struct Vector gravity = calculate_gravity(sun, earth);
        update_body(&earth, gravity, time_step);
        printf("Earth at t=%.2f:\n", t / (24 * 3600));
        print_body(earth);
    }
    return 0;
}