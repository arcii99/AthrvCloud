//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: irregular
#include <stdio.h>

// Define Constants
#define G 6.6743e-11 // Gravitational Constant
#define DAY 86400    // Number of seconds in a day
#define YEAR 365     // Number of days in a year

// Define Structs
struct Vector {
    double x;
    double y;
    double z;
};

struct Body {
    struct Vector position;
    struct Vector velocity;
    double mass;
};

// Define Functions
struct Vector compute_gravitational_force(struct Body body1, struct Body body2) {
    struct Vector force;
    double distance_sqrd = pow(body2.position.x - body1.position.x, 2) + pow(body2.position.y - body1.position.y, 2) + pow(body2.position.z - body1.position.z, 2);
    double force_mag = (G * body1.mass * body2.mass) / distance_sqrd;
    double force_dir_x = (body2.position.x - body1.position.x) / sqrt(distance_sqrd);
    double force_dir_y = (body2.position.y - body1.position.y) / sqrt(distance_sqrd);
    double force_dir_z = (body2.position.z - body1.position.z) / sqrt(distance_sqrd);
    force.x = force_mag * force_dir_x;
    force.y = force_mag * force_dir_y;
    force.z = force_mag * force_dir_z;
    return force;
}

void update_velocity(struct Body *body, struct Vector acceleration, double time_step) {
    body->velocity.x += acceleration.x * time_step;
    body->velocity.y += acceleration.y * time_step;
    body->velocity.z += acceleration.z * time_step;
}

void update_position(struct Body *body, double time_step) {
    body->position.x += body->velocity.x * time_step;
    body->position.y += body->velocity.y * time_step;
    body->position.z += body->velocity.z * time_step;
}

void run_simulation(struct Body *bodies, int num_bodies, double time_step, int num_years) {
    int num_steps = num_years * YEAR * DAY / time_step;
    for (int i = 0; i < num_steps; i++) {
        for (int j = 0; j < num_bodies; j++) {
            struct Vector acceleration = {0, 0, 0};
            for (int k = 0; k < num_bodies; k++) {
                if (j == k)
                    continue;
                struct Vector force = compute_gravitational_force(bodies[j], bodies[k]);
                acceleration.x += force.x / bodies[j].mass;
                acceleration.y += force.y / bodies[j].mass;
                acceleration.z += force.z / bodies[j].mass;
            }
            update_velocity(&bodies[j], acceleration, time_step);
        }
        for (int j = 0; j < num_bodies; j++) {
            update_position(&bodies[j], time_step);
        }
    }
}

int main() {
    // Define Bodies
    struct Body sun = {{0, 0, 0}, {0, 0, 0}, 1.989e30};   // Mass of Sun = 1.989 × 10^30 kg
    struct Body earth = {{1.495e11, 0, 0}, {0, 29783, 0}, 5.972e24};   // Mass of Earth = 5.972 × 10^24 kg
    struct Body moon = {{1.495e11 + 384400000, 0, 0}, {0, 3070, 0}, 7.342e22};   // Mass of Moon = 7.342 × 10^22 kg

    // Run Simulation
    struct Body bodies[] = {sun, earth, moon};
    int num_bodies = sizeof(bodies) / sizeof(struct Body);
    double time_step = 1000;  // Seconds
    int num_years = 1;
    run_simulation(bodies, num_bodies, time_step, num_years);

    // Print Final Details about the Bodies
    printf("Body Positions after %d year(s):\n", num_years);
    for (int i = 0; i < num_bodies; i++) {
        printf("Body %d Position (m): (%.2f, %.2f, %.2f)\n", i, bodies[i].position.x, bodies[i].position.y, bodies[i].position.z);
    }
    printf("\n");

    return 0;
}