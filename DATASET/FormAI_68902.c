//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11   // gravitational constant
#define DT 0.1          // time step

// definition of a planet
struct planet {
    double x, y;     // position
    double vx, vy;   // velocity
    double ax, ay;   // acceleration
    double mass;     // mass
};

// calculates the distance between two planets
double distance(struct planet p1, struct planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// calculates the force of attraction between two planets
double force(struct planet p1, struct planet p2) {
    double r = distance(p1, p2);
    return G * p1.mass * p2.mass / (r*r);
}

// calculates the acceleration of a planet due to the force of attraction
void acceleration(struct planet *p, struct planet p_other) {
    double f = force(*p, p_other);
    double theta = atan2(p_other.y - p->y, p_other.x - p->x);
    p->ax += f * cos(theta) / p->mass;
    p->ay += f * sin(theta) / p->mass;
}

// updates the position and velocity of a planet using the acceleration
void update(struct planet *p) {
    p->vx += p->ax * DT;
    p->vy += p->ay * DT;
    p->x += p->vx * DT;
    p->y += p->vy * DT;
    p->ax = 0;
    p->ay = 0;
}

int main() {
    // define the planets
    struct planet earth = {0, 0, 0, 0, 0, 5.972e24};
    struct planet moon = {384400000, 0, 0, 1022, 0, 7.342e22};

    // simulate the motion of the planets
    int i, t;
    for (t = 0; t < 3600; t++) {
        // calculate the acceleration of each planet
        acceleration(&earth, moon);
        acceleration(&moon, earth);

        // update the position and velocity of each planet
        update(&earth);
        update(&moon);

        // print the position and velocity of the moon
        if (t % 10 == 0) {
            printf("t = %d s: ", t);
            printf("moon: x = %.2f km, y = %.2f km, vx = %.2f m/s, vy = %.2f m/s\n",
                moon.x/1000, moon.y/1000, moon.vx, moon.vy);
        }
    }

    return 0;
}