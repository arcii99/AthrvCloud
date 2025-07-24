//FormAI DATASET v1.0 Category: Physics simulation ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant
#define DT 0.01 // time step
#define MASS_SUN 1.989e30 // solar mass
#define MASS_EARTH 5.972e24 // earth mass
#define AU 1.496e11 // astronomical unit
#define YEAR 365.25 * 24 * 3600 // year in seconds

typedef struct {
    double x, y;
    double vx, vy;
    double mass;
} Body;

void update_velocity(Body *a, Body *b) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double d = sqrt(dx * dx + dy * dy);
    double F = G * a->mass * b->mass / (d * d);
    double fx = F * dx / d;
    double fy = F * dy / d;
    a->vx += fx / a->mass * DT;
    a->vy += fy / a->mass * DT;
    b->vx -= fx / b->mass * DT;
    b->vy -= fy / b->mass * DT;
}

void update_position(Body *a) {
    a->x += a->vx * DT;
    a->y += a->vy * DT;
}

int main() {
    Body sun = {0, 0, 0, 0, MASS_SUN};
    Body earth = {AU, 0, 0, 29.78e3, MASS_EARTH};
    double t = 0;
    while (t < YEAR) {
        update_velocity(&sun, &earth);
        update_position(&earth);
        t += DT;
    }
    printf("After %f years, Earth is at (%f, %f)", t / YEAR, earth.x, earth.y);
    return 0;
}