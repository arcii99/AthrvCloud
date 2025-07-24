//FormAI DATASET v1.0 Category: Physics simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.673e-11     // gravitational constant

#define NUM_BODIES 2             // number of bodies in simulation

typedef struct {
    double mass;                // mass of the body (in kg)
    double pos_x;               // position in x-axis (in m)
    double pos_y;               // position in y-axis (in m)
    double vel_x;               // velocity in x-axis (in m/s)
    double vel_y;               // velocity in y-axis (in m/s)
} Body;

void calculate_force(Body *body1, Body *body2, double *force_x, double *force_y)
{
    double dist, dist_squared, force;
    double pos_diff_x, pos_diff_y;

    // calculate distance between two bodies
    pos_diff_x = body2->pos_x - body1->pos_x;
    pos_diff_y = body2->pos_y - body1->pos_y;
    dist_squared = pos_diff_x * pos_diff_x + pos_diff_y * pos_diff_y;
    dist = sqrt(dist_squared);

    // calculate gravitational force
    force = (GRAV_CONST * body1->mass * body2->mass) / dist_squared;
    *force_x = force * (pos_diff_x / dist);
    *force_y = force * (pos_diff_y / dist);
}

void update_body_pos_vel(Body *body, double force_x, double force_y, double delta_t)
{
    double accel_x, accel_y;

    // calculate acceleration
    accel_x = force_x / body->mass;
    accel_y = force_y / body->mass;

    // update velocity and position
    body->vel_x += accel_x * delta_t;
    body->vel_y += accel_y * delta_t;
    body->pos_x += body->vel_x * delta_t;
    body->pos_y += body->vel_y * delta_t;
}

int main()
{
    Body bodies[NUM_BODIES] = {
        {5.97e24, 0, 0, 0, 0},   // Earth
        {7.34e22, 3.84e8, 0, 0, 1022}   // Moon
    };
    double force_x, force_y, delta_t = 1000;      // delta_t is in seconds

    // perform simulation for 10 days
    for (int i = 0; i < 864000; i++) {
        // calculate and update forces between all body pairs
        calculate_force(&bodies[0], &bodies[1], &force_x, &force_y);
        update_body_pos_vel(&bodies[0], force_x, force_y, delta_t);
        update_body_pos_vel(&bodies[1], -force_x, -force_y, delta_t);

        // print current position of bodies
        printf("Day %d: Earth (%.2f, %.2f), Moon (%.2f, %.2f)\n",
               i / 86400 + 1, bodies[0].pos_x, bodies[0].pos_y,
               bodies[1].pos_x, bodies[1].pos_y);
    }
    return 0;
}