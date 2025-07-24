//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define G 6.67e-11 // gravitational constant

struct planet {
    char* name; // planet name
    double mass; // planet mass (kg)
    double x; // position in x-axis (m)
    double y; // position in y-axis (m)
    double vx; // velocity in x-axis (m/s)
    double vy; // velocity in y-axis (m/s)
    double ax; // acceleration in x-axis (m/s^2)
    double ay; // acceleration in y-axis (m/s^2)
};

void update_acceleration(struct planet* p, struct planet* all_planets, int num_planets) {
    double dist, dist_cubed, force;
    double ax = 0, ay = 0;
    for (int i = 0; i < num_planets; i++) {
        if (p == &all_planets[i]) // skip self-interaction
            continue;
        dist = sqrt(pow(all_planets[i].x - p->x, 2) + pow(all_planets[i].y - p->y, 2));
        dist_cubed = pow(dist, 3);
        force = G * all_planets[i].mass / dist_cubed;
        ax += force * (all_planets[i].x - p->x);
        ay += force * (all_planets[i].y - p->y);
    }
    p->ax = ax;
    p->ay = ay;
}

void update_velocity(struct planet* p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
}

void update_position(struct planet* p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

int main() {
    srand(time(NULL)); // seed for random number
    int num_planets = 4; // number of planets in the simulation

    // create planets
    struct planet planets[] = {
        {"Earth", 5.97e24, 0, 0, 0, 0, 0, 0},
        {"Jupiter", 1.90e27, 4.20e11, 0, 0, 13.07e3, 0, 0},
        {"Mars", 6.39e23, 0, 2.28e11, -24.07e3, 0, 0, 0},
        {"Venus", 4.87e24, -1.08e11, 0, 0, -35.00e3, 0, 0}
    };

    double dt = 3600 * 24; // time step (1 day)

    // time loop
    for (int t = 0; t < 365; t++) {
        // update accelerations
        for (int i = 0; i < num_planets; i++)
            update_acceleration(&planets[i], planets, num_planets);
        // update velocities
        for (int i = 0; i < num_planets; i++)
            update_velocity(&planets[i], dt);
        // update positions
        for (int i = 0; i < num_planets; i++)
            update_position(&planets[i], dt);
        // print positions
        printf("Day %d\n", t);
        for (int i = 0; i < num_planets; i++)
            printf("%s\t(%.2e, %.2e)\n", planets[i].name, planets[i].x, planets[i].y);
        printf("\n");
    }

    return 0;
}