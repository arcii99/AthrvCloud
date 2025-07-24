//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11  // gravitational constant
#define MASS 5.97e24  // mass of the Earth
#define RADIUS 6.371e6  // radius of the Earth

typedef struct {
    double x, y;  // position
    double vx, vy;  // velocity
    double ax, ay;  // acceleration
    double mass;  // mass
} Body;

void update_position(Body *body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
}

void update_velocity(Body *body, double dt) {
    body->vx += body->ax * dt;
    body->vy += body->ay * dt;
}

void update_acceleration(Body *body1, Body *body2) {
    double dx = body2->x - body1->x;
    double dy = body2->y - body1->y;
    double distance = sqrt(dx * dx + dy * dy);
    double force = G * body1->mass * body2->mass / (distance * distance);
    body1->ax += force * dx / body1->mass;
    body1->ay += force * dy / body1->mass;
}

int main() {
    Body earth = {0, 0, 0, 0, 0, 0, MASS};
    Body object = {7000e3, 0, 0, 7800, 0, 0, 1000};

    double dt = 1;  // time step
    double t = 0;  // current time
    double duration = 86400 * 365;  // one year

    while (t < duration) {
        update_acceleration(&object, &earth);
        update_velocity(&object, dt);
        update_position(&object, dt);
        t += dt;
    }

    double altitude = sqrt(object.x * object.x + object.y * object.y) - RADIUS;
    printf("Altitude: %.0f km\n", altitude / 1000);

    return 0;
}