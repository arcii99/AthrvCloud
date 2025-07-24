//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.8 // m/s^2
#define TIME_STEP 0.01 // s

typedef struct {
    double x;
    double y;
} Vector2d;

typedef struct {
    Vector2d position;
    Vector2d velocity;
    double mass;
} Particle;

void integrate(Particle *p) {
    Vector2d acceleration = {0, -GRAVITY};
    Vector2d delta_v = {acceleration.x * TIME_STEP, acceleration.y * TIME_STEP};
    p->velocity.x += delta_v.x;
    p->velocity.y += delta_v.y;
    Vector2d delta_p = {p->velocity.x * TIME_STEP, p->velocity.y * TIME_STEP};
    p->position.x += delta_p.x;
    p->position.y += delta_p.y;
}

int main() {
    printf("*** Basic Physics Simulation ***\n");
    Particle ball = {{0, 0}, {10, 10}, 0.25};
    Particle floor = {{0, -10}, {0, 0}, INFINITY};

    int t = 0;
    double t_final = 10;
    while (t < t_final) {
        printf("Time: %.2fs | Ball Position: (%.2f, %.2f)\n", t, ball.position.x, ball.position.y);
        integrate(&ball);
        t += TIME_STEP;
        if (ball.position.y < floor.position.y) {
            printf("Ball hits floor at %.2fs\n", t);
            break;
        }
    }

    return 0;
}