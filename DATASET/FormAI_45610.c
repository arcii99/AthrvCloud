//FormAI DATASET v1.0 Category: Physics simulation ; Style: realistic
#include <stdio.h>
#include <math.h>

#define GRAV_CONSTANT 6.67408e-11
#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Vector;

typedef struct {
    Vector position, velocity, acceleration;
    double mass;
} Body;

void calculate_acceleration(Body *body, Body *bodies, int num_bodies) {
    Vector acceleration = {0, 0};
    for(int i = 0; i < num_bodies; i++) {
        if(body == &bodies[i])
            continue;
        double dx = bodies[i].position.x - body->position.x;
        double dy = bodies[i].position.y - body->position.y;
        double distance = sqrt(pow(dx, 2) + pow(dy, 2));
        double force = GRAV_CONSTANT * body->mass * bodies[i].mass / pow(distance, 2);
        double angle = atan2(dy, dx);
        acceleration.x += force / body->mass * cos(angle);
        acceleration.y += force / body->mass * sin(angle);
    }
    body->acceleration = acceleration;
}

Vector calculate_velocity(Vector velocity, Vector acceleration, double time_step) {
    velocity.x += acceleration.x * time_step;
    velocity.y += acceleration.y * time_step;
    return velocity;
}

Vector calculate_position(Vector position, Vector velocity, double time_step) {
    position.x += velocity.x * time_step;
    position.y += velocity.y * time_step;
    return position;
}

int main() {
    int num_bodies = 2;
    Body bodies[num_bodies];

    // Body 1
    bodies[0].position = (Vector){0, 0};
    bodies[0].velocity = (Vector){0, 0};
    bodies[0].mass = 100;

    // Body 2
    bodies[1].position = (Vector){100, 0};
    bodies[1].velocity = (Vector){0, 10};
    bodies[1].mass = 50;

    double time_step = 1;
    double duration = 10;

    for(double t = 0; t <= duration; t += time_step) {
        for(int i = 0; i < num_bodies; i++) {
            calculate_acceleration(&bodies[i], bodies, num_bodies);
            bodies[i].velocity = calculate_velocity(bodies[i].velocity, bodies[i].acceleration, time_step);
            bodies[i].position = calculate_position(bodies[i].position, bodies[i].velocity, time_step);
        }
        printf("Time: %g\n", t);
        for(int i = 0; i < num_bodies; i++) {
            printf("Body %d - Position: (%g, %g), Velocity: (%g, %g)\n", i + 1, bodies[i].position.x, bodies[i].position.y, bodies[i].velocity.x, bodies[i].velocity.y);
        }
        printf("\n");
    }

    return 0;
}