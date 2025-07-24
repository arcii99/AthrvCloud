//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: relaxed
#include <stdio.h>
#include <math.h>
#define G 6.67e-11

struct planet {
    char name[20];
    double mass;
    double radius;
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
    double acc_x;
    double acc_y;
} earth, mars, sun;

void update_position(struct planet *p, double dt) {
    p->pos_x += p->vel_x * dt;
    p->pos_y += p->vel_y * dt;
}

void update_velocity(struct planet *p, double dt) {
    p->vel_x += p->acc_x * dt;
    p->vel_y += p->acc_y * dt;
}

double distance(struct planet a, struct planet b) {
    double dx = b.pos_x - a.pos_x;
    double dy = b.pos_y - a.pos_y;
    return sqrt(dx*dx + dy*dy);
}

double force(struct planet a, struct planet b) {
    double dist = distance(a, b);
    return G * a.mass * b.mass / (dist * dist);
}

void update_acceleration(struct planet *p) {
    p->acc_x = 0.0;
    p->acc_y = 0.0;
    for (int i = 0; i < 2; i++) {
        struct planet other;
        if (i == 0)
            other = sun;
        else if (i == 1)
            other = mars;
        if (p->mass != other.mass) {
            double f = force(*p, other);
            double dx = other.pos_x - p->pos_x;
            double dy = other.pos_y - p->pos_y;
            p->acc_x += f * dx / distance(*p, other);
            p->acc_y += f * dy / distance(*p, other);
        }
    }
}

int main(void) {
    // initialize planets
    sprintf(earth.name, "Earth");
    earth.mass = 5.97e24;
    earth.radius = 6.37e6;
    earth.pos_x = 0.0;
    earth.pos_y = 0.0;
    earth.vel_x = 0.0;
    earth.vel_y = 29.783e3;

    sprintf(mars.name, "Mars");
    mars.mass = 6.39e23;
    mars.radius = 3.39e6;
    mars.pos_x = 2.28e11;
    mars.pos_y = 0.0;
    mars.vel_x = 0.0;
    mars.vel_y = 21.97e3;

    sprintf(sun.name, "Sun");
    sun.mass = 1.99e30;
    sun.radius = 6.96e8;
    sun.pos_x = -1.5e11;
    sun.pos_y = 0.0;
    sun.vel_x = 0.0;
    sun.vel_y = 0.0;

    // simulate planets
    double dt = 86400; // 1 day in seconds
    double t = 0.0;
    while (1) {
        // print planets position
        printf("Position of %s: (%e, %e)\n", earth.name, earth.pos_x, earth.pos_y);
        printf("Position of %s: (%e, %e)\n", mars.name, mars.pos_x, mars.pos_y);

        update_acceleration(&earth);
        update_acceleration(&mars);

        update_velocity(&earth, dt);
        update_velocity(&mars, dt);

        update_position(&earth, dt);
        update_position(&mars, dt);

        t += dt;
        if (t > 31536000) // simulate 1 year
            break;
    }
    return 0;
}