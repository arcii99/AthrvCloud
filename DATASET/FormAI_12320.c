//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double x, y;
} Vec2;

typedef struct {
    Vec2 pos;
    Vec2 vel;
    double mass;
} Body;

void calc_gravity_force(const Body* a, const Body* b, Vec2* force)
{
    double dx = b->pos.x - a->pos.x;
    double dy = b->pos.y - a->pos.y;
    double r2 = dx * dx + dy * dy;
    double r = sqrt(r2);
    double f = G * a->mass * b->mass / r2;
    force->x = f * dx / r;
    force->y = f * dy / r;
}

void update_velocity_and_position(Body* body, const Vec2* force, double delta_t)
{
    double a_x = force->x / body->mass;
    double a_y = force->y / body->mass;
    body->vel.x += a_x * delta_t;
    body->vel.y += a_y * delta_t;
    body->pos.x += body->vel.x * delta_t;
    body->pos.y += body->vel.y * delta_t;
}

int main()
{
    Body bodies[] = {
        { {0, 0}, {0, 0}, 5.974e24 },
        { {1.495e11, 0}, {0, 29784}, 1.989e30 }
    };
    size_t num_bodies = 2;

    const double delta_t = 3600; // seconds
    for (int t = 0; t < 365 * 24; t++) { // simulate 1 year
        Vec2 total_force[num_bodies];
        for (int i = 0; i < num_bodies; i++) {
            total_force[i].x = 0;
            total_force[i].y = 0;
        }
        for (int i = 0; i < num_bodies; i++) {
            for (int j = i + 1; j < num_bodies; j++) {
                Vec2 force;
                calc_gravity_force(&bodies[i], &bodies[j], &force);
                total_force[i].x += force.x;
                total_force[i].y += force.y;
                total_force[j].x -= force.x;
                total_force[j].y -= force.y;
            }
        }
        for (int i = 0; i < num_bodies; i++) {
            update_velocity_and_position(&bodies[i], &total_force[i], delta_t);
            printf("Body %d: pos = (%f, %f), vel = (%f, %f)\n", i, bodies[i].pos.x, bodies[i].pos.y, bodies[i].vel.x, bodies[i].vel.y);
        }
    }
    return 0;
}