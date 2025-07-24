//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: scientific
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67e-11 // Universal Gravitational Constant

struct vector {
    double x;
    double y;
    double z;
};

struct body {
    char name;
    double mass;
    struct vector position;
    struct vector velocity;
    struct vector acceleration;
};

void initialize(struct body *bodies, int num_bodies) {
    // Initialize positions randomly within a sphere with radius 1
    srand(time(0));
    for (int i = 0; i < num_bodies; i++) {
        double x, y, z;
        do {
            x = 2 * ((double) rand() / RAND_MAX) - 1;
            y = 2 * ((double) rand() / RAND_MAX) - 1;
            z = 2 * ((double) rand() / RAND_MAX) - 1;
        } while (x*x + y*y + z*z > 1);
        bodies[i].position.x = x * 1e11;
        bodies[i].position.y = y * 1e11;
        bodies[i].position.z = z * 1e11;

        // Initialize velocities based on the inverse square law
        double r = sqrt(bodies[i].position.x*bodies[i].position.x
                      + bodies[i].position.y*bodies[i].position.y
                      + bodies[i].position.z*bodies[i].position.z);
        double v = sqrt(G * 2e30 / r);
        bodies[i].velocity.x = -bodies[i].position.y / r * v;
        bodies[i].velocity.y = bodies[i].position.x / r * v;
        bodies[i].velocity.z = 0;

        // Assign masses randomly
        bodies[i].mass = ((double) rand() / RAND_MAX) * 1e30;
    }
}

void update_accelerations(struct body *bodies, int num_bodies) {
    // Calculate new accelerations for each body based on the gravitational force
    for (int i = 0; i < num_bodies; i++) {
        struct vector acceleration = {0, 0, 0};
        for (int j = 0; j < num_bodies; j++) {
            if (i == j) continue;
            double dx = bodies[j].position.x - bodies[i].position.x;
            double dy = bodies[j].position.y - bodies[i].position.y;
            double dz = bodies[j].position.z - bodies[i].position.z;
            double distance_cubed = pow(sqrt(dx*dx + dy*dy + dz*dz), 3);
            double force = G * bodies[i].mass * bodies[j].mass / distance_cubed;
            acceleration.x += dx * force / bodies[i].mass;
            acceleration.y += dy * force / bodies[i].mass;
            acceleration.z += dz * force / bodies[i].mass;
        }
        bodies[i].acceleration = acceleration;
    }
}

void update_positions(struct body *bodies, int num_bodies, double dt) {
    // Update positions based on velocities and previous positions
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * dt;
        bodies[i].position.y += bodies[i].velocity.y * dt;
        bodies[i].position.z += bodies[i].velocity.z * dt;
    }
}

void update_velocities(struct body *bodies, int num_bodies, double dt) {
    // Update velocities based on accelerations and previous velocities
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].velocity.x += bodies[i].acceleration.x * dt;
        bodies[i].velocity.y += bodies[i].acceleration.y * dt;
        bodies[i].velocity.z += bodies[i].acceleration.z * dt;
    }
}

void print_body(struct body b) {
    printf("%c (%.2e kg): (%.2e, %.2e, %.2e) (%.2e, %.2e, %.2e)\n",
           b.name, b.mass,
           b.position.x, b.position.y, b.position.z,
           b.velocity.x, b.velocity.y, b.velocity.z);
}

void print_system(struct body *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        print_body(bodies[i]);
    }
    printf("\n");
}

int main() {
    int num_bodies = 4;
    struct body bodies[num_bodies];
    bodies[0].name = 'S'; // Sun
    bodies[1].name = 'E'; // Earth
    bodies[2].name = 'M'; // Mars
    bodies[3].name = 'J'; // Jupiter

    initialize(bodies, num_bodies);

    double t = 0;
    double dt = 60 * 60 * 24; // 1 day in seconds
    int num_steps = 365 * 10; // 10 years of simulation
    for (int i = 0; i < num_steps; i++) {
        printf("Time: %.2e s\n", t);
        print_system(bodies, num_bodies);

        update_accelerations(bodies, num_bodies);
        update_positions(bodies, num_bodies, dt);
        update_velocities(bodies, num_bodies, dt);

        t += dt;
    }
    return 0;
}