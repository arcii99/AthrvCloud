//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 9
#define GRAV_CONST 6.673 * pow(10, -11)

struct planet {
    char name[10];
    double mass;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
};

double calculate_distance(double x1, double y1, double x2, double y2) {
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}

void update_velocity(struct planet *planets, int index1, int index2, double timestep) {
    double distance = calculate_distance(planets[index1].x_pos, planets[index1].y_pos, planets[index2].x_pos, planets[index2].y_pos);
    double force = GRAV_CONST * planets[index1].mass * planets[index2].mass / pow(distance, 2);
    double x_force = force * (planets[index2].x_pos - planets[index1].x_pos) / distance;
    double y_force = force * (planets[index2].y_pos - planets[index1].y_pos) / distance;
    planets[index1].x_vel += x_force / planets[index1].mass * timestep;
    planets[index1].y_vel += y_force / planets[index1].mass * timestep;
}

void update_position(struct planet *planet, double timestep) {
    planet->x_pos += planet->x_vel * timestep;
    planet->y_pos += planet->y_vel * timestep;
}

void print_planet_info(struct planet *planet) {
    printf("%s\t\t mass: %f kg \t x_pos: %f m \t y_pos: %f m \t x_vel: %f m/s \t y_vel: %f m/s\n", planet->name, planet->mass, planet->x_pos, planet->y_pos, planet->x_vel, planet->y_vel);
}

void simulate(struct planet *planets, double timestep, int num_steps) {
    double current_time = 0;
    for (int i = 0; i < num_steps; i++) {
        printf("Time: %f seconds\n", current_time);
        for (int j = 0; j < NUM_PLANETS; j++) {
            printf("Planet %d: ", j+1);
            print_planet_info(&planets[j]);
        }
        printf("\n");

        for (int j = 0; j < NUM_PLANETS; j++) {
            for (int k = 0; k < NUM_PLANETS; k++) {
                if (j != k) {
                    update_velocity(planets, j, k, timestep);
                }
            }
        }

        for (int j = 0; j < NUM_PLANETS; j++) {
            update_position(&planets[j], timestep);
        }

        current_time += timestep;
    }
}

int main() {
    struct planet planets[NUM_PLANETS] = {
        {"Sun", 1.99 * pow(10, 30), 0, 0, 0, 0},
        {"Mercury", 3.285 * pow(10, 23), 0, 5.79 * pow(10, 10), 47.9 * pow(10, 3), 0},
        {"Venus", 4.87 * pow(10, 24), 0, 1.08 * pow(10, 11), 35.0 * pow(10, 3), 0},
        {"Earth", 5.97 * pow(10, 24), 0, 1.50 * pow(10, 11), 29.8 * pow(10, 3), 0},
        {"Mars", 6.39 * pow(10, 23), 0, 2.28 * pow(10, 11), 24.1 * pow(10, 3), 0},
        {"Jupiter", 1.90 * pow(10, 27), 0, 7.78 * pow(10, 11), 13.1 * pow(10, 3), 0},
        {"Saturn", 5.68 * pow(10, 26), 0, 1.43 * pow(10, 12), 9.69 * pow(10, 3), 0},
        {"Uranus", 8.68 * pow(10, 25), 0, 2.87 * pow(10, 12), 6.81 * pow(10, 3), 0},
        {"Neptune", 1.02 * pow(10, 26), 0, 4.50 * pow(10, 12), 5.43 * pow(10, 3), 0},
    };

    double timestep = 3600; // 1 hour in seconds
    int num_steps = 1000;

    simulate(planets, timestep, num_steps);
    return 0;
}