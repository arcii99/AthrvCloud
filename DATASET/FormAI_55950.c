//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: surprised
#include <stdio.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265359
#define G 6.67430e-11

struct position {
    double x, y;
};

struct velocity {
    double vx, vy;
};

struct body {
    double mass, radius;
    struct position pos;
    struct velocity vel;
    struct position force;
};

void init_body(struct body *b, double mass, double radius, double x, double y, double vx, double vy) {
	  b->mass = mass;
	  b->radius = radius;
	  b->pos.x = x;
	  b->pos.y = y;
	  b->vel.vx = vx;
	  b->vel.vy = vy;
	  b->force.x = 0;
	  b->force.y = 0;
}

void calc_force(struct body *b1, struct body *b2) {
    double dx, dy, dist, f;

    dx = b2->pos.x - b1->pos.x;
    dy = b2->pos.y - b1->pos.y;
    dist = sqrt(dx * dx + dy * dy);

    if (dist == 0) {
        f = 0;
    } else {
        f = G * b1->mass * b2->mass / (dist * dist);
    }

    b1->force.x += f * dx / dist;
    b1->force.y += f * dy / dist;
}

void simulate(struct body *bodies, int num_bodies, double dt) {
    int i, j;

    for (i = 0; i < num_bodies; i++) {
        for (j = 0; j < num_bodies; j++) {
            if (i != j) {
            	calc_force(&bodies[i], &bodies[j]);
            }
        }
    }

    for (i = 0; i < num_bodies; i++) {
        double ax = bodies[i].force.x / bodies[i].mass;
        double ay = bodies[i].force.y / bodies[i].mass;

        bodies[i].vel.vx += ax * dt;
        bodies[i].vel.vy += ay * dt;
        bodies[i].pos.x += bodies[i].vel.vx * dt;
        bodies[i].pos.y += bodies[i].vel.vy * dt;

        bodies[i].force.x = 0;
        bodies[i].force.y = 0;
    }
}

void print_body(struct body *b) {
    printf("Body position: (%.2f, %.2f)\n", b->pos.x, b->pos.y);
}

int main() {
    srand(time(NULL));

    int num_bodies = 5;
    double dt = 0.1;
    struct body bodies[num_bodies];

    init_body(&bodies[0], 1.989e30, 696340000, 0, 0, 0, 0);
    printf("Initializing Sun...\n");

    init_body(&bodies[1], 5.97e24, 6371000, 147095000000, 0, 0, 30290);
    printf("Initializing Earth...\n");

    init_body(&bodies[2], 6.39e23, 3389500, 206644545142, 0, 0, 26500);
    printf("Initializing Mars...\n");

    init_body(&bodies[3], 3.30e23, 2523200, 149598262, 0, 0, 47850);
    printf("Initializing Mercury...\n");

    init_body(&bodies[4], 4.87e24, 6051800, 108939000000, 0, 0, 34790);
    printf("Initializing Venus...\n");

    int i, j, k;
    for (k = 0; k < 10; k++) {
        for (i = 0; i < num_bodies; i++) {
            printf("Body %d position: ", i);
            print_body(&bodies[i]);
        }

        simulate(bodies, num_bodies, dt);

        printf("\n");
    }

    return 0;
}