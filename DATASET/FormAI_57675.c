//FormAI DATASET v1.0 Category: Physics simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define G 6.674e-11 // Gravitational constant in m^3/(kg*s^2)
#define TIMESTEP 1 // Time step in seconds

// Structure for a 2D vector
typedef struct vector2d {
    double x;
    double y;
} Vector2D;

// Structure for a particle
typedef struct particle {
    double mass;
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
} Particle;

// Function to calculate the distance between two particles
double distance(Particle *p1, Particle *p2) {
    double dx = p2->position.x - p1->position.x;
    double dy = p2->position.y - p1->position.y;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

// Function to calculate the gravitational force between two particles
Vector2D gravitationalForce(Particle *p1, Particle *p2) {
    double r = distance(p1, p2);
    double f = (G * p1->mass * p2->mass) / pow(r, 2);
    Vector2D direction = {
        .x = (p2->position.x - p1->position.x) / r,
        .y = (p2->position.y - p1->position.y) / r
    };
    Vector2D force = {
        .x = f * direction.x,
        .y = f * direction.y
    };
    return force;
}

int main() {
    // Define particles
    Particle p1 = {
        .mass = 100,
        .position = {
            .x = 0,
            .y = 0
        },
        .velocity = {
            .x = 0,
            .y = 0
        },
        .acceleration = {
            .x = 0,
            .y = 0
        }
    };
    Particle p2 = {
        .mass = 1000,
        .position = {
            .x = 100,
            .y = 0
        },
        .velocity = {
            .x = 0,
            .y = 10
        },
        .acceleration = {
            .x = 0,
            .y = 0
        }
    };

    // Simulation loop
    for (int i = 0; i < 1000; i++) {
        // Calculate forces
        Vector2D force12 = gravitationalForce(&p1, &p2);
        Vector2D force21 = gravitationalForce(&p2, &p1);

        // Update acceleration
        p1.acceleration.x = force21.x / p1.mass;
        p1.acceleration.y = force21.y / p1.mass;
        p2.acceleration.x = force12.x / p2.mass;
        p2.acceleration.y = force12.y / p2.mass;

        // Update velocity
        p1.velocity.x += p1.acceleration.x * TIMESTEP;
        p1.velocity.y += p1.acceleration.y * TIMESTEP;
        p2.velocity.x += p2.acceleration.x * TIMESTEP;
        p2.velocity.y += p2.acceleration.y * TIMESTEP;

        // Update position
        p1.position.x += p1.velocity.x * TIMESTEP;
        p1.position.y += p1.velocity.y * TIMESTEP;
        p2.position.x += p2.velocity.x * TIMESTEP;
        p2.position.y += p2.velocity.y * TIMESTEP;

        // Print output
        printf("Time: %d s\n", i);
        printf("Particle 1 position: (%.2f, %.2f)\n", p1.position.x, p1.position.y);
        printf("Particle 2 position: (%.2f, %.2f)\n", p2.position.x, p2.position.y);
        printf("\n");
    }

    return 0;
}