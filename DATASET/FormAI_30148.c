//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <math.h>

#define G 6.674e-11
#define TIME_STEP 3600
#define NUMBER_OF_PLANETS 3
#define UNIVERSE_SIZE 100

struct Planet {
    double x, y;
    double mass;
    double ax, ay;
    double vx, vy;
};

void updatePosition(struct Planet *p, double time_step) {
    p->vx += p->ax * time_step;
    p->vy += p->ay * time_step;
    p->x += p->vx * time_step;
    p->y += p->vy * time_step;
}

void updateAcceleration(struct Planet *p, struct Planet *planets, int n) {
    double distance, force;

    p->ax = 0;
    p->ay = 0;

    for (int i = 0; i < n; i++) {
        if (p == &planets[i]) {
            continue;
        }

        distance = sqrt(pow(p->x - planets[i].x, 2) + pow(p->y - planets[i].y, 2));
        force = G * p->mass * planets[i].mass / pow(distance, 2);

        p->ax += force * (planets[i].x - p->x) / (p->mass * distance);
        p->ay += force * (planets[i].y - p->y) / (p->mass * distance);
    }
}

int main() {
    struct Planet planets[NUMBER_OF_PLANETS] = {
        {.x = 50, .y = 50, .mass = 1e5},
        {.x = 80, .y = 80, .mass = 2e5},
        {.x = 70, .y = 70, .mass = 4e5},
    };

    for (int t = 0; t < 24 * 60 * 60; t += TIME_STEP) {
        for (int i = 0; i < NUMBER_OF_PLANETS; i++) {
            updateAcceleration(&planets[i], planets, NUMBER_OF_PLANETS);
        }

        for (int i = 0; i < NUMBER_OF_PLANETS; i++) {
            updatePosition(&planets[i], TIME_STEP);
        }

        for (int i = 0; i < NUMBER_OF_PLANETS; i++) {
            printf("planet %d: x = %lf, y = %lf, vx = %lf, vy = %lf\n", i, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
        }

        printf("\n");
    }

    return 0;
}