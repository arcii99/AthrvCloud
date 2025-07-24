//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: energetic
#include <stdio.h>
#include <math.h>

#define G 6.67e-11  // gravitational constant

struct Planet {
    double x, y;  // position
    double vx, vy;  // velocity
    double mass;  // mass
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

double gravity_force(double m1, double m2, double d) {
    return G * m1 * m2 / pow(d, 2);
}

void update_velocity(struct Planet *p, double fx, double fy, double dt) {
    p->vx += fx / p->mass * dt;
    p->vy += fy / p->mass * dt;
}

void update_position(struct Planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

int main() {
    struct Planet earth = {0, 0, 0, 0, 5.97e24};  // mass in kg
    struct Planet moon = {384400000, 0, 0, 1023, 7.34e22};  // position in m and mass in kg
    double dt = 60;  // time step in s
    double fx, fy, d;

    printf("Simulation start:\n");
    printf("Earth position: (%.2f, %.2f)\n", earth.x, earth.y);
    printf("Moon position: (%.2f, %.2f)\n", moon.x, moon.y);
    printf("Moon velocity: (%.2f, %.2f)\n", moon.vx, moon.vy);

    for (int i=1; i<=60*24*365*2; i++) {  // simulate for 2 years
        d = distance(earth.x, earth.y, moon.x, moon.y);
        fx = gravity_force(earth.mass, moon.mass, d) * (earth.x - moon.x) / d;
        fy = gravity_force(earth.mass, moon.mass, d) * (earth.y - moon.y) / d;

        update_velocity(&moon, fx, fy, dt);
        update_position(&moon, dt);

        printf("Day %d\n", i);
        printf("Moon position: (%.2f, %.2f)\n", moon.x, moon.y);
        printf("Moon velocity: (%.2f, %.2f)\n", moon.vx, moon.vy);
    }

    printf("Simulation end.\n");

    return 0;
}