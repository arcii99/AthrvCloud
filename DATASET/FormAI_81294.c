//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67428e-11

struct planet {
    char name[10];
    double mass;
    double position[3];
    double velocity[3];
    double acceleration[3];
};

void calculate_acceleration(struct planet *pl, struct planet *all_pl, int num_pl) {
    for (int i = 0; i < num_pl; i++) {
        if (pl == &all_pl[i]) {
            continue; // No need to calculate gravity with itself
        }
        double distance = sqrt(pow(all_pl[i].position[0] - pl->position[0], 2) +
                               pow(all_pl[i].position[1] - pl->position[1], 2) +
                               pow(all_pl[i].position[2] - pl->position[2], 2));
        double magnitude = G * all_pl[i].mass / pow(distance, 2);
        for (int j = 0; j < 3; j++) {
            pl->acceleration[j] += magnitude * (all_pl[i].position[j] - pl->position[j]) / distance;
        }
    }
}

void update_velocity(struct planet *pl, double time_step) {
    for (int i = 0; i < 3; i++) {
        pl->velocity[i] += pl->acceleration[i] * time_step;
    }
}

void update_position(struct planet *pl, double time_step) {
    for (int i = 0; i < 3; i++) {
        pl->position[i] += pl->velocity[i] * time_step;
    }
}

int main() {
    srand(time(NULL));

    int num_planets = 5;
    struct planet planets[num_planets];

    // Set up planets
    strcpy(planets[0].name, "Mercury");
    planets[0].mass = 3.30e23;
    planets[0].position[0] = 0;
    planets[0].position[1] = 0;
    planets[0].position[2] = 0;
    planets[0].velocity[0] = 0;
    planets[0].velocity[1] = 0;
    planets[0].velocity[2] = 0;

    strcpy(planets[1].name, "Venus");
    planets[1].mass = 4.869e24;
    planets[1].position[0] = 0.723 * 1.496e11;
    planets[1].position[1] = 0;
    planets[1].position[2] = 0;
    planets[1].velocity[0] = 0;
    planets[1].velocity[1] = 35.02e3;
    planets[1].velocity[2] = 0;

    strcpy(planets[2].name, "Earth");
    planets[2].mass = 5.97e24;
    planets[2].position[0] = 1 * 1.496e11;
    planets[2].position[1] = 0;
    planets[2].position[2] = 0;
    planets[2].velocity[0] = 0;
    planets[2].velocity[1] = 29.78e3;
    planets[2].velocity[2] = 0;

    strcpy(planets[3].name, "Mars");
    planets[3].mass = 6.39e23;
    planets[3].position[0] = 1.524 * 1.496e11;
    planets[3].position[1] = 0;
    planets[3].position[2] = 0;
    planets[3].velocity[0] = 0;
    planets[3].velocity[1] = 24.07e3;
    planets[3].velocity[2] = 0;

    strcpy(planets[4].name, "Jupiter");
    planets[4].mass = 1.898e27;
    planets[4].position[0] = 5.20 * 1.496e11;
    planets[4].position[1] = 0;
    planets[4].position[2] = 0;
    planets[4].velocity[0] = 0;
    planets[4].velocity[1] = 13.07e3;
    planets[4].velocity[2] = 0;

    double time_step = 3600 * 24; // A day
    int num_steps = 365 * 10; // 10 years
    for (int i = 0; i < num_planets; i++) {
        calculate_acceleration(&planets[i], planets, num_planets);
    }
    for (int i = 0; i < num_steps; i++) {
        for (int j = 0; j < num_planets; j++) {
            update_velocity(&planets[j], time_step);
        }
        for (int j = 0; j < num_planets; j++) {
            update_position(&planets[j], time_step);
        }
        for (int j = 0; j < num_planets; j++) {
            calculate_acceleration(&planets[j], planets, num_planets);
        }
        printf("Step %d:\n", i+1);
        for (int j = 0; j < num_planets; j++) {
            printf("%s - Position: (%.2f, %.2f, %.2f), Velocity: (%.2f, %.2f, %.2f), Acceleration: (%.2f, %.2f, %.2f)\n",
                   planets[j].name, planets[j].position[0], planets[j].position[1], planets[j].position[2],
                   planets[j].velocity[0], planets[j].velocity[1], planets[j].velocity[2],
                   planets[j].acceleration[0], planets[j].acceleration[1], planets[j].acceleration[2]);
        }
        printf("\n");
    }

    return 0;
}