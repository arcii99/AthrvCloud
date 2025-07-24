//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PLANETS 10
#define MAX_MASS 1000
#define MAX_DISTANCE 1000
#define G_CONSTANT 6.67408E-11

typedef struct {
    double x;
    double y;
    double mass;
} Planet;

double calculate_distance(Planet planet1, Planet planet2) {
    return sqrt(pow(planet2.x - planet1.x, 2) + pow(planet2.y - planet1.y, 2));
}

double calculate_force(Planet planet1, Planet planet2) {
    double distance = calculate_distance(planet1, planet2);
    return G_CONSTANT * planet1.mass * planet2.mass / pow(distance, 2);
}

void update_planet(Planet *planet, double force_x, double force_y, double time_delta) {
    double acceleration_x = force_x / planet->mass;
    double acceleration_y = force_y / planet->mass;
    planet->x += planet->x * time_delta + 0.5 * acceleration_x * pow(time_delta, 2);
    planet->y += planet->y * time_delta + 0.5 * acceleration_y * pow(time_delta, 2);
}

void simulate(Planet planets[], int num_planets, double time_delta, int num_steps) {
    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_planets; i++) {
            double total_force_x = 0;
            double total_force_y = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i == j) {
                    continue;
                }
                double force = calculate_force(planets[i], planets[j]);
                double angle = atan2(planets[j].y - planets[i].y, planets[j].x - planets[i].x);
                total_force_x += force * cos(angle);
                total_force_y += force * sin(angle);
            }
            update_planet(&planets[i], total_force_x, total_force_y, time_delta);
        }
    }
}

int main() {
    srand(time(NULL));
    int num_planets = rand() % MAX_PLANETS + 1;
    Planet planets[num_planets];
    for (int i = 0; i < num_planets; i++) {
        planets[i].x = rand() % MAX_DISTANCE;
        planets[i].y = rand() % MAX_DISTANCE;
        planets[i].mass = (double)(rand() % MAX_MASS) + 1;
    }
    double time_delta = (double)(rand() % 100) / 100.0;
    int num_steps = rand() % 1000 + 1;
    simulate(planets, num_planets, time_delta, num_steps);
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d final position: (%lf, %lf)\n", i+1, planets[i].x, planets[i].y);
    }
    return 0;
}