//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11   /* gravitational constant */
#define WINDOW_SIZE 600 /* window size */

typedef struct {
    float x, y;
} Vector2D;

typedef struct {
    Vector2D pos, vel, acc;
    float mass;
} Body;

int main(void) {
    /* set up the solar system */

    Body sun = {
        .pos = {0, 0},
        .vel = {0, 0},
        .acc = {0, 0},
        .mass = 1.989e30
    };

    Body earth = {
        .pos = {147e9, 0},
        .vel = {0, 30.29e3},
        .acc = {0, 0},
        .mass = 5.972e24
    };

    Body moon = {
        .pos = {147e9 + 384e6, 0},
        .vel = {0, 30.29e3 + 1.022e3},
        .acc = {0, 0},
        .mass = 7.348e22
    };

    Body mars = {
        .pos = {-227.9e9, 0},
        .vel = {0, -24.07e3},
        .acc = {0, 0},
        .mass = 6.39e23
    };

    Body venus = {
        .pos = {108.2e9, 0},
        .vel = {0, 35.26e3},
        .acc = {0, 0},
        .mass = 4.87e24
    };

    Body bodies[] = {sun, earth, moon, mars, venus};
    int num_bodies = sizeof(bodies) / sizeof(bodies[0]);

    /* simulation loop */

    float t, dt = 1e5;
    int i, j;

    for (t = 0; t <= 5e8; t += dt) {
        /* update accelerations */

        for (i = 0; i < num_bodies; i++) {
            Body *body = &bodies[i];
            body->acc.x = body->acc.y = 0;

            for (j = 0; j < num_bodies; j++) {
                if (i == j) continue;
                Body *other = &bodies[j];

                Vector2D r;
                r.x = other->pos.x - body->pos.x;
                r.y = other->pos.y - body->pos.y;

                float dist = sqrt(r.x * r.x + r.y * r.y);
                float force = G * body->mass * other->mass / (dist * dist);

                body->acc.x += force * r.x / dist / body->mass;
                body->acc.y += force * r.y / dist / body->mass;
            }
        }

        /* update velocities and positions */

        for (i = 0; i < num_bodies; i++) {
            Body *body = &bodies[i];

            body->vel.x += body->acc.x * dt;
            body->vel.y += body->acc.y * dt;

            body->pos.x += body->vel.x * dt;
            body->pos.y += body->vel.y * dt;
        }

        /* render */

        system("clear");

        float scale = (WINDOW_SIZE - 100) / 2e11;
        int x_offset = WINDOW_SIZE / 2, y_offset = WINDOW_SIZE / 2;

        for (i = 0; i < num_bodies; i++) {
            Body *body = &bodies[i];
            int radius = scale * pow(body->mass, 1.0 / 3);
            int x = x_offset + scale * body->pos.x;
            int y = y_offset - scale * body->pos.y;
            printf("\033[38;2;%d;%d;%dm", rand() % 256, rand() % 256, rand() % 256);
            printf("o");
            printf("\033[0m");
        }

        usleep(10000); /* sleep for 10ms to control animation speed */
    }

    return 0;
}