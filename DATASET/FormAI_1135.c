//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 0.1
#define TIME_STEP 0.1
#define MAX_STEPS 100

typedef struct planet {
    double x;
    double y;
    double mass;
    double vx;
    double vy;
} Planet;

void update_velocities(Planet *p1, Planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx*dx + dy*dy);
    double force = GRAVITY * (p1->mass * p2->mass) / (distance * distance);
    p1->vx += force * dx / distance;
    p1->vy += force * dy / distance;
    p2->vx -= force * dx / distance;
    p2->vy -= force * dy / distance;
}

void update_position(Planet *p) {
    p->x += p->vx * TIME_STEP;
    p->y += p->vy * TIME_STEP;
}

int main(void) {
    Planet planets[2] = {
        { .x = -10, .y = 0, .mass = 10, .vx = 0, .vy = 0 },
        { .x = 10, .y = 0, .mass = 10, .vx = 0, .vy = 0 }
    };
    int i, j, step;
    for (step = 0; step < MAX_STEPS; step++) {
        for (i = 0; i < 2; i++) {
            for (j = i+1; j < 2; j++) {
                update_velocities(&planets[i], &planets[j]);
            }
        }
        for (i = 0; i < 2; i++) {
            update_position(&planets[i]);
            printf("Position of planet %d: (%lf, %lf)\n", i, planets[i].x, planets[i].y);
        }
    }
    return 0;
}