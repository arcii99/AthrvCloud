//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: optimized
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11

typedef struct {
    double x;
    double y;
    double z;
} Vec3;

typedef struct {
    Vec3 pos;
    Vec3 vel;
    double mass;
} Body;

void update_velocity(Body* bodies, int num_bodies, double timestep)
{
    int i, j;

    for (i = 0; i < num_bodies; i++) {
        Body* a = &bodies[i];

        for (j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue;
            }

            Body* b = &bodies[j];

            double distance_x = b->pos.x - a->pos.x;
            double distance_y = b->pos.y - a->pos.y;
            double distance_z = b->pos.z - a->pos.z;
            double distance = sqrt(distance_x * distance_x + distance_y * distance_y + distance_z * distance_z);

            double force = G * a->mass * b->mass / (distance * distance);

            a->vel.x += force * distance_x / distance * timestep;
            a->vel.y += force * distance_y / distance * timestep;
            a->vel.z += force * distance_z / distance * timestep;
        }
    }
}

void update_position(Body* bodies, int num_bodies, double timestep)
{
    int i;

    for (i = 0; i < num_bodies; i++) {
        Body* a = &bodies[i];

        a->pos.x += a->vel.x * timestep;
        a->pos.y += a->vel.y * timestep;
        a->pos.z += a->vel.z * timestep;
    }
}

void simulate(Body* bodies, int num_bodies, double timestep, int num_steps)
{
    int step;

    for (step = 0; step < num_steps; step++) {
        update_velocity(bodies, num_bodies, timestep);
        update_position(bodies, num_bodies, timestep);
    }
}

int main()
{
    Body sun = {{0, 0, 0}, {0, 0, 0}, 1.989e30};
    Body earth = {{-147.09e9, 0, 0}, {0, 30.29e3, 0}, 5.97e24};
    Body moon = {{-147.097e9 + 384.4e6, 0, 0}, {0, 30.29e3 + 1022, 0}, 7.342e22};

    Body bodies[] = {sun, earth, moon};

    simulate(bodies, sizeof(bodies) / sizeof(*bodies), 60 * 60 * 24, 365);

    return 0;
}