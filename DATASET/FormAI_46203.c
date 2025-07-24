//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <math.h>

#define G 6.674e-11  // gravitational constant

typedef struct {
    double x, y;     // position
    double vx, vy;   // velocity
    double mass;     // mass
} Body;

// compute distance between two points
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

// compute gravitational force between two bodies
void force(Body *b1, Body *b2, double *fx, double *fy) {
    double d = distance(b1->x, b1->y, b2->x, b2->y);
    double f = G * b1->mass * b2->mass / (d*d);
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    *fx = f * dx / d;
    *fy = f * dy / d;
}

int main() {
    // initialization
    Body earth = {0.0, 0.0, 0.0, 29783.0, 5.972e24};
    Body moon = {-384400000.0, 0.0, 0.0, -1023.0, 7.3477e22};
    double fx1, fy1, fx2, fy2;

    // simulation loop
    for (double t = 0.0; t < 3600.0; t += 1.0) {
        force(&earth, &moon, &fx1, &fy1);
        force(&moon, &earth, &fx2, &fy2);
        earth.vx += fx1 / earth.mass * t;
        earth.vy += fy1 / earth.mass * t;
        moon.vx += fx2 / moon.mass * t;
        moon.vy += fy2 / moon.mass * t;
        earth.x += earth.vx * t;
        earth.y += earth.vy * t;
        moon.x += moon.vx * t;
        moon.y += moon.vy * t;
        printf("%f,%f,%f,%f\n", earth.x, earth.y, moon.x, moon.y);
    }

    return 0;
}