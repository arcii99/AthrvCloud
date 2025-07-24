//FormAI DATASET v1.0 Category: Physics simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define G 6.67408e-11   // Gravitational constant
#define NUM_BODIES 3    // Number of bodies in the simulation
#define SIM_TIME  10    // Time duration of simulation (in seconds)
#define TIME_STEP 0.1   // Time step size (in seconds)

typedef struct {
    double mass;
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
} Body;

void update_positions(Body *bodies, int num_bodies, double time_step) {
    // Update positions of all bodies according to their velocities
    for (int i = 0; i < num_bodies; i++) {
        Body *b = &bodies[i];
        b->pos_x += b->vel_x * time_step;
        b->pos_y += b->vel_y * time_step;
    }
}

void update_velocities(Body *bodies, int num_bodies, double time_step) {
    // Update velocities of all bodies according to the gravitational force between them
    for (int i = 0; i < num_bodies; i++) {
        Body *b1 = &bodies[i];
        for (int j = i+1; j < num_bodies; j++) {
            Body *b2 = &bodies[j];
            double dx = b2->pos_x - b1->pos_x;
            double dy = b2->pos_y - b1->pos_y;
            double r_squared = dx*dx + dy*dy;
            double force_magnitude = G * b1->mass * b2->mass / r_squared;
            double force_x = force_magnitude * dx / sqrt(r_squared);
            double force_y = force_magnitude * dy / sqrt(r_squared);
            b1->vel_x += force_x / b1->mass * time_step;
            b1->vel_y += force_y / b1->mass * time_step;
            b2->vel_x -= force_x / b2->mass * time_step;
            b2->vel_y -= force_y / b2->mass * time_step;
        }
    }
}

void print_state(Body *bodies, int num_bodies) {
    // Print the current state of all bodies
    for (int i = 0; i < num_bodies; i++) {
        Body *b = &bodies[i];
        printf("Body %d - position (%.2f, %.2f), velocity (%.2f, %.2f)\n", i+1, b->pos_x, b->pos_y, b->vel_x, b->vel_y);
    }
}

int main() {
    // Initialize the simulation with three bodies
    Body bodies[NUM_BODIES] = {
        {1000.0, 0.0, 0.0, 0.0, 0.0},
        {500.0, 10.0, 0.0, 0.0, 50.0},
        {200.0, 0.0, 15.0, -40.0, 0.0}
    };

    int num_steps = SIM_TIME / TIME_STEP;
    for (int i = 0; i < num_steps; i++) {
        printf("Time step %d:\n", i+1);
        print_state(bodies, NUM_BODIES);
        update_velocities(bodies, NUM_BODIES, TIME_STEP);
        update_positions(bodies, NUM_BODIES, TIME_STEP);
    }

    return 0;
}