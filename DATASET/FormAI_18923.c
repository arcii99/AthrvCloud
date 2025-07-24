//FormAI DATASET v1.0 Category: Physics simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOX_SIZE 10
#define GRAVITY -9.8

// Structs
typedef struct {
    double x;
    double y;
    double z;
} Vector3;

typedef struct {
    Vector3 position;
    Vector3 velocity;
    double mass;
} Particle;

typedef struct {
    Vector3 position;
    double length;
} Box;

// Functions
double random_double(double min, double max) {
    return ((double)rand() / (double)RAND_MAX) * (max - min) + min;
}

void print_vector3(Vector3 v) {
    printf("[%f, %f, %f]", v.x, v.y, v.z);
}

void print_particle(Particle p) {
    printf("Position: ");
    print_vector3(p.position);
    printf("\nVelocity: ");
    print_vector3(p.velocity);
    printf("\nMass: %f", p.mass);
    printf("\n");
}

void update_particle_position(Particle *p, double t) {
    p->position.x += p->velocity.x * t;
    p->position.y += p->velocity.y * t;
    p->position.z += p->velocity.z * t;
}

void update_particle_velocity(Particle *p, double t) {
    p->velocity.y += GRAVITY * t;
}

int particle_in_box(Particle p, Box b) {
    if (p.position.x >= b.position.x && p.position.x <= b.position.x + b.length &&
        p.position.y >= b.position.y && p.position.y <= b.position.y + b.length &&
        p.position.z >= b.position.z && p.position.z <= b.position.z + b.length) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    // Initialize box and particles
    Box b;
    b.position = (Vector3) { 0, 0, 0 };
    b.length = BOX_SIZE;

    Particle particles[10];
    for (int i = 0; i < 10; i++) {
        particles[i].position = (Vector3) { random_double(0, BOX_SIZE), random_double(0, BOX_SIZE), random_double(0, BOX_SIZE) };
        particles[i].velocity = (Vector3) { random_double(-5, 5), random_double(-5, 5), random_double(-5, 5) };
        particles[i].mass = random_double(1, 10);
    }

    // Simulate particle in box
    double t = 0.01; // Time step
    double simulation_time = 10; // seconds
    int num_steps = simulation_time / t;

    for (int i = 0; i < num_steps; i++) {
        for (int j = 0; j < 10; j++) {
            // Update position
            update_particle_position(&particles[j], t);

            // Check if particle is in box
            if (particle_in_box(particles[j], b)) {
                // Update velocity (collision with box)
                particles[j].velocity.y *= -1;
            } else {
                // Update velocity (gravity)
                update_particle_velocity(&particles[j], t);
            }
        }
    }

    // Print final positions
    for (int i = 0; i < 10; i++) {
        printf("Particle %d\n", i + 1);
        print_particle(particles[i]);
        printf("\n");
    }

    return 0;
}