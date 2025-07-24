//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: invasive
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11

typedef struct {
    double x, y;
} Vector2D;

typedef struct {
    Vector2D position;
    Vector2D velocity;
    double mass;
} Body;

void update_velocity(Body* body, Vector2D acceleration, double time_step) {
    body->velocity.x += acceleration.x * time_step;
    body->velocity.y += acceleration.y * time_step;
}

void update_position(Body* body, double time_step) {
    body->position.x += body->velocity.x * time_step;
    body->position.y += body->velocity.y * time_step;
}

double compute_distance(Vector2D position1, Vector2D position2) {
    double dx = position2.x - position1.x;
    double dy = position2.y - position1.y;
    return sqrt(dx*dx + dy*dy);
}

Vector2D compute_gravity(Body* body1, Body* body2) {
    double distance = compute_distance(body1->position, body2->position);
    double force_magnitude = G * body1->mass * body2->mass / (distance * distance);
    Vector2D direction;
    direction.x = (body2->position.x - body1->position.x) / distance;
    direction.y = (body2->position.y - body1->position.y) / distance;
    Vector2D force;
    force.x = force_magnitude * direction.x;
    force.y = force_magnitude * direction.y;
    return force;
}

int main() {
    double time_step = 0.01;
    Body sun = { {0, 0}, {0, 0}, 1.989e+30 };
    Body earth = { {149.6e+9, 0}, {0, 29.78e3}, 5.972e+24 };
    Body moon = { {149.6e+9 + 384.4e+6, 0}, {0, 29.78e3 + 1.022e3}, 7.342e+22 };

    for (double time = 0; time < 365.25*24*3600; time += time_step) {
        Vector2D gravity1 = compute_gravity(&sun, &earth);
        Vector2D gravity2 = compute_gravity(&earth, &moon);

        update_velocity(&sun, gravity1, time_step);
        update_position(&sun, time_step);

        update_velocity(&earth, gravity2, time_step);
        update_velocity(&earth, gravity1, time_step);
        update_position(&earth, time_step);

        update_velocity(&moon, gravity1, time_step);
        update_velocity(&moon, gravity2, time_step);
        update_position(&moon, time_step);

        printf("%lf %lf %lf %lf %lf %lf\n", sun.position.x, sun.position.y, earth.position.x, earth.position.y, moon.position.x, moon.position.y);
    }
    return 0;
}