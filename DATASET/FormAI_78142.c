//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define num_bodies 4    // Number of bodies in the simulation
#define G 6.67408E-11   // Gravitational constant

struct body {           // Struct representing a celestial body
    char name[20];
    double mass, radius;
    double position[3], velocity[3], acceleration[3];
};

void calculate_acceleration(struct body* bodies);
void update_positions(struct body* bodies, double dt);
void update_velocities(struct body* bodies, double dt);
void print_body_info(struct body* body);

int main() {
    struct body bodies[num_bodies] = {     // Initialize the celestrial bodies
        {"Sun", 1.989E30, 696340E3, {0,0,0}, {0,0,0}, {0,0,0}},
        {"Earth", 5.9742E24, 6371E3, {-147095000E3, 0, 0}, {0, 29600, 0}, {0,0,0}},
        {"Moon", 7.342E22, 1737.1E3, {-147095000E3 + 384400E3, 0, 0},
            {0, 29600 + 1023, 0}, {0,0,0}},
        {"Mars", 6.39E23, 3390E3, {0, 227939200E3, 0}, {-24007, 0, 0}, {0,0,0}}
    };

    double dt = 1;  // Time step
    int num_steps = 1000;   // Number of time steps to simulate

    for (int i = 0; i < num_steps; i++) {
        calculate_acceleration(bodies);
        update_positions(bodies, dt);
        calculate_acceleration(bodies);
        update_velocities(bodies, dt);

        printf("===== Step %d =====\n", i);
        for (int j = 0; j < num_bodies; j++) {
            print_body_info(&bodies[j]);
        }
        printf("\n");
    }

    return 0;
}

void calculate_acceleration(struct body* bodies) {
    for (int i = 0; i < num_bodies; i++) {
        for (int j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue;
            }

            double distance_vector[3];
            for (int k = 0; k < 3; k++) {
                distance_vector[k] = bodies[j].position[k] - bodies[i].position[k];
            }

            double distance = sqrt(pow(distance_vector[0], 2) + pow(distance_vector[1], 2) + pow(distance_vector[2], 2));
            double magnitude = G * bodies[j].mass / pow(distance, 3);

            for (int k = 0; k < 3; k++) {
                bodies[i].acceleration[k] += magnitude * distance_vector[k];
            }
        }
    }
}

void update_positions(struct body* bodies, double dt) {
    for (int i = 0; i < num_bodies; i++) {
        for (int k = 0; k < 3; k++) {
            bodies[i].position[k] += bodies[i].velocity[k] * dt;
        }
    }
}

void update_velocities(struct body* bodies, double dt) {
    for (int i = 0; i < num_bodies; i++) {
        for (int k = 0; k < 3; k++) {
            bodies[i].velocity[k] += bodies[i].acceleration[k] * dt;
            bodies[i].acceleration[k] = 0;
        }
    }
}

void print_body_info(struct body* body) {
    printf("%s:\n", body->name);
    printf("  Mass: %g kg\n", body->mass);
    printf("  Radius: %g km\n", body->radius / 1000);
    printf("  Position: (%g, %g, %g) km\n", body->position[0] / 1000, body->position[1] / 1000, body->position[2] / 1000);
    printf("  Velocity: (%g, %g, %g) m/s\n", body->velocity[0], body->velocity[1], body->velocity[2]);
    printf("  Acceleration: (%g, %g, %g) m/s^2\n", body->acceleration[0], body->acceleration[1], body->acceleration[2]);
}