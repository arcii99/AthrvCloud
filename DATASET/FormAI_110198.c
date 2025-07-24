//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: shape shifting
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67430e-11

struct Body {
    char name[20];
    double mass;
    double x, y;
    double vx, vy;
};

struct System {
    int num_bodies;
    struct Body *bodies;
};

void update_system(struct System *system, double dt);
void calculate_force(struct Body *body1, struct Body *body2);
double distance(struct Body *body1, struct Body *body2);

int main() {
    srand(time(NULL));

    struct System solar_system = {
        .num_bodies = 8,
        .bodies = (struct Body[]) {
            {
                .name = "Sun",
                .mass = 1.989e30,
                .x = 0,
                .y = 0,
                .vx = 0,
                .vy = 0
            },
            {
                .name = "Mercury",
                .mass = 3.285e23,
                .x = 6.982e10,
                .y = 0,
                .vx = 0,
                .vy = 3.869e4
            },
            {
                .name = "Venus",
                .mass = 4.867e24,
                .x = 1.0821e11,
                .y = 0,
                .vx = 0,
                .vy = 3.502e4
            },
            {
                .name = "Earth",
                .mass = 5.972e24,
                .x = 1.496e11,
                .y = 0,
                .vx = 0,
                .vy = 2.978e4
            },
            {
                .name = "Mars",
                .mass = 6.39e23,
                .x = 2.279e11,
                .y = 0,
                .vx = 0,
                .vy = 2.413e4
            },
            {
                .name = "Jupiter",
                .mass = 1.898e27,
                .x = 7.784e11,
                .y = 0,
                .vx = 0,
                .vy = 1.307e4
            },
            {
                .name = "Saturn",
                .mass = 5.683e26,
                .x = 1.427e12,
                .y = 0,
                .vx = 0,
                .vy = 9.693e3
            },
            {
                .name = "Uranus",
                .mass = 8.681e25,
                .x = 2.871e12,
                .y = 0,
                .vx = 0,
                .vy = 6.835e3
            },
            {
                .name = "Neptune",
                .mass = 1.024e26,
                .x = 4.495e12,
                .y = 0,
                .vx = 0,
                .vy = 5.477e3
            }
        }
    };

    double t = 0;
    double dt = 86400; // 1 day in seconds

    while (1) {
        update_system(&solar_system, dt);

        printf("Time: %lf\n", t);
        for (int i = 0; i < solar_system.num_bodies; i++) {
            printf("%s: (%lf, %lf)\n", solar_system.bodies[i].name, solar_system.bodies[i].x, solar_system.bodies[i].y);
        }
        printf("\n");

        t += dt;
    }

    return 0;
}

void update_system(struct System *system, double dt) {
    // Calculate forces on each body
    for (int i = 0; i < system->num_bodies; i++) {
        for (int j = i + 1; j < system->num_bodies; j++) {
            calculate_force(&system->bodies[i], &system->bodies[j]);
        }
    }

    // Update each body's position and velocity
    for (int i = 0; i < system->num_bodies; i++) {
        double ax = system->bodies[i].vx;
        double ay = system->bodies[i].vy;

        system->bodies[i].vx += ax*dt;
        system->bodies[i].vy += ay*dt;

        system->bodies[i].x += system->bodies[i].vx*dt;
        system->bodies[i].y += system->bodies[i].vy*dt;
    }
}

void calculate_force(struct Body *body1, struct Body *body2) {
    double r = distance(body1, body2);
    double f = G*body1->mass*body2->mass/(r*r);
    double theta = atan2(body2->y - body1->y, body2->x - body1->x);
    double fx = f*cos(theta);
    double fy = f*sin(theta);

    body1->vx += fx/body1->mass;
    body1->vy += fy/body1->mass;

    body2->vx -= fx/body2->mass;
    body2->vy -= fy/body2->mass;
}

double distance(struct Body *body1, struct Body *body2) {
    double dx = body2->x - body1->x;
    double dy = body2->y - body1->y;
    return sqrt(dx*dx + dy*dy);
}