//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.67408e-11
#define TIME_STEP 0.01
#define MAX_TIME 1000

struct planet {
    double mass;
    double position[3];
    double velocity[3];
};

double distance_between(struct planet p1, struct planet p2)
{
    double dx = p2.position[0] - p1.position[0];
    double dy = p2.position[1] - p1.position[1];
    double dz = p2.position[2] - p1.position[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void update_velocity(struct planet *p1, struct planet *p2)
{
    double distance = distance_between(*p1, *p2);
    double force_magnitude = GRAVITATIONAL_CONSTANT * p1->mass * p2->mass / (distance*distance);
    double fx = force_magnitude * (p2->position[0] - p1->position[0]) / distance;
    double fy = force_magnitude * (p2->position[1] - p1->position[1]) / distance;
    double fz = force_magnitude * (p2->position[2] - p1->position[2]) / distance;
    p1->velocity[0] += fx / p1->mass * TIME_STEP;
    p1->velocity[1] += fy / p1->mass * TIME_STEP;
    p1->velocity[2] += fz / p1->mass * TIME_STEP;
}

void update_position(struct planet *p)
{
    p->position[0] += p->velocity[0] * TIME_STEP;
    p->position[1] += p->velocity[1] * TIME_STEP;
    p->position[2] += p->velocity[2] * TIME_STEP;
}

void simulate(struct planet *planets, int num_planets)
{
    for (double t = 0; t < MAX_TIME; t += TIME_STEP) {
        for (int i = 0; i < num_planets; i++) {
            for (int j = i+1; j < num_planets; j++) {
                update_velocity(&planets[i], &planets[j]);
                update_velocity(&planets[j], &planets[i]);
            }
        }
        for (int i = 0; i < num_planets; i++) {
            update_position(&planets[i]);
        }
    }
}

int main()
{
    struct planet planets[3] = {
        { 5.97e24, { 0, 0, 0 }, { 0, 0, 0 } },
        { 6.39e23, { 0, 3.84e8, 0 }, { 1022, 0, 0 } },
        { 7.35e22, { 0, 3.84e8, 3.84e8 }, { 1022, 0, 0 } }
    };
    simulate(planets, 3);
    for (int i = 0; i < 3; i++) {
        printf("Planet %d final position: (%g, %g, %g)\n", i+1, planets[i].position[0], planets[i].position[1], planets[i].position[2]);
    }
    return 0;
}