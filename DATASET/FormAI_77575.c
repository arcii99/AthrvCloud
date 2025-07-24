//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cryptic
#include <stdio.h>
#include <math.h>

#define MAX_PLANETS 10

struct planet {
    double mass;
    double x, y;
    double vx, vy;
};

struct universe {
    size_t n_planets;
    struct planet planets[MAX_PLANETS];
};

void update_positions(struct universe *u, double dt);
void update_velocities(struct universe *u, double dt);

void print_universe(struct universe *u) {
    for (size_t i = 0; i < u->n_planets; ++i) {
        printf("Planet %ld: (%lf, %lf)\n", i, u->planets[i].x, u->planets[i].y);
    }
}

void simulate(struct universe *u, size_t n_steps, double dt) {
    printf("Starting simulation with %ld steps and time step %lf.\n", n_steps, dt);
    for (size_t i = 0; i < n_steps; ++i) {
        update_positions(u, dt);
        update_velocities(u, dt);
    }
    printf("Simulation done.\n");
}

void update_positions(struct universe *u, double dt) {
    for (size_t i = 0; i < u->n_planets; ++i) {
        u->planets[i].x += u->planets[i].vx * dt;
        u->planets[i].y += u->planets[i].vy * dt;
    }
}

void update_velocities(struct universe *u, double dt) {
    for (size_t i = 0; i < u->n_planets; ++i) {
        for (size_t j = 0; j < u->n_planets; ++j) {
            if (i == j) {
                continue;
            }
            double dx = u->planets[j].x - u->planets[i].x;
            double dy = u->planets[j].y - u->planets[i].y;
            double r = sqrt(dx * dx + dy * dy);
            double f = u->planets[j].mass / r / r;
            u->planets[i].vx += f * dx * dt;
            u->planets[i].vy += f * dy * dt;
        }
    }
}

int main() {
    struct universe u = {2, {
        {10.0, 0.0, 0.0, 0.0, 0.0},
        {100.0, 1.0, 0.0, 0.0, 10.0},
    }};
    printf("Initial universe configuration:\n");
    print_universe(&u);
    simulate(&u, 10000, 0.001);
    printf("Final universe configuration:\n");
    print_universe(&u);
    return 0;
}