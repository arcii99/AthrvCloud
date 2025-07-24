//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11

struct planet {
    char name[20];
    double mass;
    double position[3];
    double velocity[3];
    double acceleration[3];
};

void update_acceleration(struct planet *p1, struct planet *p2) {
    double r = sqrt(pow(p1->position[0]-p2->position[0], 2)
                    + pow(p1->position[1]-p2->position[1], 2)
                    + pow(p1->position[2]-p2->position[2], 2));

    double a = G * p2->mass / pow(r, 2);

    p1->acceleration[0] += a * (p2->position[0]-p1->position[0]) / r;
    p1->acceleration[1] += a * (p2->position[1]-p1->position[1]) / r;
    p1->acceleration[2] += a * (p2->position[2]-p1->position[2]) / r;
}

void update_velocity(struct planet *p, double dt) {
    p->velocity[0] += p->acceleration[0] * dt;
    p->velocity[1] += p->acceleration[1] * dt;
    p->velocity[2] += p->acceleration[2] * dt;
}

void update_position(struct planet *p, double dt) {
    p->position[0] += p->velocity[0] * dt;
    p->position[1] += p->velocity[1] * dt;
    p->position[2] += p->velocity[2] * dt;
}

void simulate(struct planet *planets, int n_planets, double dt, int n_steps) {
    for (int step=0; step<n_steps; step++) {
        for (int i=0; i<n_planets; i++) {
            planets[i].acceleration[0] = 0;
            planets[i].acceleration[1] = 0;
            planets[i].acceleration[2] = 0;

            for (int j=0; j<n_planets; j++) {
                if (i != j) {
                    update_acceleration(&planets[i], &planets[j]);
                }
            }
        }

        for (int i=0; i<n_planets; i++) {
            update_velocity(&planets[i], dt);
            update_position(&planets[i], dt);
        }

        printf("Step %d:\n", step+1);
        for (int i=0; i<n_planets; i++) {
            printf("%s:\tx:%.2f\ty:%.2f\tz:%.2f\n", planets[i].name,
                   planets[i].position[0], planets[i].position[1], planets[i].position[2]);
        }
    }
}

int main() {
    struct planet earth = {"Earth", 5.97e24, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    struct planet moon = {"Moon", 7.34e22, {384400000, 0, 0}, {0, 1022, 0}, {0, 0, 0}};
    struct planet mars = {"Mars", 6.39e23, {230000000, 0, 0}, {0, 0, 2410}, {0, 0, 0}};
    struct planet planets[] = {earth, moon, mars};

    int n_planets = sizeof(planets)/sizeof(planets[0]);
    double dt = 3600;
    int n_steps = 24;

    simulate(planets, n_planets, dt, n_steps);

    return 0;
}