//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_OF_BODIES 5
#define G_CONST 6.67430e-11
#define DELTA_T 86400

struct body {
    double mass;
    double radius;
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
    double force_x;
    double force_y;
};

struct body bodies[NUM_OF_BODIES];

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void compute_forces() {
    int i, j;
    double r, force;
    for (i = 0; i < NUM_OF_BODIES; i++) {
        bodies[i].force_x = 0;
        bodies[i].force_y = 0;
        for (j = 0; j < NUM_OF_BODIES; j++) {
            if (i == j) {
                continue;
            }
            r = distance(bodies[i].pos_x, bodies[i].pos_y, bodies[j].pos_x, bodies[j].pos_y);
            force = (G_CONST * bodies[i].mass * bodies[j].mass) / pow(r, 2);
            bodies[i].force_x += (force * (bodies[j].pos_x - bodies[i].pos_x)) / r;
            bodies[i].force_y += (force * (bodies[j].pos_y - bodies[i].pos_y)) / r;
        }
    }
}

void update_positions() {
    int i;
    for (i = 0; i < NUM_OF_BODIES; i++) {
        bodies[i].pos_x += bodies[i].vel_x * DELTA_T;
        bodies[i].pos_y += bodies[i].vel_y * DELTA_T;
    }
}

void update_velocities() {
    int i;
    for (i = 0; i < NUM_OF_BODIES; i++) {
        bodies[i].vel_x += bodies[i].force_x / bodies[i].mass * DELTA_T;
        bodies[i].vel_y += bodies[i].force_y / bodies[i].mass * DELTA_T;
    }
}

void print_state(int day) {
    int i;
    printf("\nDay: %d\n", day);
    for (i = 0; i < NUM_OF_BODIES; i++) {
        printf("\nBody %d\n", i+1);
        printf("\tPosition: (%.5lf, %.5lf)\n", bodies[i].pos_x, bodies[i].pos_y);
        printf("\tVelocity: (%.5lf, %.5lf)\n", bodies[i].vel_x, bodies[i].vel_y);
    }
}

int main() {
    srand(time(NULL));

    // Set up bodies
    bodies[0].mass = 5.97e24;
    bodies[0].radius = 6371000;
    bodies[0].pos_x = 0;
    bodies[0].pos_y = 0;
    bodies[0].vel_x = 0;
    bodies[0].vel_y = 0;

    int i;
    for (i = 1; i < NUM_OF_BODIES; i++) {
        bodies[i].mass = 10000 + rand() % 90000;
        bodies[i].radius = 10000 + rand() % 40000;
        bodies[i].pos_x = rand() % 50000000;
        bodies[i].pos_y = rand() % 50000000;
        bodies[i].vel_x = (rand() % 500) * pow(-1, rand());
        bodies[i].vel_y = (rand() % 500) * pow(-1, rand());
    }

    int day;
    for (day = 1; day <= 365; day++) {
        compute_forces();
        update_positions();
        compute_forces();
        update_velocities();
        print_state(day);
    }

    return 0;
}