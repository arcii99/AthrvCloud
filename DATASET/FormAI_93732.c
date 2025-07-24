//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: portable
#include<stdio.h>
#include<math.h>
#define G 6.67430e-11

struct planet {
    char name[20];
    double mass;
    double radius;
    double position[3];
    double velocity[3];
    double acceleration[3];
    double force[3];
};
typedef struct planet Planet;

// Compute the distance between two planets
double distance(Planet *p1, Planet *p2) {
    double dx = p1->position[0] - p2->position[0];
    double dy = p1->position[1] - p2->position[1];
    double dz = p1->position[2] - p2->position[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Compute the gravitational force between two planets
void gravitational_force(Planet *p1, Planet *p2) {
    double r = distance(p1, p2);
    double f = G * p1->mass * p2->mass / (r*r);
    p1->force[0] += f * (p2->position[0] - p1->position[0]) / r;
    p1->force[1] += f * (p2->position[1] - p1->position[1]) / r;
    p1->force[2] += f * (p2->position[2] - p1->position[2]) / r;
}

// Update the position, velocity, acceleration, and force of each planet
void update(Planet *planets, int N, double dt) {
    for (int i = 0; i < N; i++) {
        planets[i].acceleration[0] = planets[i].force[0] / planets[i].mass;
        planets[i].acceleration[1] = planets[i].force[1] / planets[i].mass;
        planets[i].acceleration[2] = planets[i].force[2] / planets[i].mass;
        planets[i].position[0] += planets[i].velocity[0] * dt + 0.5 * planets[i].acceleration[0] * dt * dt;
        planets[i].position[1] += planets[i].velocity[1] * dt + 0.5 * planets[i].acceleration[1] * dt * dt;
        planets[i].position[2] += planets[i].velocity[2] * dt + 0.5 * planets[i].acceleration[2] * dt * dt;
        planets[i].velocity[0] += planets[i].acceleration[0] * dt;
        planets[i].velocity[1] += planets[i].acceleration[1] * dt;
        planets[i].velocity[2] += planets[i].acceleration[2] * dt;
        planets[i].force[0] = planets[i].force[1] = planets[i].force[2] = 0.0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            gravitational_force(&planets[i], &planets[j]);
            gravitational_force(&planets[j], &planets[i]);
        }
    }
}

int main() {
    Planet planets[3] = {
        {"earth", 5.972e24, 6371.0, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}},
        {"moon", 7.349e22, 1737.0, {0.0, 384400000.0, 0.0}, {1022.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}},
        {"sun", 1.989e30, 696340.0, {149600000000.0, 0.0, 0.0}, {0.0, 30290.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}
    };
    double dt = 86400.0;
    int steps = 365;
    for (int i = 0; i < steps; i++) {
        printf("Step %d:\n", i+1);
        for (int j = 0; j < 3; j++) {
            printf("%s: (%.2f, %.2f, %.2f)\n", planets[j].name, planets[j].position[0], planets[j].position[1], planets[j].position[2]);
        }
        printf("\n");
        update(planets, 3, dt);
    }
    return 0;
}