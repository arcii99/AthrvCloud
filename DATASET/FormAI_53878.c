//FormAI DATASET v1.0 Category: Physics simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.81

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    double mass;
} Particle;

void update_particle(Particle *p, double dt) {
    p->position.x += p->velocity.x * dt + 0.5 * p->acceleration.x * dt * dt;
    p->position.y += p->velocity.y * dt + 0.5 * p->acceleration.y * dt * dt;
    p->velocity.x += p->acceleration.x * dt;
    p->velocity.y += p->acceleration.y * dt;
}

void apply_gravity(Particle *p) {
    p->acceleration.y = -GRAVITY * p->mass;
}

int main() {
    Particle ball;
    ball.position.x = 0.0;
    ball.position.y = 0.0;
    ball.velocity.x = 10.0;
    ball.velocity.y = 20.0;
    ball.acceleration.x = 0.0;
    ball.acceleration.y = 0.0;
    ball.mass = 1.0;

    double dt = 0.01;
    double time = 0.0;

    printf("Time\tx\ty\n");

    while (ball.position.y >= 0.0) {
        apply_gravity(&ball);
        update_particle(&ball, dt);
        time += dt;
        printf("%.2f\t%.2f\t%.2f\n", time, ball.position.x, ball.position.y);
    }

    return 0;
}