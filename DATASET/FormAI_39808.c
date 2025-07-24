//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67 * pow(10, -11) // Gravitational constant

typedef struct {
    double mass;
    double pos[3];
    double vel[3];
} body;

body* init_body(double mass, double x, double y, double z, double vx, double vy, double vz);
double distance(body* b1, body* b2);
void update_velocity(body* b1, body* b2, double dt);
void update_position(body* b, double dt);

int main() {
    double dt = 1;
    int num_bodies = 4;

    body* bodies[num_bodies];
    bodies[0] = init_body(1.989 * pow(10, 30), 0, 0, 0, 0, 0, 0);
    bodies[1] = init_body(5.97 * pow(10, 24), 1.5 * pow(10, 11), 0, 0, 0, 29.3 * pow(10, 3), 0);
    bodies[2] = init_body(3.302 * pow(10, 23), 0, 3.84 * pow(10, 8), 0, -1.02 * pow(10, 3), 0, 0);
    bodies[3] = init_body(4.869 * pow(10, 24), 0, 0, 5.79 * pow(10, 9), 47.9 * pow(10, 3), 0, 0);

    for (int i = 0; i < 1000000; i++) {
        for (int j = 0; j < num_bodies; j++) {
            for (int k = 0; k < num_bodies; k++) {
                if (j != k) {
                    update_velocity(bodies[j], bodies[k], dt);
                }
            }
        }
        for (int j = 0; j < num_bodies; j++) {
            update_position(bodies[j], dt);
        }

        printf("Step %d: Sun: (%lf, %lf, %lf) Earth: (%lf, %lf, %lf) Moon: (%lf, %lf, %lf) Mars: (%lf, %lf, %lf)\n", i, bodies[0]->pos[0], bodies[0]->pos[1], bodies[0]->pos[2], bodies[1]->pos[0], bodies[1]->pos[1], bodies[1]->pos[2], bodies[2]->pos[0], bodies[2]->pos[1], bodies[2]->pos[2], bodies[3]->pos[0], bodies[3]->pos[1], bodies[3]->pos[2]);
    }

    for (int i = 0; i < num_bodies; i++) {
        free(bodies[i]);
    }
    
    return 0;
}

// Initializes a body with the given mass, position, and velocity
body* init_body(double mass, double x, double y, double z, double vx, double vy, double vz) {
    body* b = (body*)malloc(sizeof(body));
    b->mass = mass;
    b->pos[0] = x;
    b->pos[1] = y;
    b->pos[2] = z;
    b->vel[0] = vx;
    b->vel[1] = vy;
    b->vel[2] = vz;
    return b;
}

// Calculates the distance between two bodies using the Pythagorean theorem
double distance(body* b1, body* b2) {
    double x_diff = b1->pos[0] - b2->pos[0];
    double y_diff = b1->pos[1] - b2->pos[1];
    double z_diff = b1->pos[2] - b2->pos[2];
    return sqrt(pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2));
}

// Updates the velocity of b1 based on the gravitational force from b2
void update_velocity(body* b1, body* b2, double dt) {
    double dist = distance(b1, b2);
    double force = G * b1->mass * b2->mass / pow(dist, 2);
    double x_diff = b2->pos[0] - b1->pos[0];
    double y_diff = b2->pos[1] - b1->pos[1];
    double z_diff = b2->pos[2] - b1->pos[2];
    b1->vel[0] += force / b1->mass * x_diff / dist * dt;
    b1->vel[1] += force / b1->mass * y_diff / dist * dt;
    b1->vel[2] += force / b1->mass * z_diff / dist * dt;
}

// Updates the position of a body based on its velocity
void update_position(body* b, double dt) {
    b->pos[0] += b->vel[0] * dt;
    b->pos[1] += b->vel[1] * dt;
    b->pos[2] += b->vel[2] * dt;
}