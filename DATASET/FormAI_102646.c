//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 8
#define G_CONST 6.674 * pow(10, -11)
#define SUN_MASS 1.989 * pow(10, 30)

typedef struct {
    char name[20];
    double mass; // in kg
    double pos[3]; // x, y, z coords in m
    double vel[3]; // x, y, z velocity in m/s
} Planet;

double distance(double pos1[], double pos2[]) {
    double x_diff = pos1[0] - pos2[0];
    double y_diff = pos1[1] - pos2[1];
    double z_diff = pos1[2] - pos2[2];
    return sqrt(pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2));
}

void update_pos(Planet* planet, double time_step) {
    for (int i = 0; i < 3; i++) {
        planet->pos[i] += planet->vel[i] * time_step;
    }
}

void update_vel(Planet* planet, double time_step, double acc[]) {
    for (int i = 0; i < 3; i++) {
        planet->vel[i] += acc[i] * time_step;
    }
}

void compute_acc(Planet* planet, Planet planets[]) {
    double net_acc[3] = {0, 0, 0};
    for (int i = 0; i < NUM_PLANETS; i++) {
        if (planet == &planets[i]) {
            continue; // skip if comparing to self
        }
        double dist = distance(planet->pos, planets[i].pos);
        double force = G_CONST * planet->mass * planets[i].mass / pow(dist, 2);
        double acc_component = force / planet->mass;
        for (int j = 0; j < 3; j++) {
            net_acc[j] += acc_component * (planets[i].pos[j] - planet->pos[j]) / dist;
        }
    }
    update_vel(planet, 1, net_acc); // update velocity immediately based on acc
}

void simulate(double time_step, Planet planets[]) {
    double accs[NUM_PLANETS][3]; // array to store accelerations of each planet
    for (int i = 0; i < NUM_PLANETS; i++) {
        compute_acc(&planets[i], planets);
    }

    // update positions
    for (int i = 0; i < NUM_PLANETS; i++) {
        update_pos(&planets[i], time_step);
    }

    // update accelerations using new positions
    for (int i = 0; i < NUM_PLANETS; i++) {
        compute_acc(&planets[i], planets);
    }
}

int main() {
    // initialize planets
    Planet planets[NUM_PLANETS] = {
        {"Mercury", 3.285 * pow(10, 23), {-5.791 * pow(10, 10), 0, 0}, {0, 47.87 * pow(10, 3), 0}},
        {"Venus", 4.867 * pow(10, 24), {0, 1.082 * pow(10, 11), 0}, {-35.02 * pow(10, 3), 0, 0}},
        {"Earth", 5.972 * pow(10, 24), {1.496 * pow(10, 11), 0, 0}, {0, 29.78 * pow(10, 3), 0}},
        {"Mars", 6.39 * pow(10, 23), {0, -2.279 * pow(10, 11), 0}, {24.077 * pow(10, 3), 0, 0}},
        {"Jupiter", 1.898 * pow(10, 27), {0, 0, 7.785 * pow(10, 11)}, {13.07 * pow(10, 3), 0, 0}},
        {"Saturn", 5.683 * pow(10, 26), {0, 0, -1.433 * pow(10, 12)}, {-9.68 * pow(10, 3), 0, 0}},
        {"Uranus", 8.681 * pow(10, 25), {0, 0, 2.844 * pow(10, 12)}, {6.81 * pow(10, 3), 0, 0}},
        {"Neptune", 1.024 * pow(10, 26), {0, 0, -4.495 * pow(10, 12)}, {-5.43 * pow(10, 3), 0, 0}}
    };

    double sim_time = 365 * 24 * 3600; // simulate for one year
    double time_step = 3600; // simulate in hourly increments

    for (double time = 0; time < sim_time; time += time_step) {
        simulate(time_step, planets);
    }

    // print final positions
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: (%.2e, %.2e, %.2e)\n", planets[i].name, planets[i].pos[0], planets[i].pos[1], planets[i].pos[2]);
    }

    return 0;
}